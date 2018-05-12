/*
链接：https://www.nowcoder.com/acm/contest/112/A
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
现有n组人，m个地点，给出每组人的人数，每个地点可容纳的最大人数和选择的价格
要求一种方式，使得每组人都到一个各不相同的地点，最小化选择的价格
每个队伍的人都要在同一个地方每个地方只能有一个队伍

输入描述:
第一行n,m
第二行n个数，表示每组的人数
接下来m行，每行两个数，表示可容纳的最大人数和选择的价格

输出描述:
输出最小化选择的价格，无解输出-1

示例1
输入
3 4
2 3 4
1 2
2 3
3 4
4 5

输出
12

备注:
所有数据小于1e5

解题思路:
算法思路是对价格最小的地点开始, 将当前地点分配给可以容纳的最大的队伍. 即价值最大化分配.

1.将N个队伍按人数升序排序, 用于二分查找.
2.将M个地点按价格升序排序, 用于逐个枚举
3.逐个枚举每个地点, 在队伍中二分查找可以进入该地点的最大队伍, 该队伍之前的
    所有队伍都可以分配到该地点, 从找到的最大队伍开始往前找一个没有被安排的
    队伍, 如果找到了一个没有被安排的队伍, 就将该地点分配给该队伍, 否则继续
    枚举下一个地点.
    直到所有的地点都得到了分配或枚举完所有的地点.
4.如果枚举完所有的地点还有队伍没有得到分配, 则无解.

时间复杂度: M*(logN + N)
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
typedef long long LL;

struct Place
{
    int c, p;
    Place(int c=0,int p=0):c(c),p(p){}
    bool operator<(const Place& nd)const
    {
        if( p != nd.p) return p <  nd.p;
        return c > nd.c;
    }
};

int p[maxn], vis[maxn];

int b[maxn], c[maxn]; //countSort辅助数组

int readInt() {
    int x = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') (x *= 10) += (ch - '0'), ch = getchar();
    return x;
}

// template<typename T>
void countSort(int a[], int n)
{
    int Max = a[0];
    for(int i=0; i<n; ++i)
    {
        ++b[a[i]];
        Max < a[i]? Max=a[i] : 0;
    } 
    for(int i=1; i<=Max; ++i) b[i] += b[i-1];
    for(int i=n-1; i>=0; --i)
    {
        c[ b[a[i]] - 1] = a[i];
        --b[a[i]];
    }
    memcpy(a, c, sizeof(int)*n);
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif

    int N,M;
    int people, price, maxp=0;
    vector<Place> v;
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) 
        // scanf("%d", &p[i]);
        p[i] = readInt();

    N < 1e3? sort(p, p+N) :  countSort(p, N);
    
    v.reserve(M);
    for(int i=0; i<M; ++i)
    {
        // scanf("%d%d",&people, &price);
        people = readInt();
        price = readInt();
        // scanf("%d%d", &v[i].c, &v[i].p);
        if(people < p[0]) continue;
        v.push_back(Place(people, price));
    }
    sort(v.begin(), v.end());
    // sort(v, v+M, cmp);
    
    LL ans=0, m=v.size(), cnt=0;
    for(int i=0; i<m && cnt<N; ++i)
    {
        int idx = upper_bound(p, p+N, v[i].c) - p;
        for(--idx; idx>=0; --idx)
        {
            if(vis[idx]) continue;
            vis[idx] = 1;
            ++cnt;
            ans += v[i].p;
            break;
        }
    }
    if(cnt != N) ans = -1;
    printf("%lld\n", ans);

    return 0;
}