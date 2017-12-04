#include<stdio.h>
#include<string.h>
/*���������ı��룬ѹ������ѹ
 */
typedef struct{
    double weight;
    int parent,left_child,right_child;
    char data;
    char num;
    char string[100];
}node;
node ht[60];

typedef struct{
    char data;
    double weight;
    int num;
    int flag;
}ready_sort;
ready_sort arr[60];
void createtree(node *ht,ready_sort *arr,int len);
ready_sort select(ready_sort *arr,int j);
void code(node *ht);
void reverse(char *string);
int n=0;
int main()
{
    /*printf("�������ַ�����Сn:");
    scanf("%d",&n);
    printf("������n���ַ�\n");
    for(int i=1;i<=n;i++)
        scanf(" %c",&(arr[i].data));
    printf("��������n��Ȩֵ\n");
    for(int i=1;i<=n;i++)
        scanf(" %lf",&(arr[i].weight));
    for(int i=1;i<=2*n-1;i++)
        arr[i].num = i;
    createtree(ht,arr,n);
    code(ht);
    char input[100]={0};
    char result[100]={0};
    scanf(" %s",input);
    for(int i=0;i<strlen(input);i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ht[j].data == input[i])
                strcat(result,ht[j].string);
        }
    }
    printf("%s\n",result);*/
	FILE *fp= fopen("/home/cwh/Desktop/code/source.txt","r");
	fseek(fp,0L,SEEK_END);
	int total_char= ftell(fp);//��ȡ�ļ���С
	rewind(fp);
	int i=0;
	char temp[100];
	double alpha[27]={0};
	int size;
	while( (size=fread(temp,1,10,fp))!=0)
	{
		for(int i=0;i<size;i++)
		{
			alpha[temp[i]-'a'+1]++;
		}
	}
	fclose(fp);
	double freque[27]={0};
	for(int i=1;i<27;i++)
	{
		freque[i] = alpha[i];
	}
	for(int i=1;i<27;i++)
	{
		if(alpha[i]!=0)
			n++;
	}

	int j =1;
	for(int i =1;i<=26;i++)
	{
		if(alpha[i]!=0)
		{
			arr[j].weight = freque[i];
			arr[j].data = 'a'+i-1;
			j++;
		}
	}
	for(int i=1;i<=2*n-1;i++)
		arr[i].num = i;
	//for(int i=1;i<=n;i++)
		//printf("%weight:lf data:%c\n",arr[i].weight,arr[i].data);
	createtree(ht,arr,n);
	code(ht);

	//for(int i=1;i<=2*n-1;i++)
		//printf("i=%d,weight=%lf,pre=%d,lef=%d,right=%d,data=%c, num=%d,string%s,\n", i,ht[i].weight,ht[i].parent,ht[i].left_child,ht[i].right_child,ht[i].data,ht[i].num,ht[i].string);

	char input[100]={0};
    char result[1000]={0};
    fp = fopen("/home/cwh/Desktop/code/source.txt","r");
    //��ȡ����
    while((size = fread(input,1,10,fp))!=0)
    {
	    //scanf(" %s",input);
        for(int i=0;i<strlen(input);i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(ht[j].data == input[i])
                    strcat(result,ht[j].string);
            }
        }
    }

	unsigned char comprassion[1000]={0};//����0������
	int num=0;
    //����λ����
	const int OR[]={128,64,32,16,8,4,2,1};
	const int AND[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
	for(i=0;i<strlen(result);i++)
	{
		if(result[i]=='1')
			comprassion[num]|=OR[i%8];
		if(result[i]=='0')
			comprassion[num]&=AND[i%8];	
		if((i+1)%8==0)
			num++;
	}
    //�����β���ܲ�û������
	if((i+1)%8==0)
		comprassion[num]='\0';
	else 
	{
		num++;
		comprassion[num]='\0';
	}
    fp = fopen("/home/cwh/Desktop/code/code.txt","w");
    int len = strlen(result);
    fwrite((void *)&len,1,sizeof(len),fp);//д���ж���λ
    fwrite(ht,1,sizeof(ht),fp);//д��ÿ����Ȩֵ
    fwrite(comprassion,1,sizeof(comprassion),fp);//д��ѹ���ı���
    fflush(fp);
    fclose(fp);

    printf("write code\n");

    fp=fopen("/home/cwh/Desktop/code/code.txt","r");
    node inflate[60];
    int bytes;
    fread((void*)&bytes,1,sizeof(int),fp);
    fread(inflate,1,sizeof(inflate),fp);
    
    unsigned char temp_back;
    char back[1000]={1};
    int back_num=0;
    while((size=fread(&temp_back,1,1,fp))!=0)
    {
        for(int j=0;j<8;j++)
        {
            back[back_num++]=(OR[j]&temp_back)?'1':'0';
            //char������ַ�0
        }
        if (back_num > bytes)
            break;
    }
    
    back[bytes]='\0';
    printf("back:%s",back);
	return 0;

}


void createtree(node *ht,ready_sort *arr,int len)
{
    int m = 2*len-1;
    int j = n;
    ready_sort s1,s2;
    for(int i = 1;i<=len;i++) 
    {
        node a = {arr[i].weight,0,0,0,arr[i].data,0};
        ht[i] = a;
    }
    for(int i = len+1;i<=m;i++)
    {
        node a = { 0,0,0,0,0,0};
        ht[i] = a;
    }
    for(int i=1;i<=m;i++)
        arr[i].flag=1;
    for(int i = len+1;i<=m;i++)
    {
        s1 = select(arr,j);
        s2 = select(arr,j);
        arr[++j].weight = s1.weight + s2.weight;

        ht[i].weight = s1.weight + s2.weight;
        ht[i].left_child = s1.num;
        ht[i].right_child = s2.num;
        ht[s1.num].parent = i;
        ht[s2.num].parent = i;
    }
}
ready_sort select(ready_sort *arr,int m)
{
    int min;
    for(int i=1;i<=m;i++)
    {
        if(arr[i].flag)
        {
            min = i;
            break;
        }
    }
    for(int j=1;j<=m;j++)
    {
        if(arr[j].flag)
        {
            if(arr[min].weight > arr[j].weight)
                min = j;
        }
    }
    arr[min].flag = 0;
    return arr[min];
    
}
void code(node *ht)
{
    for(int i=1;i<=2*n-1;i++)//���
    {
        ht[ht[i].left_child].num ='0';
        ht[ht[i].right_child].num ='1';
    }
    for(int i=1;i<=n;i++)
    {
        char string[2];
        string[1]='\0';
        int j=i;

        while(1)
        {
            if(ht[j].parent ==0)
                break;
            string[0]=ht[j].num;
            strcat(ht[i].string,string);
            j = ht[j].parent;
        }
        reverse(ht[i].string);
    }
    
}
void reverse(char *string)
{
    int len = strlen(string);
    char result[100]={0};
    int j=0;
    for(int i = len-1;i>=0;i--)
    {
        result[j++]=string[i];
    }
    result[j]='\0';
    strcpy(string,result);
}
