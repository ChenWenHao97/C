#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void MAX_HEADPIFY(int *arr,int i,int len);//建立最大堆
void swap(int *str1,int *arr2);//交换函数
void BULD_MAX_HEAP(int  *arr,int len);//建立堆
void HEADPSORT(int  *arr,int len);//排序
int main()
{
    int len;
    int  arr[]={12,11,13,10,9,8,7,6,5,4,3,2,1};
    HEADPSORT(arr-1,13);//排序的时候是按从索引1开始，这样可以很好的排序
    for(int i=0;i<13;i++)
        printf("%d ",arr[i]);
}
void swap(int *arr1,int *arr2)
{
    int  t;

    t=*arr1;
    *arr1=*arr2;
    *arr2=t;
}
void MAX_HEADPIFY(int *arr,int i,int len)//保证最大堆的性质
{
    int max=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=len&&arr[left]>arr[max])//第二个不能使用str[i]，因为左孩子可能比节点大
        max=left;                   //如果还是使用str[i]会让数据错误，切记！！！
    if(right<=len&&arr[right]>arr[max])
        max=right;
    if(max!=i)
    {
        swap(&arr[max],&arr[i]);
        MAX_HEADPIFY(arr,max,len);
    }
}

void BULD_MAX_HEAP(int  *arr,int len)//自底而上建堆
{
    int i;

    for(i=len/2;i>=1;i--)//i的len/2是树叶的个数
        MAX_HEADPIFY(arr,i,len);
}
void HEADPSORT(int *arr,int len)
{
    int i;

    
    BULD_MAX_HEAP(arr,len);//先建立堆
    for(i=len;i>=1;i--)
    {
        swap(&arr[1],&arr[i]);//取出最大值,保证之前str[1]永远是最大的
        len=len-1;
        MAX_HEADPIFY(arr,1,len);
    }
}