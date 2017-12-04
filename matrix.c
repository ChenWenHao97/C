#include<stdio.h>
#include<string.h>
typedef struct{
    int clo,row;
    int value;
}three;
three arr1[100];
three arr2[100];
int top1=0;
int top2=0;
int zero=0;
int sum_clo=0,sum_row=0;
int matrix1[21][21];
int matrix2[21][21];
void add(three *ar1 ,three *ar2 );
void substract(three *ar1,three *ar2);
void reverse(three *ar1,three *ar2);
int main()
{
    int row1,clo1;
    int row2,clo2;
    printf("请输入你的矩阵的行数和列数：");
    scanf("%d%d",&sum_row,&sum_clo);
    printf("请输入矩阵1非零元素个数\n");
	int for_num=0;
	scanf("%d",&for_num);
	memset(arr1,0,sizeof(arr1));
	int a,b,c;
	printf("输入三元组\n");
	for(int i=0;i<for_num;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		arr1[top1].row = a;
		arr1[top1].clo = b;
		arr1[top1].value = c;
		top1++;
	}
            
    printf("请输入矩阵2非零元素个数\n");
	for_num=0;
	scanf("%d",&for_num);
	memset(arr2,0,sizeof(arr2));
	a=b=c=0;
	printf("输入三元组\n");
	for(int i=0;i<for_num;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		arr2[top2].row = a;
		arr2[top2].clo = b;
		arr2[top2].value = c;
		top2++;
	}
     while(1)
    {
        printf("请输入你要进行的操作(1、相加 2、相减 3、逆置）\n");
        int num=0;
        scanf(" %d",&num);
        switch(num)
        {
            case 1:
                add(arr1,arr2);
                break;
            case 2:
                substract(arr1,arr2);
                break;
            case 3:
                reverse(arr1, arr2);
                break;
        }
    }
	 return 0;

}
void add(three *ar1,three *ar2)
{
    three result[100];
    int i=0,j=0,k=0;
    while(1)
    {
        if(i>=top1||j>=top2)
        {
            break;
        }
        
        if(ar1[i].clo==ar2[j].clo && ar1[i].row==ar2[j].row)
        {
           
            result[k]=ar1[i];
            result[k].value = ar1[i].value + ar2[j].value;
            
            k++;i++;j++;
        }
        else if(ar1[i].row == ar2[j].row && ar1[i].clo!=ar2[j].clo)
        {
            if(ar1[i].clo < ar2[j].clo)
            {
                
                result[k]=ar1[i];
                result[k].value = ar1[i].value;
                k++;i++;
            }
            else if(ar1[i].clo > ar2[j].clo)
            {
               
                result[k]=ar1[j];
                result[k].value = ar2[j].value;
                k++;j++;
            }

        }
        else if(ar1[i].row < ar2[j].row)
        {
            
            result[k]=ar1[i];
            result[k].value = ar1[i].value;
            k++;i++;
        }
        else if(ar1[i].row > ar2[j].row)
        {
            
            result[k]=ar1[j];
            result[k].value = ar2[j].value;
            k++;j++;
        }


    }
    while(i<top1)
    {
        result[k]=ar1[i];
        result[k].value = ar1[i].value;
        k++;i++;       
    }
    while(j<top2)
    {
        result[k]=ar2[j];
        result[k].value = ar2[j].value;
        k++;j++;
        
    }
    int begin = 0;
    for(int i=0;i<sum_row;i++)
    {
        putchar('\n');
        for(int j=0;j<sum_clo;j++)
        {
            if(result[begin].clo==j&&result[begin].row==i)
            {
                printf("%d ",result[begin].value);
                begin++;
            }
            else 
                printf("0 ");
        }
    }
    putchar('\n');
}

