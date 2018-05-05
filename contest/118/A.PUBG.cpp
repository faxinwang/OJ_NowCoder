/*
链接：https://www.nowcoder.com/acm/contest/118/A
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述 

最近，喜爱ACM的PBY同学沉迷吃鸡，无法自拔，于是又来到了熟悉的ERANGEL。经过一番搜寻，PBY同学准备动身前往安全区，
但是，地图中埋伏了许多LYB，PBY的枪法很差，希望你能够帮他找到一条路线，每次只能向上、下、左、右移动，尽可能遇到较少的敌人。

输入描述:
题目包含多组测试，请处理到文件结束；
第一行是一个整数n，代表地图的大小；
接下来的n行中，每行包含n个整数a，每个数字a代表当前位置敌人的数量；
1 < n <= 100，1 <= a <= 100，-1代表当前位置，-2代表安全区。

输出描述:
对于每组测试数据，请输出从当前位置到安全区所遇到最少的敌人数量，每个输出占一行。

示例1
输入
5
6 6 0 -2 3
4 2 1 2 1
2 2 8 9 7
8 1 2 1 -1
9 7 2 1 2
输出
9

示例2
输入
5
62 33 18 -2 85
85 73 69 59 83
44 38 84 96 55
-1 11 90 34 50
19 73 45 53 95

输出
173


解题思路:
BFS + 优先级队列.
结点中累计沿路上遇到的敌人数量, 优先扩展遇到的敌人数量最低的结点.

*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 105;

int a[maxn][maxn];
bool vis[maxn][maxn];
int n;
int dir[4][2]={0,1,1,0, 0, -1, -1, 0};


struct Point
{
    int x,y;
    int cnt;
    Point(int x=0,int y=0, int cnt=0):x(x),y(y),cnt(cnt) {}
    bool operator<(const Point& p)const{ return cnt > p.cnt; }
};

bool check(int x,int y){ return !vis[x][y] && 0<=x && x<n && 0<=y && y<n; }


int BFS(int sx, int sy)
{
    priority_queue<Point> Q;
    Q.push(Point(sx,sy));
    while(!Q.empty())
    {
        Point p = Q.top(); Q.pop();
        for(int i=0; i<4; ++i)
        {
            int nx = p.x + dir[i][0];
            int ny = p.y + dir[i][1];
            if( !check(nx, ny) ) continue;
            if(a[nx][ny] == -2) return p.cnt;
            vis[nx][ny] = 1;
            Q.push(Point( nx,ny, p.cnt + a[nx][ny] ));
        }
    }
    return 0;
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif

    int sx, sy, val;
    while(~scanf("%d",&n))
    {
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                scanf("%d", &a[i][j]);
                if(a[i][j] == -1){ sx=i, sy=j; }
            }
        }
        printf("%d\n", BFS(sx, sy));
    }


    return 0;
}