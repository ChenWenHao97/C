/*************************************************************************
	> File Name: perm.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月06日 星期三 18时47分38秒
 ************************************************************************/

#include<stdio.h>
void perm(char *list,int i,int n);
void SWAP(char *a,char *b);

int main()
{
    char a[5]={'a','b','c','\0'};
    perm(a,0,2);
}
void perm(char *list,int i,int n)
{
    int j;
    if(i==n)
    {
        for(j=0;j<=n;j++)
            printf("%c",list[j]);
        printf("\n");
    }
    else 
    {
        for(j=i;j<=n;j++)
        {
            SWAP(&list[i],&list[j]);
            perm(list,i+1,n);
            SWAP(&list[i],&list[j]);
        }
    }
}

void SWAP(char *a,char *b)
{
    char c;
    c=*a;
    *a=*b;
    *b=c;
}
