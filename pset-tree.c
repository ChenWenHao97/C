/*************************************************************************
	> File Name: pset-tree.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月07日 星期四 09时11分22秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>

typedef struct vertex {
    char data;
    int left, right;
} vertex;

int main()
{
    char str[]="abcd";
    vertex set[3000];
    set[1].data='^';
    set[1].left=2;
    set[1].right=3;

    for(int i=0;i<=4;i++)
    {
        for(int j=pow(2,i);j<=pow(2,i+1)-1;j++)
        {
            set[j].left=2*j;
            set[j].right=2*j+1;
            set[2 * j].data='^';
            set[2 * j + 1].data=str[i];
        }
    }

}

