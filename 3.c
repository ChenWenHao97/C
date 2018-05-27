/*考点
 * static用法
 * 函数内static变量的初始化语句只执行一次
 * 相当于全局变量
 */
#include<stdio.h>
static int a = 2018;//只能初始化一次，是全局变量，加static是为了仅有本文件可以用
int b = 2019;
//a = 2019;
static void f(void)
{
    static int b;
    //作用域限制
    printf("a = %d,b = %d\n",a++,++b);
}
int main()
{
    f();
    f();
    f();
   // printf("%d",b);
    return 0;
}
