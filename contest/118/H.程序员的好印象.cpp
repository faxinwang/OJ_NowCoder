/*
链接：https://www.nowcoder.com/acm/contest/118/H
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述 

有一个程序员做过 n 个项目，他想要跳槽，因此他想要给面试官留下一个好印象。于是他想使自己看起来很有潜力也相应的会有竞争力，
于是他决定从自己以前做过的N个成功或者失败的项目里不改变原来的时间顺序从中选择若干个项目，使得他展示出来的任意一个成功的
项目之后都不会有一个失败的项目。这样一来，能够表现出他十足的潜力：尽管一开始做项目会失败，但一旦学会之后就不会再失败。
具体的来说，给定一个含 n 个数字的“01”序列，如一个含5个数字的“01”序列：0 0 0 0 1，其中0代表失败的项目，1代表成功的项目。
即第一个0代表第一个失败的项目，第二个0代表第二个失败的项目......最后一个1代表第五个成功的项目。于是如果这个程序员将选取
一个原序列的一个子序列 0 0 0 0，满足上面他的要求：任意的数字1之后都没有数字0出现。程序员的目的是为了在满足上面的要求的
条件下尽可能的展示最多的项目，请帮他算最多能展示多少个项目。

输入描述:
每组样例第一行为一个整数n，1<=n<=100,第二行为n项的01序列，每一项之间用一个空格隔开。

输出描述:
输出一个正整数，表示最多能展示的项目个数。


示例1
输入
4
1 1 0 1
6
0 1 0 0 1 0
1
0


输出
3
4
1

解题思路:
最长不下降子序列.

*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 105;

int a[maxn], d[maxn];

int dp(int n)
{
    int ans = 1;
    d[0] = 1;
    for(int i=1; i<n; ++i)
    {
        int M=0;
        for(int j=0; j<i; ++j)
        {
            if(a[j] <= a[i] && d[j] > M) M = d[j];
        }
        d[i] = M + 1;
        if( d[i] > ans ) ans = d[i];
    }
    return ans;
}

int main()
{
    #ifdef WFX
    freopen("in.txt", "r", stdin);
    #endif
    int n;
    while(~scanf("%d", &n))
    {
        memset(d, 0, sizeof(d));
        for(int i=0; i<n; ++i) scanf("%d", &a[i]);
        printf("%d\n", dp(n));
    }

    return 0;
}