/*考点
 * 1、作用域问题
 * 2、对无符号整形的认识
* */
#include<stdio.h>
int f(unsigned int num)
{
    for(unsigned i = 0;num;i++)
        num &= num - 1;
    printf("%d\n",num);
    return i;
}
int main()
{
    int x=f(2018);
    printf("%d\n",x);

    return 0;
}
//2018:00000000 00000000 00000111 11100010
