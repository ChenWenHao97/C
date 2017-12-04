/*************************************************************************
	> File Name: singleshort.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 18时03分38秒
 ************************************************************************/
//单源最短路径
#include<stdio.h>
#define MAX 6
int cost[][MAX] = 
{
    {   0,  50,  10,1000,  45,1000},
    {1000,   0,  15,1000,  10,1000},
    {  20,1000,   0,  15,1000,1000},
    {1000,  20,1000,   0,  35,1000},
    {1000,1000,  30,1000,   0,1000},
    {1000,1000,1000,   3,1000,   0}
};
int n = MAX;
int found[50] = {0};
int distance[50] = {0};
void shortestpath(int v,int cost[][MAX],int distance[],int n,int found[]);
int choose(int distance[],int n,int found[]);
int main()
{
    int v;
    printf("请输入起点:");
    scanf("%d",&v);
    shortestpath(v,cost,distance,n,found);
    for(int i=0;i<n;i++)//最终结果
    {
        printf("%d ",distance[i]);
    }
    putchar('\n');

    return 0;

}
void shortestpath(int v,int cost[][MAX],int distance[],int n,int found[])
{
    int u,w;
    for(int i = 0;i < n;i++)//初始化起点到所有点的距离
    {
        found[i] = 0;
        distance[i] = cost[v][i];
    }
    found[v] = 1;
    distance[v] = 0;
    for(int i = 0;i < n-2;i++)//因为每次distance是加两个，所以只能弄到倒数第二个
    {
        u = choose(distance,n,found);//找最小距离点，之后u变成一个中间点
        if(u == -1)
            continue;
        found[u] = 1;//加入集合中了
        for(w = 0;w < n;w++)
        {
            if(!found[w])
            {
                if(distance[u]+cost[u][w]< distance[w])//如果转折点加cost小，就改值
                {
                    distance[w] = distance[u]+cost[u][w];
                }
            }
        }
    }
}
int choose(int distance[],int n,int found[])
{
    int min = 9999;
    int minpos = -1;
    for(int i=0;i < n;i++)
    {
        if(distance[i] < min && !found[i])
        {
            min = distance[i];
            minpos = i;
        }
    }
    printf("minpos:%d\n",minpos);
    return minpos;
}
