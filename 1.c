/*考点
1、数组在内存中是连续存在的
2、运算符优先级
3、a[b]的实质是*(a + b)
*/
#include<stdio.h>
int main()
{
    int nums[3][3] ={1,2,3,4,5,6,7,8,9};
    printf("%d\n",nums[1][-2]);
    printf("%d\n",(-1)[nums][5]);
   // printf("%d",*(*(-1+nums)+5));
    printf("%d\n",-1[nums][5]);
    // printf("%d",-1 * *(*(1+nums)+5));'
    return 0;
}
