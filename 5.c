/*考点
 * const在不同位置的意义
 *
 */
#include<stdio.h>
int main()
{
    char y[] = "xiyoulinuxgroup",x[]="2018";
    char *const p1 = y;
    const char *p2 = y;
    //const char * const p3 = y;
    p1 = x;
    p2 = x;
    //p3 = x;
    *p1 = 'x';
    *p2='x';
    //*p3 = 'x';
}
