/*
链接：https://www.nowcoder.com/acm/contest/79/A
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
Special Judge, 64bit IO Format: %lld
题目描述 
银行的定期存款一般有1年期、2年期、3年期、5年期四种。
现在我们有1块钱，我们想知道，通过合理安排存款方式，n年以后这1块钱最多会变成几块钱。
假设在这n年里利率不变，且n年以后这笔钱不能处于2年期、3年期、5年期存款年限的中间（否则会变成活期）。

输入描述:
第一行五个数n, r1, r2, r3, r5分别表示年数，1年期年利率，2年期年利率，3年期年利率和5年期年利率。
假设我们有1块钱，i年期存款到期后这1块钱会变成（1 + ri)^i块钱。
1 <= n <= 20 且 n为整数，
0.04 <= r1 <= r2 <= r3 <= r5 <= 0.05;

输出描述:
一行一个数表示答案。保留5位小数(绝对误差或相对误差在1e-5之内的结果均判断为通过)。

示例1
输入
8 0.0430 0.0449 0.0458 0.0473

输出
1.44112

解题思路：
用d[i]表示i年后的本金利息和的最大值。设本金为a,则d[0] = a, d[1] = d[0] * (1+r1)
假设d[0] 到d[i-1]都已经求出，则 d[i]可以以d[i-1], d[i-2], d[i-3], d[i-5]为
本金分别存1,2,3,5年获得, 所以d[i]应该取从这四种方式中获得的最大值。
 
*/

#include<bits/stdc++.h>
using namespace std;

double d[25];
double r1,r2,r3,r5;

double dp(int n)
{
    d[0] = 1;
    for(int i=1; i<=n; ++i)
    {
        d[i] = d[i-1] * (1+r1);
        if(i >= 2) d[i] = max(d[i], d[i-2] * pow((1+r2),2));
        if(i >= 3) d[i] = max(d[i], d[i-3] * pow((1+r3),3));
        if(i >= 5) d[i] = max(d[i], d[i-5] * pow((1+r5),5));
    }
    return d[n];
}

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n;
    cin>>n>>r1>>r2>>r3>>r5;
    cout<<dp(n)<<endl;
    
    return 0;
}
