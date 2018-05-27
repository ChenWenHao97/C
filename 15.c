/*考点
 * 1、如何利用一个数组就可以完成转换
 * 2、学会使用qsort函数
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* int cmp(const void *pa, const void *pb)
// {
//     int a = (*(int *)pa) % 2, b = (*(int *)pb) % 2;
//     if (a == b) return 0;
//     if (a == 1) return -1;
//     return 1;
 }*/

/* int main(int argc, char *argv[])
// {
//     int a[] = { 1, 2, 3, 4, 5, 6 };

//     qsort(a, 6, sizeof(int), cmp);

//     for (int i = 0; i < 6; i++) 
//         printf("%d ", a[i]);
}*/


/* int main(int argc, char *argv[])
// {
//     const int n = 6;
//     int num[] = { 1, 2, 3, 4, 5, 6 };d

//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < i; j++) {
//             int a = num[i] % 2, b = num[j] % 2;
//             if (a == 1 && a != b) {
//                 int t = num[i];
//                 num[i] = num[j];
//                 num[j] = t;
//             }
//         }
//     }

//     for (int i = 0; i < 6; i++) 
//         printf("%d ", num[i]);
 }*/


int main()
{
    int a[] = {1,2,3,4,5,6};
    int j = sizeof(a)/sizeof(int)-1;
    int i = 0;
    while(i<(sizeof(a)/sizeof(int))/2-1)//从两边开始交换
    {
        if(a[i]%2==0&&a[j]%2!=0)
        {
            int temp;
            temp = a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
        if(a[i]%2!=0)
            i++;
        if(a[j]%2==0)
            j--;
    }
    for(int i = 0;i < sizeof(a)/sizeof(int);i++)
        printf("%d ",a[i]);
}
