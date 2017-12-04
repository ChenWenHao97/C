#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct link{
    int data;
    struct link *next;
}node;
void  invert(node *head);
void head_invert(node *head);
int main()
{
    node *p,*q;
    node * head=NULL;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        p=(node *)malloc(sizeof(node));
        scanf("%d",&(p->data));
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            q->next=p;
        q=p;
    }
    p=head;
    while(p)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
    putchar('\n');
    //invert(head);
    head_invert(head);

    return 0;
    
}

void invert(node * head)//就地逆置
{
    node *tail,*middle;
    middle=NULL;
    while(head)
    {
        tail=middle;
        middle=head;
        head=head->next;
        middle->next=tail;//方向改变
    }
    //middle作为新的头结点
    while(middle)
    {
        printf("%d ",middle->data);
        middle=middle->next;
    }

}

void head_invert(node * head)//带头节点头插
{
    node *p,*q;
    p=head->next;
    head->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        q->next=head->next;
        head->next=q;//新的节点都放在头结点后面
    }
    while(head)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}