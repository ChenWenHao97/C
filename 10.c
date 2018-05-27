/*考点
 * 宏定义
 * 1、#x和##x的区别
 * 2、mutiply函数的注意事项
 *
 * 拓展
 * 宏定义swap函数
 */
#include<stdio.h>
#define YEAR 2018
#define LEVELONE(x) "XiyouLinux "#x"\n"
#define LEVELTWO(x) LEVELONE(x)
#define LEVELTHREE(x) str##x
#define MULTIPLY(x,y) x*y
//#define SWAP(x,y) { int t = x;x = y;y = t; }

int main()
{
    char * strA = "2018 XiyouLinux";
    int x = MULTIPLY(1+2,3);
    printf("%d\n",x);
    printf(LEVELONE(YEAR));
    printf(LEVELTWO(YEAR));
    printf(LEVELTHREE(A));
    int a = 3,b = 4;
  //  SWAP(a,b);
   // printf("\na:%d b:%d\n",a,b);

    return 0;
}
