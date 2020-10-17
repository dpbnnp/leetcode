/*
二叉树中的最大路径和
Description
给定一个非空二叉树，返回其最大路径和。
本题中，路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
Input
输入第一行为一个整数 n (1 <= n <= 100000), 表示二叉树的节点个数。
接下来共有 n 行, 每行有 3 个整数 l、r 和 val, 分别表示第 i (i为每一行的行号)个节点的左孩子和右孩子下标以及第 i 个节点的权值, 左/右孩子下标值为 0 表示当前节点没有左孩子/右孩子. 根节点的下标始终为 1.
Output
输出单独的一行, 即当前二叉树的最大路径和
Sample Input 1
5
2 3 -10
0 0 9
4 5 20
0 0 15
0 0 7
Sample Output 1
42
Hint
样例中共 5 个节点,
输入的开始 5 表示共5个节点
接下来第 1 行, 2 3 -10 表示节点 1 的左孩子为 2 号节点, 右孩子为 3 号节点, 节点 1 的权值为 -10
第 2 行 0 0 9 表示节点 2 没有左孩子也没有右孩子, 节点 2 的权值为 9
第 3 行 4 5 20 表示节点 3 的左孩子为 4 号节点, 右孩子为 5 号节点, 节点 3 的权值为 20
第 4 行 0 0 15 表示节点 4 没有左孩子也没有右孩子, 节点 4 的权值为 15
第 5 行 0 0 7 表示节点 5 没有左孩子也没有右孩子, 节点 5 的权值为 7
从而可以得到下面的二叉树, 对于该二叉树, 最大路径和对应的路径为 4 - 3 - 5, 对应路径和的值为 15 + 20 + 7 = 42
*/
/*
这道题目实际上也是树的遍历，不过特殊之处在于，每个节点都可以作为根节点。而且需要计算最大值，
*/
#include<stdio.h>
#include<stdlib.h>
#include<cstdio>
#include<string.h>
#include <math.h>
#include<stack>
#include<queue>
using namespace std;
struct node{
	int data;
	struct node *right;
	struct node *left;
	struct node *father;
};
void inittree(node** &nodes,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		nodes[i]=(node*)malloc(sizeof(node));
		nodes[i]->right=NULL;
		nodes[i]->left=NULL;
	}
	for(i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d%d",&l,&r,&nodes[i]->data);
		if(l!=0)
		{
			nodes[i]->left=nodes[l-1];
			nodes[l-1]->father=nodes[i];
		}
		if(r!=0)
		{
			nodes[i]->right=nodes[r-1];
			nodes[r-1]->father=nodes[i];
		}
	}
}
void show_tree(node *head)
{
	node* tmp = head;
	if(tmp!=NULL)
	{
		printf("%d\t",tmp->data);
		show_tree(tmp->left);
		show_tree(tmp->right);
	}
}
int max_len(node* root,int &res) {
		if (root == NULL) return 0;
		int left = max_len(root->left,res);
		int right = max_len(root->right,res);
		int cur = root->data + max(0, left) + max(0, right);
		if (cur > res) res = cur;
		return root->data + max(left, max(right, 0));
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n<1||n>100000)
	{
		return 0;
	}
	node **nodes;
	nodes=(node**)malloc(sizeof(node*)*n);
	inittree(nodes,n);
	nodes[0]->father=NULL;
	int i=0;
	int maxl=nodes[0]->data;
	for(;i<n;i++)
	{
		int c=max_len(nodes[i],maxl);
	}
	printf("%d",maxl);
	return 0;
}
int max_len(node* root,int &res) {
		if (root == NULL) return 0;
		int left = max_len(root->left,res);
		int right = max_len(root->right,res);
		int cur = root->data + max(0, left) + max(0, right);
		if (cur > res) res = cur;
		return root->data + max(left, max(right, 0));
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n<1||n>100000)
	{
		return 0;
	}
	node **nodes;
	nodes=(node**)malloc(sizeof(node*)*n);
	inittree(nodes,n);
	nodes[0]->father=NULL;
	int i=0;
	int maxl=nodes[0]->data;
	for(;i<n;i++)
	{
		int c=max_len(nodes[i],maxl);
	printf("%d",maxl);
	return 0;
}
