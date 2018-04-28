/*
链接：https://www.nowcoder.com/acm/contest/105/C
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
紧急事件！战场内被敌军埋放了n枚炸弹！
我军情报部门通过技术手段，掌握了这些炸弹的信息。这些炸弹很特殊，每枚炸弹的波及区域是一个矩形。第i枚炸弹的波及区
域是以点(xi1,yi1)为左下角，点(xi2,yi2)为右上角的矩形。
mostshy，作为我军的指挥官，想要知道，如果这些弹同时被敌军引爆，最多将有多少枚炸弹会波及到同一个区域（不考虑边界和角落）。


输入描述:
第一行是一个整数T(1 ≤ T ≤ 50)，表示样例的个数。
以后每个样例第一行是一个整数n(1 ≤ n ≤ 50)，表示炸弹的个数。
接下来n行，每行四个整数，第i行为xi1,yi1,xi2,yi2(0 ≤ xi1,yi1,xi2,yi2≤ 100)，输入保证合法。


输出描述:
每个样例输出一行，一个整数，表示最多将有多少枚炸弹会波及到同一个区域。

示例1
输入
1
2
0 0 50 50
40 40 100 100

输出
2


说明
在左下角为(40,40)，右上角为(50,50)的矩形区域内，有两个炸弹同时波及，所以答案为2。

解题思路:
这题数据范围小, 可以直接暴力.
但时要注意处理好边界, 方法是对于每个给定的矩形, 不处理其下边界和右边界.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[101][101];

void fill(int x1, int y1, int x2, int y2)
{
    for(int i=x1; i<=x2; ++i)
    {
        for(int j=y1; j<=y2; ++j) ++a[i][j];
    }
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    #endif
    int T,n;
    int x1,y1, x2,y2;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0, sizeof(a));
        scanf("%d",&n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d%d%d", &x1,&y1, &x2, &y2);
            fill(x1,y1, x2-1, y2-1); //不处理下边界和右边界
        }
        int ans = 0;
        for(int i=0; i<=100; ++i)
        {
            for(int j=0; j<=100; ++j)
            {
                if(a[i][j] > ans) ans = a[i][j];
                // printf("%d ",a[i][j]);
            }
            // printf("\n");
        }
        printf("%d\n",ans);
    }


    return 0;
}