/*考点
 * 1、字符串解析按照贪心来读取，读取最大值,遇到'\0'之后尝试匹配更多，
 *    匹配到'\010'才停止
 * 2、转义字符
 * 3、sizeof内表达式不会运行
 * 
 * */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int a[3][2] = {2,0,1,8};
    char *str = (char*)malloc(sizeof(char)*20);
    strcpy(str,"\0101\\xb2");
    char str2[6]="abcdef";//没有结束符号

    printf("%zu %zu %d\n",sizeof(a),sizeof(a[1][1]=0),a[1][1]);
    //printf("%zu %zu %d\n",sizeof(a),a[1][1],sizeof(a[1][1]));
    //printf("str:%s\n",str);
    //printf("str2:%s\n",str2);
    printf("%zu %zu\n",sizeof(str),strlen(str));
    //str是一个指针类型

    return 0;
}
