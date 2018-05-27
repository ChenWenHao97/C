/*考点
 * 1、二级指针
 * 2、内存分配与释放,防止内存泄露
 * 3、值传递和地址传递
 *
 * 拓展
 * 如何检查内存泄露:valgrind ./a.out --leak--check=full
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct a{
    char *name;
    int num;
}A;

void func(A *a)
{
    a = (A*)malloc(sizeof(A));
    strcpy(a->name,"XiyouLinuxGroup");
    a->num = 2017;
}
int main()
{
    A *a;
    func(a);
    printf("%s %d",a->name,a->num);
    return 0;
}
// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// typedef struct a{
//     char *name;
//     int num;
// }A;
// void func(A **a)
// {
//     *a = (A*)malloc(sizeof(A));
//     (*a)->name = (char*)malloc(1000);
//     strcpy((*a)->name,"XiyouLinuxGroup");
//     (*a)->num = 2018;
// }

// int main()
// {
//     A *a;
//     
//     //func(&a);
//    
//     //printf("a:%s %d\n",a->name,a->num);
//     // free((a)->name);
//     // free(a);

//     return 0;
// }
