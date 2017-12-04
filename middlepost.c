#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//根据中序和后序建立二叉树
typedef struct node* tree_pointer;
typedef struct node{
	tree_pointer left_child;
	tree_pointer right_child;
	char data;
}tree;
int find_index(char* arr,char data);//找到对应值在数组的索引
void create_tree(tree **node,char *postorder,char *inorder);
int num;
int Index;//全局变量
void pre_order(tree *what) 
{
	if (what == NULL)
		return;
	printf("%c ", what->data);
	pre_order(what->left_child);
	pre_order(what->right_child);
	
}
int main()
{
	char postorder[100] = {0};
	char inorder[100] = {0};
	printf("输入节点个数:");
	scanf(" %d",&num);
	Index = num;//后序列的根是在后面
	//i=1开始的好处是设置了哨兵，每次中序的时候，最左边的元素向左边找的时候是空
	//这才证明这个点没有左子树
	printf("输入后序序列:");
	for(int i=1;i<=num;i++)
		scanf(" %c",&postorder[i]);
	printf("输入中序序列:");
	for(int i=1;i<=num;i++)
		scanf(" %c",&inorder[i]);
	tree *node; 
	create_tree(&node,postorder,inorder);
	printf("前序的结果是：");
	pre_order(node);//前序遍历检验答案
	putchar('\n');
}

void create_tree(tree **node,char *postorder,char *inorder)
{
	
	//tree *left;
	//tree *right;
	int find_in;
	char temp;
	(*node) = (tree *)malloc(sizeof(tree));
	//后序列最后一个是根，所以找后序最后一个，建立根节点
	(*node)->data = postorder[Index];//root
	find_in = find_index(inorder,postorder[Index]);//找到根在序列中对应的位置
	postorder[Index--] = '\0';//每次创建一个节点，在数组中就吧该节点删除，方便如何结束递归
	//Index可以记录已经创建了多少节点了

	//后序+中序不同于前序+中序的是先建立右子树木，再建立左子树
	inorder[find_in] = '\0';//将中序对应的值记为'\0
	if(inorder[find_in+1]!='\0')//如果中序列中已经创立的节点左边有数值，证明有右子树
		create_tree(&((*node)->right_child),postorder,inorder);
	else//没有右子树就记为空
		(*node)->right_child = NULL;

	if(inorder[find_in-1]!='\0')//有左子树
		create_tree(&((*node)->left_child),postorder,inorder);
	else//没有左子树就记为空
		(*node)->left_child = NULL;


}
int find_index(char *arr,char data)
{
	for(int i=1;i<=num;i++)//切记，这里不能用strlen，因为删除一个用'\0'，而且因为有哨兵，所以永远是0
	{
		if(arr[i] == data)
			return i;
	}
	return 0;

}
