/*
面试题 10.09. 排序矩阵查找

给定M×N矩阵，每一行、每一列都按升序排列，请编写代码找出某元素。

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。

给定 target = 20，返回 false。

/*
when it comes to problem of sorting the sequence, it is easy to think about binary search,
which couble sovled by the way called dividinf and conquering. but in this situation ,it may
not work out.beacause it is a matrix. when we use the binary search on the row, we may ignore 
the column, vice versa.
up to now, the best way i have is find the row which first number is lower than the target, and
use binary search on the column.
my solution is as below. but it has some bug, and i can't find them out.
*/
/*
analyse

my code as below shows that i still don't kown how to find the common characteristic of the problem,
some special situation could be contadined in the whole solution ,but i didn't had it well. I should 
review the binary search againe.

*/

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int i;
	int j;
    if(matrix.size()==0)
    {
        return false;
    }
	if(matrix.size()==1&&matrix[0].size()<=0)
	{
		return false;
	}
    if(matrix[0][0]==target) 
			return true;
	if(target<matrix[0][0]||target>matrix[matrix.size()-1][matrix[0].size()-1])
		return false;
	i=matrix.size()/2;
	for(i=0;i<matrix.size();i++)
	{
		if(matrix[i][0]==target) 
			return true;
		if(matrix[i][0]<target)
		{
			j=matrix[0].size()/2;
			int low=0;
			int high=matrix[0].size()-1;
			//printf("i:%d\t j:%d\n",i,j) ;
			
			while(j>0&&j<=matrix[0].size()-1&&low<=high&&high<matrix[0].size()&&j>=low&&j<=high)
			{
				if(matrix[i][j]==target)
				{
					return true;
				}
				else if(matrix[i][j]>target)
				{
					high=j-1;
					j=(low+j)/2;
				}
				else
				{
					low=j+1;
					j=(high+j+1)/2;
				}
			}
		} 
		else
		{
			return false;
		} 
	}
	return false;
    }
