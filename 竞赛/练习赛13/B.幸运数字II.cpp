/*
链接：https://www.nowcoder.com/acm/contest/70/B
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 262144K，其他语言524288K
64bit IO Format: %lld

题目描述 
定义一个数字为幸运数字当且仅当它的所有数位都是4或者7。
比如说，47、744、4都是幸运数字而5、17、467都不是。
定义next(x)为大于等于x的第一个幸运数字。给定l，r，请求出next(l) + next(l + 1) + ... + next(r - 1) + next(r)。

输入描述:
两个整数l和r (1 <= l <= r <= 1000,000,000)。

输出描述:
一个数字表示答案。

示例1
输入
2 7

输出
33

示例2
输入
7 7

输出
7

解题思路
               0
             /   \
            4      7
           / \    /  \
         44  47  74  77
层序遍历这课二叉树, 会发现这是一个递增的序列，并且序列中每个数字都是幸运数字。
所以，用队列进行层序遍历，可以顺便计算出最后的答案。
*/

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long LL;

int a[3000];
int cnt = 0;

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
    LL sum = 0,L,R;
    cin>>L>>R;
    queue<LL> Q;
    Q.push(0);
    while(L <= R)
    {
        if(Q.front() < L)
        {
            LL tmp = Q.front(); Q.pop();
            Q.push(tmp * 10 + 4);
            Q.push(tmp * 10 + 7);
        }
        else
        {
            sum += Q.front();
            ++L;
        }
    }
    cout<<sum<<endl;

    return 0;
}