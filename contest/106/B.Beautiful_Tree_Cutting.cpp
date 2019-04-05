/*
链接：https://www.nowcoder.com/acm/contest/106/B
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述 

It’s universally acknowledged that there’re innumerable trees in the campus of HUST.
One day Xiao Ming is walking on a straight road and sees many trees line up in the right side. 
Heights of each tree which is denoted by a non-negative integer from 0 to 9 can form a tree string. 
It's very surprising to find that the tree string can be represent as an initial string repeating 
K times. Now he wants to remove some trees to make the rest of the tree string looks beautiful. A 
string is beautiful if and only if the integer it represents is divisible by five. Now he wonders 
how many ways there are that he could make it.

Note that when we transfer the string to a integer, we ignore the leading zeros. For example, the 
string “00055” will be seen as 55. And also pay attention that two ways are considered different 
if the removed trees are different. The result can be very large, so printing the answer (mod 1000000007) 
is enough. And additionally, Xiao Ming can't cut down all trees.

输入描述:
The first line contains a single integer K, which indicates that the tree string is the initial string 
repeating K times.
The second line is the initial string S.

输出描述:
A single integer, the number of ways to remove trees mod 1000000007.

示例1
输入
1
100

输出
6

说明
Initially, the sequence is ‘100’. There are
6 ways:
100
1_0
10_
_00
__0
_0_

示例2
输入
3
125390

输出
149796

题目大意:
给定一串长度为n数字串s, 把它重复k次之后得到一个长度为n*k的新的数字串.
可以删除其中的一些数字, 使剩下的数字表示的整数可以被5整除. 问有多少种删除数字的方法.
可以删除0 ~ n*k-1个数字.

解题思路:
能被5整除的数字, 其末尾只能是0或者5, 所以0或者5后面的数字一定要被删除.
所以我们从低位数往高位数扫描, 遇到0或者5时, 后面的数字是一定要删除掉的, 设该0或5前面有p个数字,
那么删除数字的方法数就是 2^p(每一位最后或者被保留或者没有被保留),又由于该字符串重复了k次, 所以前面还有
k-1个循环节, 所以该0或5和其前面k-1个循环节中相同位置的数字总共具有的删数方案数目为:

2^p + 2^(n+p) + 2^(2n+p) + ... + 2^((k-1)n) + p)

提出一个2^p得到:
2^p * [ 1 +  2^n + 2^(2n) + ... + 2^((k-1)n) ]
中括号中是一个等比数列, 首项为1, 公比为2^n, 项数为k, 所以结果等于:
2^p * [ (1 - 2^nk) / (1-2^n) ]

由于中括号中的值在计算中会重复使用, 所以我们先把它计算出来保存在变量中,
tmp = (1 - 2^nk) / (1-2^n)
好了, 现在问题来了, 由于 (1 - 2^nk) 不一定能整除(1-2^n), 如果直接除肯定会导致计算误差, 所以重点来了.
这里我们需要使用乘法逆元. 即当 a / b % p 时, 为了整除计算带来的误差, 我们可以改写为 a * inv(b) % p, 
其中inv(b) 表示b在模p意义下的乘法逆元, 并且当p为质数时 有 inv(i) = i^(p-2) % p.

前面只是对s中从右往左找到的第一个0或者5和其前面k-1个循环节中相同位置的数字进行了计算, s中可能还有其他的
0或5, 也需要做相同的计算并累加起来才能得到最终结果. 

乘法逆元:
https://blog.csdn.net/sdfzchy/article/details/76098066
https://www.cnblogs.com/dupengcheng/p/5487362.html

*/

#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

//return a ^ x % mod
LL qpow(LL a, LL x, LL mod)
{
    LL ans=1, tmp=a;
    while(x)
    {
        if(x & 1) ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        x >>= 1;
    }
    return ans;
}

//求a在模mod意义下的的乘法逆元
LL inv(LL a, LL mod)
{
    //这里mod=1000000007，是质数，因此可以使用公式 inv(i) = i^(p-2) % p.
    return qpow(a, mod-2, mod);
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif

    LL k , ans=0;
    string s;
    cin>>k>>s;

    int n = s.size();
    LL ks = qpow(2, k*n, MOD);
    LL ss = qpow(2, n, MOD);
    LL tmp = (ks-1) * inv(ss-1, MOD) % MOD; //除以一个数等于乘以该数的逆元

    for(int i=n-1; i>=0; --i)
    {
        if(s[i] == '0' || s[i] == '5')
        {
            ans = (ans + qpow(2, i, MOD) * tmp % MOD) % MOD;
        }
    }

    cout<<ans<<endl;
    return 0;
}