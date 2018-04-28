/*
链接：https://www.nowcoder.com/acm/contest/105/A
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
某个实验需要统计时间，记录了实验开始和结束的时间，计算实验用了多少秒。 

输入描述:
第一行输入一个整数n，表示样例个数。接下来每组样例两行，表示开始时间和结束时间，格式为xdayHH:MM:SS，
x是一个整数表示第几天，0 < x < 20000，HH表示小时，MM表示分钟，SS表示秒，保证时间合法，结束时间比开始时间晚。

输出描述:
每组数据输出一行一个整数，表示经过的秒数。

示例1
输入
2
1day03:26:12
1day04:26:12
123day15:00:01
19999day15:00:00

输出
3600
1717286399

解题思路:
题目很简单, 将两个时间都化成秒,然后相减即可.
*/

#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;

LL getSecond(LL x, LL HH, LL MM, LL SS)
{
    return x*24*3600 + HH * 3600 + MM * 60 + SS;
}

int main()
{
    #ifdef WFX
    freopen("in.txt", "r", stdin);
    #endif

    LL T,x, HH,MM,SS;
    scanf("%lld",&T);
    while(T--)
    {
        LL tmp = 0;
        scanf("%lldday%lld:%lld:%lld", &x,&HH,&MM,&SS);
        tmp = getSecond(x, HH, MM, SS);
        scanf("%lldday%lld:%lld:%lld", &x,&HH,&MM,&SS);
        printf("%lld\n", getSecond(x, HH, MM ,SS) - tmp);
    }


    return 0;
}