/*
链接：https://www.nowcoder.com/acm/contest/105/E
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
作为一个标准的吃货，mostshy又打算去联建商业街觅食了。
混迹于商业街已久，mostshy已经知道了商业街的所有美食与其价格，而且他给每种美食都赋予了一个美味度，
美味度越高表示他越喜爱这种美食。
mostshy想知道，假如带t元去商业街，只能吃一种食物，能够品味到的美食的美味度最高是多少？

输入描述:
第一行是一个整数T(1 ≤ T ≤ 10)，表示样例的个数。
以后每个样例第一行是两个整数n,m(1 ≤ n,m ≤ 30000)，表示美食的种类数与查询的次数。
接下来n行，每行两个整数分别表示第i种美食的价格与美味度di,ci (1 ≤ di,ci ≤ 109)。
接下来m行，每行一个整数表示mostshy带t(1 ≤ t ≤ 109)元去商业街觅食。

输出描述:
每个查询输出一行，一个整数，表示带t元去商业街能够品味到美食的最高美味度是多少，如果不存在这样的美食，输出0。

示例1
输入
1
3 3
1 100
10 1000
1000000000 1001
9
10
1000000000

输出
100
1000
1001

解题思路:
先使用价格对所有美食排序, 然后设置fd[i].sat 为排序后前i种食物中最大的没事满意度.
然后给定钱数,就可以使用二分搜索找到对应钱数的最大满意度了.
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 30005;

struct Food
{
    int sat, price;
    bool operator<(const Food& f)const {return price < f.price;}
}fd[maxn];

int binSearch(int n, int money)
{
    int low=0, high = n, mid, ans=0;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        // printf("mid=%d price=%d sat=%d\n", mid, fd[mid].price, fd[mid].sat);
        if(fd[mid].price <= money) ans = fd[mid].sat, low = mid+1;
        else high = mid-1;
    }
    return ans;
}

int main()
{   
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    int T, n , m, money;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i=0; i<n; ++i) scanf("%d%d", &fd[i].price, &fd[i].sat);

        sort(fd, fd+n);
        
        //让fd[i].sat表示排序后前i种食物中最大的美食满意度. 之后给定钱的数量,就可以使用二分查找了.
        for(int i=1; i<n; ++i) if(fd[i].sat < fd[i-1].sat) fd[i].sat = fd[i-1].sat;

        for(int i=0; i<m; ++i)
        {
            scanf("%d",&money);
            printf("%d\n", binSearch(n-1, money));
        }
    }


    return 0;
}
