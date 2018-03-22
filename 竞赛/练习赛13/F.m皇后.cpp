/*
链接：https://www.nowcoder.com/acm/contest/70/F
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 262144K，其他语言524288K
64bit IO Format: %lld

题目描述 
在一个n*n的国际象棋棋盘上有m个皇后。
一个皇后可以攻击其他八个方向的皇后（上、下、左、右、左上、右上、左下、右下）。
对于某个皇后，如果某一个方向上有其他皇后，那么这个方向对她就是不安全的。
对于每个皇后，我们都能知道她在几个方向上是不安全的。

现在我们想要求出t0,t1,...,t8，其中ti表示恰有i个方向是"不安全的"的皇后有多少个。

输入描述:
第一行两个整数n，m表示棋盘大小和皇后数量。
接下来m行每行两个整数ri，ci表示皇后坐标。
1 <= n, m <= 100,000
1 <= ri, ci <= n
数据保证没有皇后在同一个位置上。

输出描述:
一行九个整数表示答案。
空格隔开，结尾无空格

示例1
输入
8 4
4 3
4 8
6 5
1 6

输出
0 3 0 1 0 0 0 0 0

示例2
输入
10 3
1 1
1 2
1 3

输出
0 2 1 0 0 0 0 0 0

解题思路：
如果逐个计算每个皇后有几个方向是不安全的，则在每个皇后上需要消耗O(N)的时间，
总的时间复杂度为O(N^2), 而N最大可达1e5的量级，所以这个时间复杂度会超时。

下面说一下我的做法：
因为每个都处在某一个行，列，左线线，右斜线四条线上，而且每个黄后在这四条线上都有相应的
位置, 那么对于每个皇后，我们只需要看它在这四条线上是处于中间位置还是在首尾位置，如果在
中间位置，则该皇后在这条线上就会有两个方向不安全，如果在首尾位置，则该皇后在这条线上只有
一个方向不安全。 
最后就能统计出所有皇后不安全方向的个数。这里主要耗时的地方在于排序，因为我这里用的是vector,
所以需要按照皇后在每条线上的位置，对每条线分别排序。总共需要的排序时间是4*NLog(N),
所以时间复杂度为 O(NLogN) 
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn =  100005;
const int maxm =  100005;

struct Queen
{
    int order, id;
    Queen(int o, int id):order(o),id(id){}
    bool operator<(const Queen& q)const { return order < q.order; }
};

vector<Queen> row[maxn];
vector<Queen> col[maxn];
vector<Queen> L[maxn*2];
vector<Queen> R[maxn*2];
int cnt[maxm], T[10];

void process(vector<Queen>& v)
{
    if(v.size()<=1) return;
    sort(v.begin(), v.end());
    int last = v.size()-1;
    for(int i=1; i<last; ++i) cnt[v[i].id] += 2;
    ++cnt[v[0].id];
    ++cnt[v[last].id];
}

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int N,M, x,y;
    scanf("%d%d",&N,&M);
    for(int i=1; i<=M; ++i)
    {
        scanf("%d%d",&x,&y); 
        row[x].push_back(Queen(y, i));
        col[y].push_back(Queen(x, i));
        L[x+y].push_back(Queen(y, i));
        R[N-x+y].push_back(Queen(y,i));
    }

    for(int i=1,n=N*2; i<=n; ++i)
    {
        if(i<=N)
        {
            process(row[i]);
            process(col[i]);
        }
        process(L[i]);
        process(R[i]);
    }

    for(int i=1; i<=M; ++i) ++T[cnt[i]];
    for(int i=0; i<=7; ++i) printf("%d ",T[i]);
    printf("%d",T[8]);
    
    return 0;
}
