#include<stdio.h>
#include<string.h>
void get_nextval(char *T,int *nextval)
{
    int i,j;
    i=1;
    j=0;
    nextval[0]=0;
    while(i<strlen(T))
    {
        if(j==0|| T[i]==T[j])
        {
            
            if(T[i]!=T[j])//和未改进算法一样
                nextval[i]=j;
            else 
                nextval[i]=nextval[j];//改进就是把之前出现过的都表示一个地方
            ++i;
            ++j;
        }
        else 
            j=nextval[j];
    }
}

int Index_KMP(char *S,char *T,int pos)
{
    int i=pos;//可以实现任意开始位置匹配

    int j=0;
    int len1=strlen(S);
    int len2=strlen(T);
    int next[255]={0};
    
    get_nextval(T,next);
    while(i<len1&&j<len2)
    {
        if(j==0||S[i]==T[j])
        {
            ++i;
            ++j;
        }
        else 
            j=next[j];
    }
    if(j>=len2)
        return i-len2;
    else 
        return -1;

}
int main()
{
   char a[10000];
   char b[10000];
   scanf("%s",a);
   scanf("%s",b);
    printf("%d\n",Index_KMP(b,a,0));//从头开始匹配

    return 0;
}