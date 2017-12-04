#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 100
typedef struct node* tree_pointer;
typedef struct node{
    char data;
    tree_pointer left_child,right_child;
}BiTree;
void CreateBiTree(BiTree **root);
void PreOrder(BiTree *root);
void InOrder(BiTree *root);
void PostOrder(BiTree *root);
void OPreOrder(BiTree *root);
void OInOrder(BiTree *root);
void OPostOrder(BiTree *root);
BiTree *STACK[MAX];
void push(int *top,BiTree *ptr);
BiTree *pop(int *top);
BiTree *Top(int top);
void treeshape(BiTree *root,int n);
int leaf(BiTree *root);
void treeheight(BiTree *root,int h);
int depth = 0;
int main()
{
    BiTree *root;//这里是一个指针，才能不把地址固定，进而可以进行malloc操作
	printf("请根据先序输入数据\n");
    CreateBiTree(&root);//只有二重指针才可以改值
    putchar('\n');
	while(1)
	{
        printf("1、先序遍历  2、中序便利 3、后序遍历\n \
4、先序递归 5、中序递归 6、后序递归\n \
7、打印树状 8、打印叶子节点数 9、打印树高度\n");
		printf("输入-1退出\n");
        int num;
        scanf(" %d",&num);
        if(num == -1)
            break;
        switch(num)
        {
            case 1:
                PreOrder(root);
                putchar('\n');
                break;
            case 2:InOrder(root);
                putchar('\n');
                break;
            case 3:PostOrder(root);
                putchar('\n');
                break;
            case 4:
                memset(STACK,0,sizeof(STACK));
                OPreOrder(root);
                putchar('\n');
                break;
            case 5:memset(STACK,0,sizeof(STACK));
                OInOrder(root);
                putchar('\n');
                break;
            case 6:memset(STACK,0,sizeof(STACK));
                OPostOrder(root);
                putchar('\n');
                break;
            case 7:
                treeshape(root,1);
                putchar('\n');
                break;
            case 8:
                printf("\n叶子结点为：%d\n",leaf(root));
                break;
            case 9:
                treeheight(root,0);
                printf("树的高度为 %d\n",depth);
        }
	}
	return 0;
    
}
void CreateBiTree(BiTree **root)
{
    char ch;
    scanf(" %c",&ch);
    if(ch == '#') 
        *root = NULL;
    else 
    {
        *root = (BiTree*)malloc(sizeof(BiTree));
        (*root)->data = ch;
        CreateBiTree(&((*root)->left_child));
        CreateBiTree(&((*root)->right_child));
    }

}
void PreOrder(BiTree *root)
{
    if(root)
    {
        printf("%c ",root->data);
        PreOrder(root->left_child);
        PreOrder(root->right_child);
    }
}
void InOrder(BiTree *root)
{
    if(root)
    {
        InOrder(root->left_child);
        printf("%c ",root->data);
        InOrder(root->right_child);
    }
}
void PostOrder(BiTree *root)
{
    if(root)
    {
        PostOrder(root->left_child);
        PostOrder(root->right_child);
        printf("%c ",root->data);
    }
}
void push(int *top,BiTree *ptr)
{
    if(*top == MAX-1)
    {
        printf("stack full\n");
        return;
    }
    else 
        STACK[++(*top)] = ptr;//因为从-1，所以下一个元素0开始，所以先++
                            //0 开始，后++

}
BiTree *pop(int *top)
{
    if(*top == -1)
    {
        printf("stack empty\n");
        return NULL;
    }
    else 
    {
        return STACK[(*top)--];//-1开始 从本元素减，所以后--;
                                //0开始，前--
    }

}

void OPreOrder(BiTree *root)
{
    int top = -1;//从个元素加起
    BiTree *p = root;
    while(p!=NULL || top!=-1)
    {
        while(p!=NULL)
        {
            printf("%c ",p->data);
            push(&top,p);
            p = p->left_child;
        }
        if(top!=-1)
        {
            p = pop(&top);
            p = p->right_child;
        }

    }
}
void OInOrder(BiTree *root)
{
	int top = -1;//从0个元素加起
    BiTree *p = root;
    while(p!=NULL || top!=-1)
    {
        while(p!=NULL)
        {
            push(&top,p);
            p = p->left_child;
        }
        if(top!=-1)
        {
            p = pop(&top);
			printf("%c ",p->data);
            p = p->right_child;
        }
    }
}
void OPostOrder(BiTree *root)
{
	int top = -1;//从0个元素加起
    BiTree *p = root;
	BiTree *q = NULL;
    while(p!=NULL || top!=-1)
    {
        while(p!=NULL)//先遍历左边
        {
            push(&top,p);
            p = p->left_child;
        }
        if(top!=-1)
        {
           p = Top(top);//获得栈顶元素
           if((p->right_child == NULL) || p->right_child == q)//如果右边为空，或者右边访问过，就输出
            //切记，不能写判断左边和右边为空，如果那样写，就会进入死循环，永远不能输出
		   {
			   p = pop(&top);
			   printf("%c ",p->data);
			   q = p;//记下上一步做过的点
               p =NULL;//将当前点设为空，就可以跳过开头while循环
		   }
           else 
           {
                p = p->right_child;
           }
        }

    }
}
BiTree *Top(int top)
{
	 return STACK[top];
}
void treeshape(BiTree *root,int n)//获得树的形状
{
	if (root == NULL) 
		return ;
	treeshape(root->right_child,n+1);
	for(int i=0;i<n;i++)
		printf("   ");
	printf("%c\n",root->data);
	treeshape(root->left_child,n+1);

}
int leaf(BiTree *root)//获得叶子节点个数
{
	int left,right;
	if(root == NULL)
		return 0;
	if(root->left_child == NULL && root->right_child == NULL)
		return 1;
	left = leaf(root->left_child);
	right = leaf(root->right_child);
	return left + right;

}
void treeheight(BiTree *root,int h)//获得树的高度，放在全局变量depth里面
{
	if(root)
	{
		if(h > depth)
			depth =h;
		treeheight(root->left_child,h+1);
		treeheight(root->right_child,h+1);
	}
}
