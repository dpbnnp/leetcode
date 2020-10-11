/*
题目描述：
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
/*自己代码*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
int main() 
{
	string s="+100";
	int i;
	int dot=0;
	int f=0;
	int e=0;
	int ef=0;
	for(i=0;i<s.length();i++)
	{
		printf("s.length()%d\ts[i]%c\n",s.length(),s[i]);
		if((i==0&&(s[i]=='+'||s[i]=='-')&&f==0)||(a[i]>='0'&&a[i]<='9'))
		{
			printf("a\n");
			f=1;
			continue;
		}
		else
		{
			printf("a1\n");
			return -1;
		}
		if(s[i]>='0'||s[i]<='9')
		{
			printf("b\n");
			continue;
		}
		if(s[i]=='.'&&dot==0)
		{
			printf("c\n");
			dot=1;
			continue;
		}
		else
		{
			printf("c1\n");
			return -1;
		}
		if(s[i]=='E'&&e==0)
		{
			printf("d\n");
			i++;
			if((i<s.length()-1)&&(s[i]=='-'||(s[i]>='0'&&s[i]<='9')))
			{
				printf("d1\n");
				dot=0;
				continue;
			}
			else
			{
				printf("d2\n");
				return -1;
			}
		}
	}
	printf("是");
	return 0;
}
/*
一个个情况分别考虑，考虑着考虑着就漏了55555而且逻辑没有理清楚，用的if-else，
不会简化问题，不会找各种情况的共性，要利用共性解题
*/
/*大佬代码*/
/*
‘.’出现正确情况：只出现一次，且在e的前面

‘e’出现正确情况：只出现一次，且出现前有数字

‘+’‘-’出现正确情况：只能在开头和e后一位
*/
class Solution {
    public boolean isNumber(String s) {
        if (s == null || s.length() == 0) return false;
        //去掉首位空格
        s = s.trim();
        boolean numFlag = false;
        boolean dotFlag = false;
        boolean eFlag = false;
        for (int i = 0; i < s.length(); i++) {
            //判定为数字，则标记numFlag
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                numFlag = true;
                //判定为.  需要没出现过.并且没出现过e
            } else if (s.charAt(i) == '.' && !dotFlag && !eFlag) {
                dotFlag = true;
                //判定为e，需要没出现过e，并且出过数字了
            } else if ((s.charAt(i) == 'e' || s.charAt(i) == 'E') && !eFlag && numFlag) {
                eFlag = true;
                numFlag = false;//为了避免123e这种请求，出现e之后就标志为false
                //判定为+-符号，只能出现在第一位或者紧接e后面
            } else if ((s.charAt(i) == '+' || s.charAt(i) == '-') && (i == 0 || s.charAt(i - 1) == 'e' || s.charAt(i - 1) == 'E')) {

                //其他情况，都是非法的
            } else {
                return false;
            }
        }
        return numFlag;
    }
}
