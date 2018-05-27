/*考点
 * 1、大小端
 * 2、文件的写入
 */
#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp = fopen("linux.txt","wb");
    long long a = 0x78756e694c;
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);

    return 0;
}
/*
1111000     01110101    01101110       01101001    01001100
    x            u            n              i             L
*/
