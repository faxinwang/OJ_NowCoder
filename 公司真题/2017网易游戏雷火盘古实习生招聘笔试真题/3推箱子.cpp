/*
https://www.nowcoder.net/question/next?pid=4111169&qid=76263&tid=13490337
大家一定玩过“推箱子”这个经典的游戏。具体规则就是在一个N*M的地图上，有1个玩家、1个箱子、
1个目的地以及若干障碍，其余是空地。玩家可以往上下左右4个方向移动，但是不能移动出地图或者
移动到障碍里去。如果往这个方向移动推到了箱子，箱子也会按这个方向移动一格，当然，箱子也不
能被推出地图或推到障碍里。当箱子被推到目的地以后，游戏目标达成。现在告诉你游戏开始是初始
的地图布局，请你求出玩家最少需要移动多少步才能够将游戏目标达成。 

输入描述:
每个测试输入包含1个测试用例
第一行输入两个数字N，M表示地图的大小。其中0<N，M<=8。
接下来有N行，每行包含M个字符表示该行地图。其中 . 表示空地、X表示玩家、*表示箱子、
#表示障碍、@表示目的地。
每个地图必定包含1个玩家、1个箱子、1个目的地。

输出描述:
输出一个数字表示玩家最少需要移动多少步才能将游戏目标达成。当无论如何达成不了的时候，输出-1。

输入例子1:
4 4
....
..*@
....
.X..
6 6
...#..
......
#*##..
..##.#
..X...
.@#...

输出例子1:
3
11


解题思路：
本题可以理解为搜索装填，即从棋盘的初始状态搜索到箱子到达目的地的状态。
每一个状态根据人的移动至多可以扩展出四个新的状态，需要根据如下规则判断
新扩展出的状态是否合法：
1.人的位置不能越界
2.人如果碰到了箱子，箱子也要移动
3.箱子的位置不能越界
4.人和箱子不能走障碍物 
由于是要求最少步数，所以使用进行BFS搜索。
*/

#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 10
using namespace std;

int N,M;
bool vis[maxn][maxn][maxn][maxn]; //vis[i][j][x][y]表示小人在i,j,箱子在x,y的状态已经访问过。
int dir[4][2]={0,1,0,-1,1,0,-1,0};
char mp[maxn][maxn];
struct Point{
	int x,y;//人的坐标 
	int bx,by; //箱子的坐标 
	int step;//步数 
	Point(int x,int y,int bx,int by,int step):x(x),y(y),bx(bx),by(by),step(step){}
};

//参数为小人的坐标和箱子的坐标
int BFS(int x,int y,int bx,int by){
	queue<Point> Q;
	Q.push(Point(x,y,bx,by,0));
	vis[x][y][bx][by] = 1;
	while(!Q.empty()){
		Point p = Q.front(); Q.pop();
		if(mp[p.bx][p.by] == '@') return p.step; //到达目的地 
		for(int i=0;i<4;++i){
			Point nxt = p;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			if(nxt.x < 0 || nxt.x>=N || nxt.y<0 || nxt.y >=M) continue; //越界 
			if(mp[nxt.x][nxt.y] == '#') continue; //人不能走障碍物 
			//如果人碰到了箱子，则箱子也要移动，然后判断该移动是否合法 
			if(nxt.x==nxt.bx && nxt.y ==nxt.by){
				nxt.bx += dir[i][0];
				nxt.by += dir[i][1];
				if(nxt.bx <0 || nxt.bx >=N || nxt.by<0 || nxt.by>=M) continue;
			}
			if(!vis[nxt.x][nxt.y][nxt.bx][nxt.by]){
				vis[nxt.x][nxt.y][nxt.bx][nxt.by] = 1;
				++nxt.step;
				Q.push(nxt);
			}
		}
	}
	return -1;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int x,y, bx,by;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>mp[i][j];
			if(mp[i][j] == 'X'){
				x=i;
				y=j;
			}
			else if(mp[i][j]=='*'){
				bx = i;
				by = j;
			}
		}
	}
	cout<<BFS(x,y,bx,by)<<endl;
	
	return 0;
}
