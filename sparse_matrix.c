#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct matrix{
    int row;
    int clo;
    struct matrix *right,*down;
    union{
        int data;
        struct matrix *next;
    }tag;
}node;
int main()
{
    int arr[5][]={{4,4,4},{0,2,11},{1,0,12},{2,1,-4},{3,3,-15}};

}
node * read_matrix(void)
{
    node *p,*q;
    node *head=(node*)malloc(sizeof(node));
    head->row=5;
    head->clo=3;
    head->down=NULL;
    head->right=NULL;
    head->next=NULL;
    q=head;
    for(int i=0;i<5;i++)//建立行
    {
        p=(node*)malloc(sizeof(node));
        p->row=i;
        p->clo=-1;
        p->next=NULL;
        q->next=p;
        q=p;
    }
    q->next=head->down;

    q=head;
    for(int i=0;i<3;i++)//建立列
    {
        p=(node *)malloc(sizeof(node));
        p->row=-1;
        p->clo=i;
        p->right=NULL;
        q->right=p;
        q=p;
    }
    q->right=head->right;

    for(int i=0;i<5;i++)
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]!=0)
            {
                p=(node *)malloc(sizeof(node));
                p->row=i;
                p->clo=j;
                p->tag.value=arr[i][j];
            }
            
        }
}