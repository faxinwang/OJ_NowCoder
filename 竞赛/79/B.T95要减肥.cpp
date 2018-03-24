/*
链接：https://www.nowcoder.com/acm/contest/79/B
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 262144K，其他语言524288K
64bit IO Format: %lld
题目描述 
T95提速啦，然而她觉得自己还是太慢了！

于是T95决定减肥——然而T95还喜欢吃麦当劳

现在有n种赛道，n家麦当劳，第i条赛道的痛苦值是ai，第i家麦当劳的快乐值是bi

为了减肥，T95吃的麦当劳次数不能大于她跑步的次数

由于T95太重了，每个赛道跑一次之后就会坏掉

由于T95喜欢吃不同的口味，每家麦当劳最多吃一次

由于明斯克航空航天局的蜜汁bug，T95每跑3次就会得到额外的m块乐值

现在T95想知道她可以得到的最大（快乐值的和-痛苦值的和）是多少

输入描述:
第一行两个数n,m

第二行n个数表示ai

第三行n个数表示bi

输出描述:
输出一行一个数表示答案

示例1
输入
5 10
0 1 3 6 8
0 4 5 6 6

输出
23

说明
样例解释：
跑：1,0,3
吃：6,5,6
额外：10

备注:
对于100%的数据，有1 <= n <= 1000000 , 0<=ai,bi,m<=2000000000

解题思路：
对ai升序排序，对bi降序排序，然后计算sum{ 1<=i<=n | bi - ai } + i/3*m的最大值。 

*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
typedef long long LL;

LL a[maxn], b[maxn];


int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);

    sort(a+1, a+n+1);
    sort(b+1, b+n+1, greater<int>());

    LL sum=0, i=1, ans=0;
    for(int k=0; i<=n; ++i)
    {
        sum += b[i] - a[i];
        if( ++k == 3)
        {
            sum += m;
            k = 0;
        }
        if(sum > ans) ans = sum;
        if(sum < 0) break;
    }
    
    cout<<ans<<endl;

    return 0;
}
