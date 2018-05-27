/* 考点
 * 对main函数的返回值和参数等认识
 *
 */
#include<stdio.h>
int main(int argc,char* argv[])
{
    printf("个数:%d\n",argc);
    for(int i = 0;i < argc;i++)
        printf("arg%d:%s\n",i,argv[i]);
    return 0;
}
