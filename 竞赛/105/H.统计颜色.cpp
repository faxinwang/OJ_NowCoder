/*
链接：https://www.nowcoder.com/acm/contest/105/H
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
n个桶按顺序排列，我们用1~n给桶标号。有两种操作：
1 l r c 区间[l,r]中的每个桶中都放入一个颜色为c的球 (1≤l,r ≤n,l≤r,0≤c≤60)
2 l r   查询区间[l,r]的桶中有多少种不同颜色的球     (1≤l,r ≤n,l≤r)

输入描述:
有多组数据，对于每组数据：
第一行有两个整数n,m(1≤n,m≤100000)
接下来m行，代表m个操作，格式如题目所示。

输出描述:
对于每个2号操作，输出一个整数，表示查询的结果。

示例1
输入
10 10
1 1 2 0
1 3 4 1
2 1 4
1 5 6 2
2 1 6
1 7 8 1
2 3 8
1 8 10 3
2 1 10
2 3 8

输出
2
3
2
4
3

解题思路:
使用线段树, 对于结点i表示的区间[Li,Ri], 用一个整数colors表示该区间内所有桶中颜色的总数,
这里使用了状态压缩的概念, 就是用colors中的第k个二进制位来表示区间[Li,Ri]的所有桶中是否包含
第k中颜色, 有则colors的第k位置1, 否则置0, 由于总共有61种颜色, 所以colors变量需要用长整型
来保存. 

然后是区间合并(向上更新)的问题:
其实很简单, 俩子区间按位或运算即可, 父区间中的颜色总数 = 左子区间中的颜色总数 | 右子区间中的颜色总数

然后是懒惰更新(向下更新)的问题:
用add变量保存父结点需要向子结点更新的颜色(可能有多种), 当需要向下更新时,需要做两件事情: 
1.把父结点中的add值合并到子结点的colors中, 而不是直接把父结点的colors值直接赋值给子结点.
2.把父结点的add值合并(注意不是赋值, 赋值会覆盖掉没来得及向下更新的颜色信息)到子结点的add值中去

*/
#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
const int maxn = 100005;
typedef long long LL;

struct Node
{
    int L, R;
    LL colors, add; //colors记录该区间内所有桶中颜色的总数, add记录需要向上或向下同步更新的颜色
    bool lazy_asyn;  //向下同步标记，1表示需要向下同步，0表示不需要向下同步
};

LL base[61];

struct SegTree
{
    Node a[maxn<<4];

    //获取区间中值
    int Mid(int rt){ return a[rt].L + (a[rt].R - a[rt].L ) / 2; }
    int Mid(int L, int R){ return L + (R- L)/2; }

    //建立线段树
    void build(int L, int R, int rt=1)
    {
        a[rt].L = L;
        a[rt].R = R;
        a[rt].colors = a[rt].add = 0;
        a[rt].lazy_asyn = 0;
        
        if(L == R) return ;
        int mid = Mid(L,R);
        build( L, mid, rt<<1);
        build( mid+1, R, rt<<1|1);
    }

    void push_up(int rt)
    { 
        int lc = rt<<1, rc=lc+1;
        a[rt].colors = a[lc].colors | a[rc].colors;
    }
    
    //将区间[L,R]的值修改为val.
    //向上走的时候，如果遇到了懒惰标记，要将懒惰标记向下传递，否则会出现修改错误
    //回溯的时候，要将更新的信息向上同步
    void insert(int L, int R, int val, int rt=1)
    {
        if(a[rt].L == L && a[rt].R == R)
        {
            a[rt].colors |= base[val];
            a[rt].add |= base[val];
            a[rt].lazy_asyn = 1;
            return;
        }

        if(a[rt].lazy_asyn) push_down(rt);

        int mid = Mid(rt);
        if(R <= mid) insert(L, R, val, rt<<1);
        else if(mid < L) insert(L, R, val, rt<<1|1);
        else 
        {
            insert(L, mid, val, rt<<1);
            insert(mid+1, R, val, rt<<1|1);
        }
        push_up(rt);
    }

    //向下同步更新，并将懒惰同步标记传递给左右子结点
    void push_down(int rt)
    {
        if(a[rt].L == a[rt].R) return; //已经到达叶子结点，不需要往下同步
        int lc = rt<<1, rc=lc+1;
        a[lc].add |= a[rt].add;
        a[rc].add |= a[rt].add;
        a[lc].colors |= a[rt].add;
        a[rc].colors |= a[rt].add;

        //懒惰标记向下传递
        a[rt].lazy_asyn = a[rt].add = 0;
        a[lc].lazy_asyn = a[rc].lazy_asyn = 1;
    }

    //区间查询
    LL query(int L, int R, int rt=1)
    {
        if(a[rt].L == L && a[rt].R == R) return a[rt].colors;

        if(a[rt].lazy_asyn) push_down(rt);

        int mid = Mid(rt);
        if(R <= mid) return query(L, R, rt<<1);
        else if(mid < L) return query(L, R, rt<<1|1);
        else return query(L, mid, rt<<1) | query(mid+1, R, rt<<1|1); //注意这里用'或'位运算符 | 连接, 而不是+
    }

}tree;

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    int n,m;
    int op, L, R, c;
    for(int i=0; i<=60; ++i) base[i] = (1LL << i); 

    while(scanf("%d%d",&n,&m)!=-1)
    {
        // memset(tree.a, 0 , sizeof(Node) * maxn);
        tree.build(1, n);
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d%d", &op, &L, &R);
            if(op == 1)
            {
                scanf("%d",&c);
                tree.insert(L, R, c);
            }else
            {
                LL cnt=0, colors = tree.query(L, R);
                for(int i=0; i<=60; ++i) cnt += (colors & (1LL<<i))? 1 : 0;
                printf("%lld\n", cnt);
            }
        }
    }

    return 0;
}