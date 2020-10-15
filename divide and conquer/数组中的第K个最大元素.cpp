/*
题目描述：
215. 数组中的第K个最大元素

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

leetcode：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
*/

/*
分析：实际上还是排序问题，数组排好序了问题就迎刃而解。选择自己已知的最好的排序算法。
可以使用快排，从大排到小，注意边界条件。

*/
class Solution {
public:
   int partition(vector<int>& nums,int b,int e)
{
	int n=nums[b];
	int f=b;
	b++;
	while(b<=e)
	{
		//printf("b:%d\te:%d\n",nums[b],nums[e]);
		while(b<=e&&nums[b]>=n)
		{
			b++;
		}
		while(b<=e&&nums[e]<n)
		{
			e--;
		}
		if(b<=e)
		{
			int temp=nums[b];
			nums[b]=nums[e];
			nums[e]=temp;
			b++;
			e--;
		}
	}
  /*
  这一部分又出错！搞成b位置与目标元素互换了。但是想了一下，无论是从小到大排序还是从大到小排序，都是和e进行互换，
  原因是e位置一定是需要位于目标元素左边的，刚好目标元素所占数组位置位于左边，因此需要将目标元素位置与e的位置互换。
  
  */
	nums[f]=nums[e];
	nums[e]=n;
	return e;
}
void quicksort(vector<int>& nums,int b,int e)
{
	if(b>=e)
	{
		return;
	}
	int q=partition(nums,b,e);
	quicksort(nums,b,q-1);
	quicksort(nums,q+1,e);
	return;
}
int findKthLargest(vector<int>& nums, int k) {
	if(nums.size()<=0||k<1||k>nums.size())
	{
		return 0;
	}
	quicksort(nums,0,nums.size()-1);
	//printf("%d\n",nums[k-1]);
	return nums[k-1];
}
};
