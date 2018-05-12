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
1.将N个队伍按人数降序排序, 优先安排人数大的队伍
2.将M个地点按可容纳人数降序排序, 优先考虑容量大的地点
3.逐个考虑排序后的每个队伍, 将所有可容纳该队伍的地点的价格放入优先级队列,
    如果优先级队列为空, 说明没有一个地点可以容纳该队伍. 直接结束算法.
    否则, 直接出队最小的价格, 表格对应的地点分配给了该队伍.
4.将步骤3重复执行N次, 直到所有队伍全部安排完毕.

时间复杂度: max{ O(NlogN), O(MlogM) }
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
typedef long long LL;

int a[maxn];

struct Place
{
    int num, val;
    bool operator<(const Place& p)const{return num > p.num;}
}p[maxn];
//存放所有能容纳当前队伍的房子的价格, 价格小的先出队
priority_queue<int, deque<int>, greater<int> > Q; 

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    int N,M;
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) scanf("%d", a+i);
    for(int j=0; j<M; ++j) scanf("%d%d", &p[j].num, &p[j].val);

    sort(a, a+N, greater<int>()); //降序排序, 先安排人数多的队伍
    sort(p, p+M); //降序排序, 先考虑容量大的房间
    int ans = 0;
    for(int i=0, j=0; i<N; ++i)
    {
        while(j<M && p[j].num >= a[i] ) Q.push( p[j].val ), ++j;
        if(Q.empty())
        {
            ans = -1;
            break;
        }
        ans += Q.top(); Q.pop();
    }
    printf("%d\n",ans);

    return 0;
}