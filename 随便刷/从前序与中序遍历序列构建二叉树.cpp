/*
从前序与中序遍历序列构建二叉树
Description
从前序与中序遍历序列构建二叉树，返回其后序序列
Input
输入包含三行
第一行为一个正整数 n （1<=n<=100000）, 表示二叉树的节点个数
第二行为 n 个正整数用空格隔开, 表示二叉树的先序遍历结果
第三行为 n 个正整数用空格隔开, 表示二叉树的中序遍历结果
Output
输出单独一行, 表示二叉树后序遍历的结果
Sample Input 1
8
1 3 2 5 6 7 4 8
3 1 5 7 6 2 8 4
Sample Output 1
3 7 6 5 8 4 2 1
*/
/*
思路：需要使用先序遍历和中序遍历主要原因是，单纯使用一种遍历方法无法确定根节点、左子树、右子树。
而而这组合起来，可以确定根节点、左子树和右子树。
依据这个特性，递归构造子树。先确定根节点，再构造左子树、右子树。注意判定什么时候结束递归。
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
	int num;
	struct node *right;
	struct node *left;
};
node* inittree(int qian[],int zhong[],int xianb,int xiane,int zhongb,int zhonge)
{
	if(xianb>xiane)
	{
		return NULL;
	}
	node* n;
	n=(node*)malloc(sizeof(node));
	n->left=NULL;
	n->right=NULL;
	n->num=qian[xianb];
	int i;
	for(i=0;i<zhonge;i++)
	{
		if(zhong[i]==n->num)
		{
			break;
		}
	}
	int j;
	for(i=zhongb;i<zhonge;i++)
	{
		if(zhong[i]==n->num)
		{
			break;
		}
	}
	n->left=inittree(qian,zhong,xianb+1,xianb+i-zhongb,zhongb,i-1);
	n->right=inittree(qian,zhong,xianb+i-zhongb+1,xiane,i+1,zhonge);
	return n;
}
void showtree(node *n)
{
	if(n==NULL)
		return;
	showtree(n->left);
	showtree(n->right);
	printf("%d ",n->num);
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n<0||n>100000)
	{
		return 0;
	}
	int *qian,*zhong;
	qian=(int*)malloc(sizeof(int)*n);
	zhong=(int*)malloc(sizeof(int)*n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&qian[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&zhong[i]);
	}
	node *head;
	head=(node*)malloc(sizeof(node));
	head=inittree(qian,zhong,0,n-1,0,n-1);
	showtree(head);
	return 0;
}
