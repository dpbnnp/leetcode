/*
此题是动态规划的经典题，1.先确定大问题是否包含子问题；2.在确定传递函数；3.确定初始状态，以及特殊情况单独处理
*/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
            int n=grid.size();
	if(n<0||n>200)
		return 0;
	int m=grid[0].size();
	if(m<0||m>200)
		return 0;
	int dp[200][200];
	memset(dp,0,sizeof(dp));
	int i,j;
	dp[0][0]=grid[0][0];
	for(i=1;i<m;i++)
	{
		dp[0][i]=grid[0][i]+dp[0][i-1];
	}
    if(n==1)
        return dp[0][i-1];
	for(i=1;i<n;i++)
	{
		dp[i][0]=grid[i][0]+dp[i-1][0];
	}
	
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
		}
	}
    return dp[i-1][j-1];
    }
};
