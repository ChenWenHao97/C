/*考点
 * 字节对齐
 *
 */
#include<stdio.h>
#include<string.h>
//#pragma pack(4) //按什么方式对齐
struct icd{
    int a;
    char b;
    double c;
};
struct cdi{
    char a;
    double b;
    int c;
};
/*struct A{
    //int a;
    char b;
    short c;
};
struct B{
    char b;
    //int a;
    short c;
};*/
int main()
{
    printf("%d %d\n",sizeof(struct icd),sizeof(struct cdi));
    //printf("A:%d B:%d",sizeof(struct A),sizeof(struct B));
}
/*
因为我们的计算机硬件就是这么设计的，也就是说CPU在访问存储器的时候只能在某些地址处获取某些特定类型的数据。另一方面，因为CPU读取数据的时候不是一个一个读的，几个几个读的。如果数据不按照一定的规则存储的话，会降低读取速度，从而影响计算效率。
如果0x02～0x05存了一个int，读取这个int就需要先读0x01～0x04，留下0x02～0x04的内容，再读0x05～0x08，留下0x05的内容，两部分拼接起来才能得到那个int的值，这样读一个int就要两次内存访问，效率就低了。
*/
