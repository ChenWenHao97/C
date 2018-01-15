#include<stdio.h>
#include<stdlib.h>
/*
    kruskal,最小生成树，利用链表，并查集的知识
*/
typedef struct{
    int bef;
    int aft;
    int weight;
}pic_node;//图中点的结构体

typedef struct find_set{
    int data;
    struct find_set *next;
}NODE;//点集合的节点

typedef struct set_head{
    NODE *head;
    NODE *tail;
    int flag;
}HEAD;//点集合的头

HEAD set[20];//点集合
pic_node arr[20];//开始时候数据

int edge;//边数
int s=0;
int vertex;//顶点数
void add_set(int a,int b);
void sort(pic_node arr[]);
int find(int who);
int main()
{
    printf("enter the number of vertex:");//输入顶点个数 
    scanf(" %d",&vertex);

    printf("enter the number of edges:");//输入边个数
    scanf(" %d",&edge);

    printf("enter bef,aft,weight:");//输入两点和权值
    for(int i=0;i<edge;i++)
        scanf("%d%d%d",&arr[i].bef,&arr[i].aft,&arr[i].weight);

    sort(arr);//进行排序，求出最小
    pic_node edge_set[20];//边集合

    for(int i=0;i<vertex;i++)//初始化点集合，每个集合首先包含自己
    {
        //实际利用并查集
        set[i].head = (NODE *)malloc(sizeof(NODE));
        set[i].flag = 1;//如果一个集合被并入另一个集合，此集合赋值0，表示不存在了
        (set[i].head)->data = i + 1;
        set[i].tail = set[i].head;
        (set[i].tail)->next = NULL;
    }

    int j=0;
    for(int i=0;i<edge;i++)
    {
        if(find(arr[i].bef) != find(arr[i].aft))//如果两个顶点不在一个集合
        {
            edge_set[j++]=arr[i];//加入边的集合
            add_set(arr[i].bef,arr[i].aft);//将两个集合放在一起，防止形成环路
        }
        if(j>vertex-1)
            break;
    }

    for(int i=0;i<vertex;i++)//输出点的集合
    {
        if(set[i].flag)
        {
            for(NODE *f=set[i].head;f!=NULL;f=f->next)
                printf("%d ",f->data);
            putchar('\n');
        }
    }
    for(int i=0;i<j;i++)//输出边的集合
        printf("(%d,%d) ",edge_set[i].bef,edge_set[i].aft);
    putchar('\n');

    return 0;
}
void sort(pic_node arr[])
{
    pic_node temp;
    for(int i=0;i<edge;i++)
        for(int j=0;j<edge-i-1;j++)
        {
            if(arr[j].weight > arr[j+1].weight)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = arr[i];
            }
        }
}

int find(int who)
{
    for (int i = 0; i < vertex; i++)
    {
        if (set[i].flag != 0)
        {
            for (NODE *p = set[i].head; p != NULL; p = p->next)
            {
                if (p->data == who)
                {
                    return i;
                }
            }
        }
    }
    return -1;
}

void add_set(int a,int b)
{
    int alist = find(a),
        blist = find(b);
    
    set[blist].flag = 0;
    (set[alist].tail)->next = set[blist].head;
    //将第一个集合的尾部，变成第二个集合的头部
    set[alist].tail = set[blist].tail;//将两个集合的尾部同步
}
