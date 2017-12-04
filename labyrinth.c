#include<stdio.h>
#include<stdlib.h>
int maze[5][5];
int mark[5][5]={0};
typedef struct{
    int x;
    int y;
}offset;
offset direct[8] = {-1,0,  -1,-1,  0,-1,   1,-1,
                    1,0,   1,1,    0,1,    -1,1};


typedef struct{
    int x;
    int y;
    int direct;
}element;
element stack[26];
void add(int *top,element position);
element delete(int *top);
int main()
{
    int entry_x, entry_y;
    int exit_x, exit_y;
    printf("请输入入口:");
    scanf(" %d%d",&entry_x,&entry_y);
    stack[0].x = entry_x;
    stack[0].y = entry_y;
    stack[0].direct = 0;
    
    mark[entry_x][entry_y] = 1;//1表示走过

    printf("请输入出口:");
    scanf(" %d%d",&exit_x,&exit_y);
    printf("请输入地图\n");

    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 5;j++)
            scanf(" %d",&maze[i][j]);

    int i,next_x,next_y,find = 0,x,y,dir;
    element position; 
    int top = 0;
    while(top > -1 && !find)
    {
       // printf("%d",top);
        position = delete(&top);
        //printf("55 %d %d \n",position.x,position.y);
        x = position.x;
        y = position.y;
        dir = position.direct;//储存下一个位置的direct
        while(dir < 8 && !find)
        {
            next_x = x + direct[dir].x;
            next_y = y + direct[dir].y;
            if(next_x < 0 || next_x > 4 || next_y < 0 || next_y > 4)
            {
                ++dir;
                continue;
            }
            //printf("63 top is %d,dir is %d\n",top,dir);

            if(next_x == exit_x && next_y == exit_y)
            {
                mark[x][y] = 1;
                position.x = x;
                position.y = y;
                add(&top,position);
                find = 1;
            }
            else if(!maze[next_x][next_y] && !mark[next_x][next_y])
            {
                mark[x][y] = 1;
                position.x = x;
                position.y = y;
                position.direct = dir + 1;  //防止多次进入一个不可以继续的点
                //printf("71 %d %d \n",position.x,position.y);
                add(&top,position);
                x = next_x;
                y = next_y;
                dir= 0 ;//重新遍历8个方向
            }
            else
            {
                ++dir;
            }
        }
        
    }

    if(find)
    {
        printf("top is %d\n",top);
        printf("The path is:\n");
        printf("row  col\n");
        for(int i = 0;i <= top;i++)
            printf("%d  %d\n",stack[i].x,stack[i].y);
        printf("%d  %d\n",exit_x,exit_y);
    }
    else 
        printf("The maze does not have a path\n");


}

element delete(int *top)
{
    if(*top == -1)
    {
        printf("delete error\n");
        exit(1);
    }
    return stack[(*top)--];
}

void add(int *top, element position)
{
    if(*top > 25)
    {
        printf("full\n");
        exit(1);
    }
    stack[++(*top)] = position;
}
