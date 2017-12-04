/*************************************************************************
	> File Name: kruskal.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 23时56分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
//kruskal算法，最小生成树使用数组，设置父节点是什么
typedef struct{
    int bef;
    int aft;
    int weight;
}node;
typedef struct find_set{
    struct find_set *bef;
    int data;
    struct find_set *next;
}NODE;
typedef struct set_head{
    NODE *head;
    NODE *tail;
    int flag;
}HEAD;
HEAD set[20];
node arr[20];
void sort(node arr[]);
void push(node *result);
int find(int bef,int aft);
int edge;
int s=0;
int vertex;

typedef struct set_t {
	int parent, data;
}set_t;
set_t Set[20];
int FindParent(int n);
void Union(int t1, int t2);
        
int main()
{
    printf("enter the number of vertex:"); 
    scanf(" %d",&vertex);

    printf("enter the edge:");
    scanf(" %d",&edge);

    printf("enter bef,aft,weight:");
    for(int i=0;i<edge;i++)
        scanf("%d%d%d",&arr[i].bef,&arr[i].aft,&arr[i].weight);

    sort(arr);
    node edge_set[20];

    for(int i=0;i<vertex;i++)//初始化点集合
    {
        Set[i].data = i + 1;
        Set[i].parent = i;
    }
    int j=0;
    for(int i=0;i<edge;i++)
    {
        if (FindParent(arr[i].bef) != FindParent(arr[i].aft)) 
        {
            edge_set[j++] = arr[i];
            Union(arr[i].bef - 1, arr[i].aft - 1);
        }
    }

    putchar('\n');
    for(int i=0;i<j;i++)
        printf("(%d,%d) ",edge_set[i].bef,edge_set[i].aft);
    putchar('\n');

    return 0;
}
void sort(node arr[])
{
    node temp;
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

int FindParent(int n) 
{
	if (Set[n].parent == n)
		return n;
	return FindParent(Set[n].parent);
}

void Union(int t1, int t2) 
{
	int root1 = FindParent(Set[t1].parent),
		root2 = FindParent(Set[t2].parent);

    if (root1 != root2) 
    {
		Set[root2].parent = root1;
	}
}

