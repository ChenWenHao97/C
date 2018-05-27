/*考点
 * 1、不同类型的数组，步长不同
 * 2、数组指针，指针数组
 */
#include<stdio.h>
int main()
{
    int a[5] = {1,2,3,4,5};
    printf("%p\n",a);//int *
    printf("%p\n",a+1);//int *
    printf("%p\n",&a);//int[5] *
    printf("%p\n",&a+1);//int[5] *
    
    
    int (*pa)[1];
    pa = (int (*)[1])&a;
    // pa = &a;
    for(int i = 0;i < 5;i++)
      // printf("%d ",(*pa)[i]);
        printf("%d ",*(pa+i)[0]);
    char * str[] ={"hello","linux","group"};

    return 0;
}
