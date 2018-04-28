/*
链接：https://www.nowcoder.com/acm/contest/105/F
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
小明来到一个由n x m个格子组成的迷宫，有些格子是陷阱，用'#'表示，小明进入陷阱就会死亡，'.'表示没有陷阱。
小明所在的位置用'S'表示，目的地用'T'表示。

小明只能向上下左右相邻的格子移动，每移动一次花费1秒。

有q个单向传送阵，每个传送阵各有一个入口和一个出口，入口和出口都在迷宫的格子里，当走到或被传送到一个有传送阵
入口的格子时，小明可以选择是否开启传送阵。如果开启传送阵,小明就会被传送到出口对应的格子里，这个过程会花费3
秒；如果不开启传送阵，将不会发生任何事情，小明可以继续向上下左右四个方向移动。

一个格子可能既有多个入口，又有多个出口，小明可以选择任意一个入口开启传送阵。使用传送阵是非常危险的，因为有
的传送阵的出口在陷阱里，如果小明使用这样的传送阵，那他就会死亡。也有一些传送阵的入口在陷阱里，这样的传送阵
是没有用的，因为小明不能活着进入。请告诉小明活着到达目的地的最短时间。

输入描述:
有多组数据。对于每组数据：
第一行有三个整数n,m,q(2≤ n,m≤300,0≤ q ≤ 1000)。
接下来是一个n行m列的矩阵，表示迷宫。
最后q行，每行四个整数x1,y1,x2,y2(0≤ x1,x2< n,0≤ y1,y2< m)，表示一个传送阵的入口在x1行y1列，出口在x2行y2列。

输出描述:
如果小明能够活着到达目的地，则输出最短时间，否则输出-1。

示例1
输入
5 5 1
..S..
.....
.###.
.....
..T..
1 2 3 3
5 5 1
..S..
.....
.###.
.....
..T..
3 3 1 2
5 5 1
S.#..
..#..
###..
.....
....T
0 1 0 2
4 4 2
S#.T
.#.#
.#.#
.#.#
0 0 0 3
2 0 2 2

输出
6
8
-1
3

解题思路:
直接使用BFS()进行搜索, 由于迷宫中有一些传送门, 可能导致捷径的存在, 这种情况下需要把普通队列换成优先级队列,
结点(状态)所花费的时间越少, 其优先级越高.

在做BFS搜索的时候, 为了避免重复访问同一个结点, 经常需要使用vis辅助数组来记录已访问的结点, 对于这一题, 如果
将通过传送门访问的结点也设置为已访问, 则会导致逻辑错误(见代码中的分析).

另外, 在搜索的过程中, 我一般习惯在扩展结点时就设置结点为已访问(这样可减少结点被重复访问的次数), 并且在扩展
结点时, 就判断是否已经到达终点(这样可以更快结束搜索), 当一步一步走时, 这样是没有任何问题的, 但是当具有传送门时,
由于传送门传送的距离与所花费的时间不成正比(单步前进,距离与时间成正比), 如果通过传送门到达终点, 则不可以立即结束
搜索, 因为可能通过单步到达终点所花费的时间更短,例如, 从传送门的入口处到传送到终点需要3秒的时间, 而单步行走可能
只需要2秒的时间.

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 305;

struct Node
{
    int x, y;
    int time; //所用时间
    Node(int x=0, int y=0, int t=0):x(x),y(y),time(t){}
    bool operator<(const Node& p)const {return time > p.time;}
};

struct Cell
{
    char ch;
    int tx,ty; //传送门出口, 没有时为-1
}maze[maxn][maxn];


int n,m,q;
int dir[4][2]={0, 1, 1,0, 0, -1, -1, 0};


int BFS(int sx, int sy)
{
    priority_queue<Node> Q;    
    Q.push(Node(sx, sy));
    maze[sx][sy].ch='#';
    while(!Q.empty())
    {
        Node p = Q.top(); Q.pop();
        if(maze[p.x][p.y].ch == 'T') return p.time;

        //往上下左右四个方向移动
        int tx,ty;
        for(int i=0; i<4; ++i)
        {
            tx = p.x + dir[i][0];
            ty = p.y + dir[i][1];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || maze[tx][ty].ch =='#' ) continue; //越界检查
            Q.push(Node(tx, ty, p.time + 1));
            if(maze[tx][ty].ch == 'T') return p.time + 1; //如果下一步就是终点, 可直接返回.
            if(maze[tx][ty].ch != 'T') maze[tx][ty].ch='#';//走过的点不重复走
        }
       
        //进入传送门
        tx = maze[p.x][p.y].tx;
        ty = maze[p.x][p.y].ty;
        if(tx < 0 || tx >= n || ty < 0 || ty >= m || maze[tx][ty].ch =='#') continue; //越界检查
        Q.push(Node(tx, ty, p.time+3)); //传送需要3秒

        //这句加上会导致逻辑错误, 如果当前点距离终点只有两秒的距离, 则通过传送门到达终点比直接走到终点要慢1秒.
        // if(maze[tx][ty].ch == 'T') return p.time+3; 
        /*
        对于此例, 正确答案为8, 
        if(maze[tx][ty].ch == 'T') return p.time+3; 
        加上这句会导致输出为9.
        6 6 3
        ..S...
        ......
        .###..
        ......
        ......
        .....T
        3 5 5 5
        4 4 5 5
        5 3 5 5
        */

        
        // 下面这句在这里会导致逻辑错误.
        // if(maze[tx][ty].ch != 'T') maze[tx][ty].ch='#'; 
        /*
        开始的时候在传送门走过的地方加上了下面这句:
        if(maze[tx][ty].ch != 'T') maze[tx][ty].ch='#';
        这句会导致逻辑错误, 例如对下图, 当从(0,0)传送到(2,0)时,如果有这句话, 则到达(2,0)的时间为3秒,
        而如果不加这句话,则可以单步走到(2,0),时间为2秒. 正确答案为9, 加上这句导致输出变为10.
        4 4 1
        S#.T
        .#.#
        .#.#
        ...#
        0 0 2 0
        */
    }
    return -1;
}


int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    
    int x,y, sx, sy;
    char line[maxn];
    while(scanf("%d%d%d", &n, &m, &q)!= -1)
    // while(cin>>n>>m>>q)
    {
        memset(maze, -1, sizeof(maze));
        for(int i=0; i<n; ++i)
        {
            scanf("%s", line);
            for(int j=0; j<m; ++j)
            {
                maze[i][j].ch = line[j];
                if(line[j] == 'S'){ sx = i, sy = j; }
            }
        }

        for(int i=0; i<q; ++i)
        {
            scanf("%d%d", &x, &y);
            scanf("%d%d", &maze[x][y].tx, &maze[x][y].ty);
        }
        printf("%d\n", BFS( sx, sy ));
    }

    return 0;
}


/*

5 5 2
..S..
.....
.###.
....#
..T..
0 2 2 4
0 0 4 4

6 6 3
..S...
......
.###..
......
......
.....T
3 5 5 5
4 4 5 5
5 3 5 5

5 5 1
S.#..
..#..
###..
.....
....T
0 1 0 2

4 4 2
S#.T
.#.#
.#.#
...#
0 0 3 0
3 0 3 3

ans:
7
8
-1
9

*/