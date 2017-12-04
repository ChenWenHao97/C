/*************************************************************************
	> File Name: kmp.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月08日 星期五 11时12分41秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define max_string_size 100
#define max_pattern_size 100
int failure[max_pattern_size];
char string[max_string_size];
char pat[max_pattern_size];
int pmatch(char *string,char *pat);
void fail(char *pat);
int main()
{
    fail("abcabcacab");
    int n=pmatch("abababcd","abcd");
    printf("%d\n",n);

    return 0;

}
int pmatch(char *string,char *pat)
{
    int i=0,j=0;
    int lens=strlen(string);
    int lenp=strlen(pat);
    while(i < lens && j < lenp)
    {
        if(string[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==0)
            i++;
        else 
            j=failure[j-1]+1;
    }
    return ((j==lenp) ? (i-lenp):-1);
}
void fail(char *pat)
{
    int n=strlen(pat);
    failure[0]=-1;
    int i,j;
    for( j=1;j<n;j++)
    {
        i=failure[j-1];
        while((pat[j]!=pat[i+1]) && (i >= 0))
            i = failure[i];
        if(pat[j] == pat[i+1])
            failure[j] = i+1;
        else 
            failure[j] = -1;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",failure[i]);
    }
}
