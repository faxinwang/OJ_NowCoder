/*
链接：https://www.nowcoder.com/acm/contest/106/K
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
It’s universally acknowledged that there’re innumerable trees in the campus of HUST.
Now you're going to walk through a large forest. There is a path consisting of N stones winding 
its way to the other side of the forest. Between every two stones there is a distance. Let di 
indicates the distance between the stone i and i+1.Initially you stand at the first stone, and 
your target is the N-th stone. You must stand in a stone all the time, and you can stride over 
arbitrary number of stones in one step. If you stepped from the stone i to the stone j, you 
stride a span of (di+di+1+...+dj-1). But there is a limitation. You're so tired that you want 
to walk through the forest in no more than K steps. And to walk more comfortably, you have to 
minimize the distance of largest step.

输入描述:
The first line contains two integer N and K as described above.
Then the next line N-1 positive integer followed, indicating the distance between two adjacent stone.

输出描述:
An integer, the minimum distance of the largest step.

示例1
输入
6 3
1 3 2 2 5

输出
5

解题思路:
求最小的最大值, 典型的二分搜索.

*/


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+5;
typedef long long LL;

int N,K;
int d[maxn];

//计算以x为最大跳跃距离最少需要多少次跳跃.
//如果最少跳跃次数小于等于k,则返回true, 表示最大跳跃距离可以适当减小.
bool check(LL x)
{
    LL cnt=0, tmp=0;
    for(int i=1; i<N; ++i)
    {
        if(x < d[i]) return 0; //最大跳跃距离不能小于任何间距
        if(tmp >= d[i])
        {
            tmp -= d[i];
        } 
        else
        {
            tmp = x - d[i];
            ++cnt;
        }
    }
    // printf("x=%d cnt=%d\n", x,cnt);
    return cnt <= K;
}

LL binSearch()
{
    //需要注意的是, 当k=1时, 最大跳跃距离就是所有间距的和, 该值可达1e10.
    LL low=1, high = 1e10+5, mid, ans;
    while(low <= high)
    {
        mid = low + (high - low)/2;
        if( check(mid) ) ans = mid, high = mid-1;
        else low = mid+1;
    }
    return ans;
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif

    scanf("%d%d",&N, &K);
    for(int i=1; i<N; ++i) scanf("%d", &d[i]);
    printf("%lld\n", binSearch());
    
    return 0;
}