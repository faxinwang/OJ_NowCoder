/*
链接：https://www.nowcoder.com/acm/contest/112/C
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
约瑟夫问题(https://baike.baidu.com/item/约瑟夫问题)，n个人，1 2报数 1出队
( 就是体育课的时候1 2报数 1出队，2留下)，q次询问，每次求第x个人是第几个出队的

输入描述:
第一行两个数n,q
接下来q行，每行一个数x，表示询问

输出描述:
一行输出一个询问的答案

示例1
输入
4 3
2
3
4

输出
3
2
4

说明
1 2 3 4围成一圈，第一轮：1 2报数，1出队，2留下，3出队，4留下，第二轮，2出队，4留下

备注:
q≤500000
n和x≤1e18

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;


int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    LL n,q,x;
    scanf("%lld%lld",&n,&q);
    for(int i=0; i<q; ++i)
    {
        scanf("%lld",&x);
        while(x % 2 == 0) x += n - (x>>1);
        printf("%lld\n",(x+1)>>1);
    }

    return 0;
}