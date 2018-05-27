/*考点
*对数据类型的认识
* 
 */
#include<stdio.h>
int main()
{
    char n[] = {1,0,0,0};
    printf("%d\n",*(int *)n);

    return 0;
}




/*
 * char n[] = 00000000 00000000 00000000 00000001
大端模式优点：符号位在所表示的数据的内存的第一个字节中，便于快速判断数据的正负和大小

小端模式优点：1. 内存的低地址处存放低字节，所以在强制转换数据时不需要调整字节的内容（注解：比如把int的4字节强制转换成short的2字节时，就直接把int数据存储的前两个字节给short就行，因为其前两个字节刚好就是最低的两个字节，符合转换逻辑）； 2. CPU做数值运算时从内存中依顺序依次从低位到高位取数据进行运算，直到最后刷新最高位的符号位，这样的运算方式会更高效
void byteorder()
{
    union{
        short value;
        char union_bytes[sizeof(short)];
    }test;
    test.value = 0x0102;//二进制为100000010
    /*当小端取低字节8位二进制00000010转换就是2，再取一位就是1
        同理大端就是1,2
    */
    if((test.union_bytes[0]==1)&&test.union_bytes[1]==2)
        cout <<"big endian"<<endl;
    else if((test.union_bytes[0]==2)&&(test.union_bytes[1])==1)
        cout <<"little endian"<<endl;
    else 
        cout <<"unkonwn"<<endl;

}


 *
 */
