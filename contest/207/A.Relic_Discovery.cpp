/*
链接：https://www.nowcoder.com/acm/contest/207/A
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 262144K，其他语言524288K
64bit IO Format: %lld
题目描述 
Recently, paleoanthropologists have found historical remains on an island in the Atlantic Ocean. 
The most inspiring thing is that they excavated in a magniﬁcent cave and found that it was a 
huge tomb. Inside the construction, researchers identiﬁed a large number of skeletons, and 
funeral objects including stone axe, livestock bones and murals. Now, all items have been 
sorted, and they can be divided into N types. After they were checked attentively, you are 
told that there are Ai items of the i-th type. Further more, each item of the i-th type requires 
Bi million dollars for transportation, analysis, and preservation averagely. As your job, you 
need to calculate the total expenditure. 
输入描述:
The ﬁrst line of input contains an integer T which is the number of test cases. For each test 
case, the ﬁrst line contains an integer N which is the number of types. In the next N lines, 
the i-th line contains two numbers Ai and Bi as described above. All numbers are positive 
integers and less than 101.
输出描述:
For each case, output one integer, the total expenditure in million dollars.
示例1
输入
复制
1
2
1 2
3 4
输出
复制
14
*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int T,n,sum,a,b;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d",&a,&b);
            sum += a*b;
        }
        printf("%d\n",sum);
    }
    
    return 0;
}