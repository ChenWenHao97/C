#include<stdio.h>
#include<string.h>
int c[11]={0};
void count_sort(int *a,int *b,int len);
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int count = sizeof(arr) /sizeof(int);
    printf("count %d\n",count);
    int b[count];
    count_sort(arr,b,count);
    for(int i=0;i<count;i++)
        printf("%d ",arr[i]);

    return 0;
}
void 
count_sort(int *a,int *b,int len)
{
    for(int j=0;j<len;j++)
        c[a[j]] = c[a[j]] + 1;
    
    for(int i=1;i<len;i++)
        c[i] = c[i] + c[i-1];
    
    for(int j=len-1;j>=0;j--)
    {
        b[ c[ a[j] ] ]= a[j];
        c[j] = c[j] -1;
    }

}