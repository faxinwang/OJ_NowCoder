/*
链接：https://www.nowcoder.com/acm/contest/118/D
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述 

1， 2， 3在打篮球， 可是二打一总是不公平的， 于是他们决定一对一，另一个人在边上看着， 谁输了谁就和下场和在
边上看着的那个人交换。 现在给你一个胜利者的序列（每一轮胜利的人）， 问这个序列合不合法。（一开始1，2单挑， 3在下面看着）

输入描述:
第一个数是数字n(1<=n<=100), 代表输入的胜利者序列的规模， 接下来的n行描述了胜利者序列。第i行包含一个正整数a[i],
（1<=a[i]<=3），代表着a[i]赢得比赛

输出描述:
输出YES如果胜利者序列合法， 否则NO

示例1
输入
3
1
1
2
2
1
2

输出
YES
NO

说明
第一个例子中， 1赢了2， 3代替2； 1赢了3， 2代替3； 2赢了
第二个例子中， 1赢了2， 3代替2， 这时候2明显已经在场下了故不可能为胜利者

解题思路:
直接模拟.

*/
#include<iostream>
#include<cstdio>
using namespace std;


int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif

    int n, win;
    while(~scanf("%d",&n))
    {
        bool ok = true;
        int c1=1, c2=2, waitter = 3;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &win);
            if(ok == false) continue;
            if(win == c1) swap(c2, waitter);
            else if(win == c2) swap(c1, waitter);
            else ok = false;
        }
        printf("%s\n", ok?"YES":"NO");
    }
    
    return 0;
}