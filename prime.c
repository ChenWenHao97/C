/*************************************************************************
	> File Name: prime.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月22日 星期三 17时49分30秒
 ************************************************************************/
/*
 * 用prim算法弄最小生成树，每次一个点都会遍历所有点，找出，两点距离最短的情况
 * 再改变节点的入度和最小值
 */
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

    for(int i=1;i<=G->vexnum;i++)//最开始是初始化
    {
        if(i!=start)
        {
            closedge[i].adjvex=start;
            closedge[i].lowcost=G->arcs[start][i];
        }
    }
    for(int i=1;i<=G->vexnum-1;i++)//大循环
    {
        min=INFINITY;
        for(int j=1;j<=G->vexnum;j++)//首先找到制定开始点到全部顶点最小的值
        {
            if(closedge[j].lowcost!=0&&closedge[j].lowcost<min)
            {
                m=j;
                min=closedge[j].lowcost;
            }
        }

        closedge[m].lowcost=0;//标志放入集合中
        for(int k=1;k<=G->vexnum;k++)//之后用找到最小边的顶点为开始，找出它到所有点最小权值
        {
            if(k!=m&&G->arcs[m][k]<closedge[k].lowcost)//点的任意一个最短
            {
                closedge[k].lowcost = G->arcs[m][k];
                closedge[k].adjvex = m;
            }
        }
    }

}
