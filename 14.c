/*考点
 * 1、正确判断数字
 * 2、负数问题
 * 3、不是数组处理
 * 3、gcc 有math头文件的时候，链接的时候加-lm
 * 
 * 
 * 使用math.h中声明的库函数还有一点特殊之处，gcc命令行必须加-lm选项，
 * 因为数学函数位于libm.so库文件中（这些库文件位于/lib目录下），
 * -lm选项告诉编译器，我们程序中用到的数学函数要到这个库文件里找。
 */
#include<stdio.h>
#include<string.h>
#include<math.h>

int Convert(const char *str)
{
    int num = 0;
    double figure = 0;
    int flag = 0;
    if(str[0]=='-')
     {
         flag = 1;
         figure--;
     }
    for(int i = strlen(str)-1;i >=0;i--)
    {
        if(str[i]<='9'&&str[i]>='0')
            num += (str[i]-'0')*pow(10.0,figure);
        else 
            num += 0;
        figure++;
    }
    if(flag==1)
        return -num;
    else 
        return num;
}

int main()
{
    char str[1000];
    printf("请输入字符串:");
    scanf("%s",str);
    
    printf("%d\n", Convert(str));
}
