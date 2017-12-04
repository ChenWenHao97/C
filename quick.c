/*
　　在很久很久以前，有一位大师级程序员，实力高强，深不可测，代码能力无人能及。从来没有人听说过他的真名，只知道他在完成一段代码后，总会跟上一行注释“十四出品，必属精品”，于是他在编程江湖上便有了绰号“十四”。

　　然而，十四大师并不满足于现有的一切，他想要让自己的实力有更进一步的提升。为此，他专程前往二次元世界修行。

　　二次元旅程归来的十四大师学习了新的技能——闪现。

　　在一条既定的直线道路上，“闪现”技能允许十四大师超时空移动。如果把道路视为一条数轴，使用闪现可以让十四大师瞬间移动到脚下坐标两倍的位置上。例如，如果十四大师站在坐标5的位置上，他可以直接闪现到坐标10的位置，如果继续闪现，则可以到达坐标20的位置上。

　　现在十四大师打算练习一下“闪现”在生活中的应用。我们假定他站在坐标为a的位置上，而他想要到达坐标为b的位置（0 ≤a,b≤100000）。除了使用闪现外，他也可以像常人一样徒步向前或者向后走，而使用闪现视为行走了一步。请问十四大师最少需要走多少步才可以到达目标？

Input
　　输入包含多组数据。每组数据占一行，包含两个整数a和b，表示十四大师的起始坐标和目的地坐标。（0 ≤a,b≤100000）

Output
　　对于每组输入，输出一个整数，即十四大师到达目的地的最少步数。

Sample Input
5 17

Sample Output
4
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int book[100001];

typedef struct link{
    int pos;
    int move;
    struct link * next;
}node;

node *head,*cur;

int bfs(int a,int b);
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d\n",bfs(a,b));
    }
}

int bfs(int a,int b)
{
    memset(book,0,sizeof(book));
    head=(node *)malloc(sizeof(node));
    head->pos=a;
    head->move=0;
    head->next=NULL;
    cur=head;
    book[a]=1;

    while(head!=NULL)
    {
        if(head->pos==b)
        {
            return head->move;
        }
        if((head->pos)*2>=0 && (head->pos)*2<=100000&&book[(head->pos)*2]==0)
        {
            node *nt=(node *)malloc(sizeof(node));
            nt->pos=(head->pos)*2;
            nt->move=head->move+1;
            nt->next=NULL;
            book[nt->pos]=1;
            cur->next=nt;
            cur=cur->next;
        }
        if(head->pos-1>=0&&head->pos-1<=100000&&book[head->pos-1]==0)
        {
            node *nt=(node *)malloc(sizeof(node));
            nt->pos=head->pos-1;
            nt->move=head->move+1;
            nt->next=NULL;
            book[nt->pos]=1;
            cur->next=nt;
            cur=cur->next;
        }
        if(head->pos+1>=0&&(head->pos+1)<=100000&&book[head->pos+1]==0)
        {
            node *nt=(node *)malloc(sizeof(node));
            nt->pos=head->pos+1;
            nt->move=head->move+1;
            nt->next=NULL;
            book[nt->pos]=1;
            cur->next=nt;
            cur=cur->next;
        }
        head=head->next;//有可能三种情况都满足，所以ｃｕｒ会加很多情况，不会漏解
    }
}