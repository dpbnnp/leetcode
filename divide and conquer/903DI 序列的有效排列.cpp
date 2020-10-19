/*
903. DI 序列的有效排列
我们给出 S，一个源于 {'D', 'I'} 的长度为 n 的字符串 。（这些字母代表 “减少” 和 “增加”。）
有效排列 是对整数 {0, 1, ..., n} 的一个排列 P[0], P[1], ..., P[n]，使得对所有的 i：
    如果 S[i] == 'D'，那么 P[i] > P[i+1]，以及；
    如果 S[i] == 'I'，那么 P[i] < P[i+1]。
有多少个有效排列？因为答案可能很大，所以请返回你的答案模 10^9 + 7.
示例：
输入："DID"
输出：5
解释：
(0, 1, 2, 3) 的五个有效排列是：
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
*/

/*
本人思路如下，虽然我也不知道为什么代码没跑通。。。。
将字符串采用分治法的方式解决，每次从中间开始分开，然后计算左边符号的情况总数，计算右边符号情况总数，两个再汇总，就得到了当前符号串的所有情况，
但分问题的同时也依据这个位置对应的增减符号放好对应的数，所以需要给这两个位置的数打上标签。让其在在后面不会被用到。
对于递归边界处理
*/

/*
#include<stdio.h>
#include<stdlib.h>
#include<cstdio>
#include<string.h>
#include <math.h>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
struct data
{
	int d;
	int flag;
};
int numPermsDISequence(string S,data datas[],int start ,int end) {
	if(start>end)
		return 1;
	if(start==end)
		return 1;
	int mid=(end+start)/2;
	//printf("MID:%d\tfuhao:%c\n",mid,S[mid]);
	int i,j=0;
	int total=0;
	for(i=0;i<=S.size();i++)
	{
		for(j=i+1;j<=S.size();j++)
		{
			if(S[mid]=='D'&&datas[j].d<datas[i].d&&datas[i].flag!=1&&datas[j].flag!=1)
			{
				datas[i].flag=1;
				datas[j].flag=1;
				string s1;
				int l=numPermsDISequence(S,datas,start,mid);
				int r=numPermsDISequence(S,datas,mid+1,end);
				total+=l*r;
				datas[i].flag=0;
				datas[j].flag=0;
			}
			else if(S[mid]=='I'&&datas[j].d>datas[i].d&&datas[i].flag!=1&&datas[j].flag!=1)
			{
				datas[i].flag=1;
				datas[j].flag=1;
				string s1;
				int l=numPermsDISequence(S,datas,start,mid);
				int r=numPermsDISequence(S,datas,mid+1,end);
				total+=l*r;
				datas[i].flag=0;
				datas[j].flag=0;
			}
		}
	}
	return total;
}

int main()
{
	string S;
	cin>>S;
	int i;
	data *datas;
	datas=(data*)malloc(sizeof(int)*(S.size()+1));
	for(i=0;i<=S.size();i++)
	{
		datas[i].d=i;
		datas[i].flag=0;
	}
	int start,end;
	start=0;
	end=S.size();
	int all=numPermsDISequence(S,datas,start,end);
	printf("%d",all);
	return 0;
}
*/

/*
大佬用动态规划求解。
*/
class Solution {
public:
    int numPermsDISequence(string S) {
        int M = pow(10, 9)+7;
        //第一维表示取到S的第几个字母，第二维表示取值，例如0，1，2，3,dp[i][3]结尾取3
        vector<vector<int>> dp(S.size()+1,vector<int>(S.size()+1,0));
        dp[0][0] = 1;
        for(int i = 0;i<S.size();i++){
            if(S[i] == 'I'){
                for(int j = 1;j<=i+1;j++){
                    dp[i+1][j] = (dp[i+1][j-1]+dp[i][j-1])%M;
                }
            }else{
                for(int j = i;j>=0;j--){
                    dp[i+1][j] = (dp[i+1][j+1]+dp[i][j])%M;
                }
            }
        }
        int res = 0;
        for(int i = 0;i<dp.size();i++){
            res=(res+dp[dp.size()-1][i])%M;
        }
        return res;
    }
};