void substract(three *ar1,three *ar2)
{
    three result[100];
    int i=0,j=0,k=0;
    while(1)
    {
        if(i>=top1||j>=top2)
        {
            break;
        }
        
        if(ar1[i].clo==ar2[j].clo && ar1[i].row==ar2[j].row)
        {
            result[k] = ar1[i];
            result[k].value = ar1[i].value - ar2[j].value;
            
            k++;i++;j++;
        }
        else if(ar1[i].row == ar2[j].row && ar1[i].clo!=ar2[j].clo)
        {
            if(ar1[i].clo < ar2[j].clo)
            {
                result[k]= ar1[i];
                result[k].value = ar1[i].value;
                k++;i++;
            }
            else if(ar1[i].clo > ar2[j].clo)
            {
                result[k]= ar2[j];
                
                result[k].value = (-1)*ar2[j].value;
                k++;j++;
            }

        }
        else if(ar1[i].row < ar2[j].row)
        {
            result[k] = ar1[i];
            result[k].value = ar1[i].value;
            k++;i++;
        }
        else if(ar1[i].row > ar2[j].row)
        {
            result[k]= ar2[j];
            result[k].value = ar2[j].value;
            k++;j++;
        }

    }
    while(i<top1)
    {
        result[k]= ar1[i];
        result[k].value = ar1[i].value;
        k++;i++;       
    }
    while(j<top2)
    {
        result[k]= ar2[j];
        
        result[k].value = (-1)*ar2[j].value;
        
        k++;j++;
        
    }
    int begin = 0;
    for(int i=0;i<sum_row;i++)
    {
        putchar('\n');
        for(int j=0;j<sum_clo;j++)
        {
            if(result[begin].clo==j&&result[begin].row==i)
            {
                printf("%d ",result[begin].value);
                begin++;
            }
            else 
                printf("0 ");
        }
    }
    putchar('\n');
}
void reverse(three *ar1,three *ar2)
{
    three reverse1[100];
    three reverse2[100];
	memset(reverse1,0,sizeof(reverse1));
	memset(reverse2,0,sizeof(reverse2));
    int new_clo=sum_row,new_row=sum_clo;

    int num[400];
    int pos1[100],pos2[100];
    memset(num,0,sizeof(num));
    for(int i=0;i<top1;i++)
        num[ar1[i].clo]++;

    pos1[0]=0;
    for(int i=1;i<sum_clo+1;i++)
        pos1[i] = pos1[i-1]+num[i-1];
    int q;
    for(int i=0;i<top1;i++)
    {
		q = pos1[ar1[i].clo]++;
        reverse1[q].row = ar1[i].clo;
        reverse1[q].clo = ar1[i].row;
        reverse1[q].value = ar1[i].value;
    }
	
    int begin = 0;
	printf("矩阵1的逆\n ");
    for(int i=0;i<new_row;i++)
    {
        putchar('\n');
        for(int j=0;j<new_clo;j++)
        {
            if(reverse1[begin].clo==j&&reverse1[begin].row==i)
            {
                printf("%d ",reverse1[begin].value);
                begin++;
            }
            else 
                printf("0 ");
        }
    }
    putchar('\n');    


    memset(num,0,sizeof(num));
    for(int i=0;i<top2;i++)
        num[ar2[i].clo]++;

    pos2[0]=0;
    for(int i=1;i<sum_clo+1;i++)
        pos2[i] = pos2[i-1]+num[i-1];
    int q1;
    for(int i=0;i<top2;i++)
    {
        q1 = pos2[ar2[i].clo]++;
        reverse2[q1].row = ar2[i].clo;
        reverse2[q1].clo = ar2[i].row;
        reverse2[q1].value = ar2[i].value;
    }

    int end = 0;
	putchar('\n');
	printf("矩阵2的逆\n ");
    for(int i=0;i<new_row;i++)
    {
        putchar('\n');
        for(int j=0;j<new_clo;j++)
        {
            if(reverse2[end].clo==j&&reverse2[end].row==i)
            {
                printf("%d ",reverse2[end].value);
                end++;
            }
            else 
                printf("0 ");
        }
    }
    putchar('\n');    

	return ;
}
