/*
链接：https://www.nowcoder.com/acm/contest/112/B
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
有n个队伍，每个队伍的人数小于等于5，每辆车最多坐5个人，要求一个队伍的人都在一辆车上，求最少的车数

输入描述:
第一行n
第二行n个数，表示每个队伍的人数

输出描述:
输出最少车数

示例1
输入
3
3 4 5

输出
3

备注:
n≤1e5
每个数小于等于5

解题思路:
先考虑人数多的队伍, 最后考虑人数少的队伍.
为人数多的队伍安排车辆时, 捎带尽量多的人数少的队伍.
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long LL;

int a[6];

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    int n,x;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&x);
        ++a[x];
    }
    
    int ans=a[5], t; //带走5需要a[5]辆车
    //a[4] 带走一部分a[1]
    t = min(a[4], a[1]);
    ans += t; a[4] -= t; a[1] -= t;
    //剩下的4 需要a[4]辆车
    ans += a[4];

    //a[3]带走一个部分a[2]
    t  = min(a[3], a[2]);
    ans += t; a[3] -= t; a[2] -= t;
    //如果a[3]还有剩余, 再带走一部分a[1]
    if(a[3])
    {
        ans += a[3]; //剩下的3,需要a[3]辆车.
        a[1] -= a[3]*2; //一个a[3]都在两个a[1]
    }
    
    //连个a[2]一组, 需要t=a[2]/2辆车, 顺便带走t个a[1]
    t = a[2]/2;
    ans += t;
    a[2] = a[2] % 2;
    a[1] -= t;
    //如果还单下了一个a[2], 则一个a[2]和三个a[1]凑一辆车
    if(a[2]) a[1] -= 3, ans+=1;
    
    //计算剩下的a[1]需要的车
    if(a[1] < 0) a[1] = 0;
    ans += a[1]/5 + (a[1] % 5? 1 : 0);

    printf("%d\n", ans);

    return 0;
}