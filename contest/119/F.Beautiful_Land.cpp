/*
链接：https://www.nowcoder.com/acm/contest/119/F
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 131072K，其他语言262144K
64bit IO Format: %lld

题目描述 
It’s universally acknowledged that there’re innumerable trees in the campus of HUST.
Now HUST got a big land whose capacity is C to plant trees. We have n trees which 
could be plant in it. Each of the trees makes HUST beautiful which determined by 
the value of the tree. Also each of the trees have an area cost, it means we need 
to cost ci area of land to plant.
We know the cost and the value of all the trees. Now HUSTers want to maximize the 
value of trees which are planted in the land. Can you help them?

输入描述:
There are multiple cases.
The first line is an integer T(T≤10), which is the number of test cases.
For each test case, the first line is two number n(1≤n≤100) and C(1≤C≤108), the 
number of seeds and the capacity of the land. 
Then next n lines, each line contains two integer ci(1≤ci≤106) and vi(1≤vi≤100), 
the space cost and the value of the i-th tree.

输出描述:
For each case, output one integer which means the max value of the trees that can 
be plant in the land.

示例1
输入
1
3 10
5 10
5 10
4 12

输出
22

解题思路:
对于这种背包容量C特别大而可能获得的总价值(N * maxValue)不是很大的问题, 直接DP会超时或者超内存.
我们该变一下dp[i][j]的定义: 
dp[i][j] 表示从前i个物品中选择总价值为j的物品时的最小重量.
总从右往左找到的第一个dp[n][j] <= C 的 j 就是答案.

初始状态: 
dp[0][j] = INF, 表示无解
dp[0][0] = 0

状态转移方程:
j>=v : dp[i][j] = min(dp[i-1][j], dp[i-1][j-v] + c)  
j< v : dp[i][j] = dp[i-1][j]   


*/
#include<bits/stdc++.h>
using namespace std;
const int maxn =101;
const int maxv =101;
const int N = maxn * maxv;
const int INF = 1e8;

//使用滚动数组优化内存
int d[2][N+5]; 

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    
    int T,n,total;
    int c,v;
    scanf("%d",&T);
    while(T--)
    {
        memset(d,0,sizeof(d));
        fill(d[0], d[0] + N + 1,  INF); //初始为无穷大的正数
        d[0][0] = 0; //重要

        scanf("%d%d",&n, &total); //个数, 总容量
        for(int i=1,last=0, now=1; i<=n; ++i, last^=1, now^=1)
        {
            scanf("%d%d",&c,&v);
            // for(int j=N-1; j>v; --j) d[j] = min(d[j], d[j-v] + c);
            for(int j=0; j<=N; ++j)
            {
                if(j < v)
                    d[now][j] = d[last][j];
                else
                    d[now][j] = min(d[last][j], d[last][j - v] + c);
            }
        }

        int j=N;
        while(d[n & 1][j] > total) --j;
        printf("%d\n", j);
    }

    return 0;
}
