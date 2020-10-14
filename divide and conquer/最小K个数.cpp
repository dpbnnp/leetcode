/*
题目描述
设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]

提示：

    0 <= len(arr) <= 100000
    0 <= k <= min(100000, len(arr))

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-k-lcci
*/
/*
分析：实际上就是对数组进行排序，排序后返回最小的k个数，
排序算法将会决定个算法的时间复杂度和空间复杂度。
可以使用快排，但是不知道为什么我写的快排，返回的排序向量不对，
我的while循环刚开始好像没有做到保证循环结束后b>e，
同时返回的那个数不太对，搞成了返回b
*/
class Solution {
public:
    int partition(vector<int> &a,int b,int e)
{
	int num=a[b];
	int f=b;
	b++; 
	while(b<=e)
	{
		
		while(e>=b&&a[e]>=num)
		{
			e--;
		}
		while(b<=e&&a[b]<num)
		{
			b++;
		}
		if(b<e)
		{
			int temp=a[b];
			a[b]=a[e];
			a[e]=temp;
			b++;
			e--;
		}
	}
	a[f]=a[e];
	a[e]=num;
	return e;
}
void quick_sort(vector<int> &a,int b,int e)
{
	if(b>=e)
		return ;
	int q=partition(a,b,e);
	quick_sort(a,b,q-1);
	quick_sort(a,q+1,e);
}
vector<int> smallestK(vector<int> &a,int k)
{
	if(a.size()==0||a.size()<k)
	{
		vector<int> t;
		return t;
	}
	if(a.size()==k)
	{
		return a;
	}
	quick_sort(a,0,a.size()-1);
	int i=0;
	vector<int> target;
	for(;i<k;i++)
	{
		target.push_back(a[i]);
	}
	return target;
}
};
