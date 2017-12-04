#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define IS_OKPOS(pos) ((pos) >= 0 && (pos) <= 100000 && !vis[(pos)])

typedef struct status_t {
    int pos;
    int moved;
} status;

typedef struct node_t {
    struct status_t dat;
    struct node_t *next;
} node, *link;

link head, tail, cur;
int vis[100001];

int bfs(int start, int end)
{
    memset(vis, 0, sizeof(vis));
    head = (link)malloc(sizeof(node));
    head->dat.pos = start;
    head->dat.moved = 0;
    head->next = NULL;
    cur = tail = head;
    vis[start] = 1;
    
    while (cur != NULL)
    {
        link this = cur;

        if (this->dat.pos == end)
        {
            return this->dat.moved;
        }

        if (IS_OKPOS(this->dat.pos * 2)) {
            link flash = (link)malloc(sizeof(node));
            flash->dat.pos = 2 * this->dat.pos;
            flash->dat.moved = this->dat.moved + 1;
            flash->next = NULL;
            tail->next = flash;
            tail = tail->next;
            vis[flash->dat.pos] = 1;
        }

        if (IS_OKPOS(this->dat.pos - 1)) {
            link nxt = (link)malloc(sizeof(node));
            nxt->dat.pos = this->dat.pos - 1;
            nxt->dat.moved = this->dat.moved + 1;
            nxt->next = NULL;
            tail->next = nxt;
            tail = tail->next;
            vis[nxt->dat.pos] = 1;
        }

        if (IS_OKPOS(this->dat.pos + 1)) {
            link move = (link)malloc(sizeof(node));
            move->dat.pos = this->dat.pos + 1;
            move->dat.moved = this->dat.moved + 1;
            move->next = NULL;
            tail->next = move;  
            tail = tail->next;
            vis[move->dat.pos] = 1;
        }

        cur = cur->next;
        free(this);
    }
    
}

int main()
{
    int start, end;    
    while (scanf("%d %d", &start, &end) != EOF) {
        printf("%d\n", bfs(start, end));
    }

    return 0;
}