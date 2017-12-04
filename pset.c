/*************************************************************************
	> File Name: pset.c
	> Author: 
	> Mail: 
	> Created Time: 2017年09月06日 星期三 23时05分11秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100 /*集合的最大元素个数*/
 
  void PowerSet(char*, int, char*);
   
   int main()
   {
           char a[MAX_LENGTH];        /*存储输入的集合*/
           char set[MAX_LENGTH]={""};    /*储存集合的幂集元素*/
        
           printf("Input the elements:");
           scanf("%s",a);
        
           printf("----------------------------\n");
           PowerSet(a,0,set); /*调用递归函数*/
           printf("----------------------------\n");
           return 1;

   }
    
    /*
     * 参数说明：             char* a :    待求幂集的集合
     * int i :    当前分析到集合的第i个元素
     * char* set :    存储当前幂集元素状态
     * int* Num :    幂集元素记数
     * */
void PowerSet(char* a, int i, char* set)
{
    char TempSet[MAX_LENGTH];
          
    strcpy(TempSet,set);
    if(i>=strlen(a))
    {
        printf("{%s}\n",set);           
    }
    else
    {
        PowerSet(a,i+1,TempSet);//每次需要set完整的版本
        strncat(TempSet,(a+i),1);//tempset成为新的set
        PowerSet(a,i+1,TempSet);         
    }
}
