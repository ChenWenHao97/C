/*************************************************************************
	> File Name: allshort.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月04日 星期一 21时09分43秒
 ************************************************************************/

#include<stdio.h>
//所有顶点对应的最短路径
#define MAX 6
int n = MAX;
int cost[][MAX] = 
{
    {   0,  50,  10,1000,  45,1000},
    {1000,   0,  15,1000,  10,1000},
    {  20,1000,   0,  15,1000,1000},
    {1000,  20,1000,   0,  35,1000},
    {1000,1000,  30,1000,   0,1000},
    {1000,1000,1000,   3,1000,   0}
};
int distance[MAX][MAX]={0};
void allcosts(int cost[][MAX],int distance[][MAX],int n);
int main()
{
    allcosts(cost,distance,n);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%d ",distance[i][j]);
        }
        putchar('\n');
    }
}
void allcosts(int cost[][MAX],int distance[][MAX],int n)
{
   for(int i = 0;i < n;i++) 
        for(int j = 0;j < n;j++)
            distance[i][j] = cost[i][j];
    for(int k = 0;k < n;k++)//k相当于一个中间点，i到k最短加上k到j最短，就是i到j最短
        for(int i = 0;i < n ;i++)
            for(int j = 0;j < n;j++)
            {
                if(distance[i][k]+distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
}

