/*
链接：https://www.nowcoder.com/acm/contest/118/F
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述 

《扫雷》是一款大众类的益智小游戏，于1992年发行。游戏目标是在最短的时间内根据点击格子出现的数字找出所有非雷格子，
同时避免踩雷，踩到一个雷即全盘皆输。当某个位置为数字的时，代表它周围的八连通区域中有对应数量的雷。
kirai获取了简化版扫雷（没有标记雷的小旗）的后台数据（后台数据包括所有数字和雷的位置），转换为一个n*m(1≤n, m≤500)
的矩阵并对格子类型做了如下标记：
雷被标记为'*'；
点开的空白区域标记为'0'；
未点开的空白区域标记为'.'；
数字1~8代表周围有多少雷；
kirai非常笨，他希望你帮他完成这样的任务：
给定k(1≤k≤min(可扫位置数, 10))个位置坐标和扫雷游戏的后台数据，输出点开指定位置序列后游戏的结果，初始时游戏中没有点开任何位置。
注：数据保证扫雷过程中不会重复点击已扫位置。


输入描述:
输入样例有多组，全部是正整数。首先输入样例组数T(T≤10)。
接下来输入T组数，每组数据第一行包括四个正整数n,m,k(1≤n, m≤500, 1≤k≤min(可扫位置数, 10))分别表示地图的行、列数和即将
点开的位置数。紧接着是一个n*m的矩阵，代表扫雷的后台数据,。
矩阵后是k个整数对xi, yi(1≤i≤k, 1≤xi≤n, 1≤yi≤m)，表示依次点开的位置。

输出描述:
如果某一步踩到雷，输出"Game over in step x"（不包括引号"，表示第x步踩中雷）；未踩到雷则根据扫雷的游戏规则更新，
并输出最后一步结束后显示给kirai的矩阵。

示例1
输入
1
5 5 3
2*11*
*2111
22...
*1...
11...
1 1
3 3
1 2

输出
Game over in step 3

说明
2....
.....
.....
.....
.....

2....
.2111
.2000
.1000
.1000

Game over in step 3

解题思路:
主要麻烦的地方在于用BFS消去某个空白块周围的所有相邻空白块并把周边的数字显示出来.
注意是往八个方向扩展,不是四个方向.

*/


#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 505;

int n,m,k;
char back[maxn][maxn], tab[maxn][maxn];
int dir[8][2] = {0, 1,  1,0,   0 ,-1,   -1, 0,   1,1,   1,-1,   -1,1,   -1,-1 };

struct Point
{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
};

bool check(int x, int y){ return tab[x][y]=='.' && 0<=x && x<n && 0<=y && y<m;}

void BFS(int sx, int sy)
{
    queue<Point> Q;
    Q.push(Point(sx,sy));
    tab[sx][sy] = '0';
    while(!Q.empty())
    {
        Point p = Q.front(); Q.pop();
        for(int i=0; i<8; ++i)
        {
            int nx = p.x + dir[i][0];
            int ny = p.y + dir[i][1];
            if(!check(nx, ny)) continue;
            if(back[nx][ny] == '.')
            {
                tab[nx][ny] = '0';
                Q.push(Point(nx,ny));
            }
            else tab[nx][ny] = back[nx][ny];
            
        }
    }
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r", stdin);
    #endif

    int T,x,y;
    scanf("%d",&T);
    while(T--)
    {
        memset(tab,'.', sizeof(tab)); //初始化棋盘
        scanf("%d%d%d",&n, &m, &k);
        for(int i=0; i<n; ++i)
        {
            scanf("%s", back[i]);
            tab[i][m] = 0; //添加串结束符
        }
          
        
        bool boom = false;
        for(int i=1; i<=k; ++i)
        {
            scanf("%d%d", &x,&y);
            --x,--y;
            if(boom) continue;
            if(back[x][y] == '*')
            {
                boom = true;
                printf("Game over in step %d\n", i);
            }
            else if(back[x][y] =='.') BFS(x,y); //显示该点周围的空白点和周边的数字
            else tab[x][y] = back[x][y];
        }

        //输出k步后游戏的局面
        if(!boom) for(int i=0; i<n; ++i) printf("%s\n", tab[i]);
    }

    return 0;
}