/*
链接：https://www.nowcoder.net/acm/contest/76/E
来源：牛客网

题目描述 
在战争时期，A国派出了许多间谍到其他国家去收集情报。因为间谍需要隐秘自己的身份，
所以他们之间只是单向联系。所以，某个间谍只能单向联系到一部分的间谍。同时，间谍
也不知道跟他联系的是谁。
HA是间谍们的老大，但他也只能联系到部分的间谍。HA现在有一项命令有告诉所有的间谍。
HA想要知道他至少要告诉多少个他能联系上的间谍才能通知到所有的间谍。

输入描述:
有多个测试数据。
对于每个测试数据：
第一行为一个整数n，m（0<n,m<=500）代表间谍的数量和HA能通知到的间谍的数量（间谍的编号为1-n）；
第二行为m个用空格隔开的整数xi,代表HA能通知到的间谍的编号；
第三行到第n+2行，每一行第一个整数ai(0<=ai<n)表示第i-2个间谍能单向联系到的间谍数。之后有ai个
用空格隔开的整数，表示间谍i-2能单向联系到的间谍的编号。

输出描述:
输出一行，此行中有一个整数，代表HA至少需要联系的间谍数。如果HA不能通知到所有间谍，输出-1。

示例1
输入
3 2
1 2
1 2
1 1
0

输出
-1

示例2
输入
3 1
1
2 2 3
0
0

输出
1

解题思路： 
本题为从给定有向图中入度为0的顶点开始，遍历图中的所有顶点，
求起点最少需要访问与之相邻的顶点的个数, 方法为起点应优先
访问与之相邻的点中入度最小的点，因为入度较大的点可能会通过
入度较小的点访问到。如下面第二个图应先从a点开始访问，因为通
过a点可以访问到b点，但从b点访问不到a点。可以使用BFS或者DFS。
注意图中可能存在环。 

9 2
1 5       有向图模型如下图(脑补斜线上的箭头)：
1 2
1 3                  S 
1 4                /   \
1 1              a      d
1 6			   /  \    / \
1 7	          b--->c  e-->f
1 8       abc构成环   def构成环 
1 9
1 5
应输出2 

9 2
1 9      有向图模型如下图(脑补斜线上的箭头):
1 2                   S    
1 3                 /   \
1 4                b<----a
1 5               /
1 6              c
1 7             /
1 8            d
0
1 1
应输出1(即从a顶开始遍历,如果从B点,则结果为2)

*/ 
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> g[501]; //用链接表保存图 
int in[501];
bool vis[501];
int n,m,x,u,v;

bool cmp(int a,int b){
	return in[a] < in[b];
}

int BFS(){
	vector<int>& v = g[0];
	sort(v.begin(),v.end(),cmp); //根据入度排序，优先从入度小的点开始访问。 
	queue<int> Q;
	set<int> s;
	int cnt = 0;
	for(int i=0; i<v.size(); ++i){
		if(vis[v[i]]) continue;
		++cnt;
		//通知第v[i]个人 
		s.insert(v[i]);
		Q.push(v[i]);
//		printf("v[%d] =%d\n", i,v[i]);
		vis[v[i]] = 1;
		while(!Q.empty()){
			int x = Q.front(); Q.pop();
			for(int k=0,p=g[x].size(); k<p; ++k){
				if(vis[g[x][k]]) continue;
				vis[g[x][k]] = 1;
				s.insert(g[x][k]);
				Q.push(g[x][k]);
			}
			if(s.size() == n) return cnt;
		}
	}
	return -1;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<=n; ++i) g[i].clear();
		memset(vis,0,sizeof(vis));
		memset(in,0,sizeof(in));
		g[0].reserve(m);
		for(int i=0; i<m; ++i){
			scanf("%d",&x);
			g[0].push_back(x);
		}
		
		for(int i=1; i<=n; ++i){
			scanf("%d",&u);
			g[i].reserve(u);
			for(int j=0;j<u;++j){
				scanf("%d",&v);
				g[i].push_back(v);
				++in[v];
			}
		}
		printf("%d\n",BFS());
	}
	
	return 0;
}
