/*
给定一个正整数n，请编写一个程序来寻找n的一个非零的倍数m，这个m应当在十进制表示时每一位上只包含0或者1。你可以假定n不大于200且m不多于100位。 
提示：本题采用Special Judge，你无需输出所有符合条件的m，你只需要输出任一符合条件的m即可。
Input
输入包含多组数据，每组数据仅一行，只包含一个正整数n (1 <= n <= 200).
Output
对于输入的每组n，都输出任一符合条件的m。即使有多个符合条件的m，你也只需要输出一个即可。
Sample Input
2
6
19
0
Sample Output
10
100100100100100100
111111111111111111
答案不唯一
*/
#include<stdio.h>
typedef long long ll;
void dfs(ll a,int b,int depth);
ll res;
int flag=0;
int main()
{
    ll a;
    while(scanf("%lld",&a)&&a!=0)
    {
        flag=0;
        dfs(1,a,1);
        printf("%lld\n",res);
    }
}
void dfs(ll a,int b,int depth)
{
    if(a % b==0)
        {
            flag=1;
            res=a;
            return ;
        }
    if(depth>=19 || flag)
        return;
    dfs(a*10,b,depth+1);
    dfs(a*10+1,b,depth+1);
}