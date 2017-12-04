#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITY 1000
struct{
    int adjvex;
    int lowcost;
}closedge[31]; 
typedef struct {
    int vexnum;
    int arcs[11][11];
}AdjMatrix;
AdjMatrix *G;
void prim(AdjMatrix *G,int start);
int main()
{
    printf("请输入矩阵：");
    G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
                scanf(" %d",&(G->arcs[i][j]));

    G->vexnum = 10;
    int start = 10;
    prim(G,start);
    for(int i=1;i<=10;i++)
        printf("%d->%d\n",i,closedge[i].adjvex);
}
void prim(AdjMatrix *G,int start)
{
    int i,e,k,m=0,min=0;
    closedge[start].lowcost=0;

    for(int i=1;i<=G->vexnum;i++)
    {
        if(i!=start)
        {
            closedge[i].adjvex=start;
            closedge[i].lowcost=G->arcs[start][i];
        }
    }
    for(int i=1;i<=G->vexnum-1;i++)
    {
        min=INFINITY;
        for(int j=1;j<=G->vexnum;j++)
        {
            if(closedge[j].lowcost!=0&&closedge[j].lowcost<min)
            {
                m=j;
                min=closedge[j].lowcost;
            }
        }
        fprintf(stderr, "m=%d\n", m);
        closedge[m].lowcost=0;
        for(int k=1;k<=G->vexnum;k++)
        {
            if(k!=m&&G->arcs[m][k]<closedge[k].lowcost)//点的任意一个最短
            {
                closedge[k].lowcost = G->arcs[m][k];
                closedge[k].adjvex = m;
            }
        }
    }

}
