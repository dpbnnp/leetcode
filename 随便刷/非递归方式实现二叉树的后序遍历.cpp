/*
此题目来自于课程作业
非递归方式实现二叉树的后序遍历
Description
给定一个二叉树，用非递归的方式实现二叉树的后序遍历。
Input
输入第一行为一个整数 n (1 <= n <= 100000), 表示二叉树的节点个数。
接下来共有 n 行, 每行有两个整数 l 和 r, 分别表示第 i (i为每一行的行号)个节点的左孩子和右孩子下标, 值为 0 表示当前节点没有左孩子/右孩子. 根节点的下标始终为 1.
Output
输出二叉树后续遍历的结果, 用空格分隔.
Sample Input 1
5
2 4
5 3
0 0
0 0
0 0
Sample Output 1
5 3 2 4 1
Hint
以第一组测试用例为例, 二叉树共 5 个节点, 接下来 5 行输入,
第 1 行为 2 4, 表示节点编号为 1 的节点(根节点)的左孩子为编号为 2 的节点, 右孩子为编号为 4 的节点.
第 2 行为 5 3, 表示节点编号为 2 的节点的左孩子为编号为 5 的节点, 右孩子为编号为 3 的节点.
后续输入均为 0, 表示剩下编号为 3, 4, 5 的节点均无左/右孩子节点.
*/
/*
后序遍历的思想就是，先输出左子树，再输出右子树，再输出根节点，由于不让递归，所以得借助内训单元来存储递归栈，
需要判断左子树是否输出完，右子树是否输出完，所以需要借助一个变量来表示左右子树是否输出完。

*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;
struct node
{
	int num;
	struct node *left;
	struct node *right;
	int flag;
};
void inittree(node ** &allnode,int num)
{
	allnode=(node**)malloc(sizeof(node*)*num);
	int i=0;
	for(;i<num;i++)
	{
		allnode[i]=(node*)malloc(sizeof(node));
		allnode[i]->num=i+1;
		allnode[i]->left=NULL;
		allnode[i]->right=NULL;
		allnode[i]->flag=0;
	}
	for(i=0;i<num;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l!=0)
		{
			allnode[i]->left=allnode[l-1];
		}
		if(r!=0)
		{
			allnode[i]->right=allnode[r-1];
		}
	}
}
void show_tree(node *head)
{
	
	stack<node*> s;
	s.push(head);
	while(!s.empty())
	{
		node *c=s.top();
		if(c->flag==0&&c->left!=NULL)
		{
			c->flag=1;
			s.push(c->left);
		}
		else if((c->flag==0||c->flag==1)&&c->right!=NULL)
		{
			c->flag=2;
			s.push(c->right);
		}
		else
		{
			printf("%d ",c->num);
			s.pop();
		}
	}
}
int main()
{
	int num;
	scanf("%d",&num);
	if(num<1||num>100000)
		return 0;
	node *frist;
	node** allnode;
	inittree(allnode,num);
	int i;
	show_tree(allnode[0]);
	return 0;
}
