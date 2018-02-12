/*
链接：https://www.nowcoder.net/acm/contest/76/B
来源：牛客网
随着如今社会的不断变化，交通问题也变得越来越重要，所以市长决定建设一些公路来方便各
个城市之间的贸易和交易。虽然市长的想法很好，但是他也遇到了一般人也经常头疼的问题，
那就是手头的经费有限……在规划过程中，设计师们已经预算出部分城市之间建设公路的经费
需求。现在市长想知道，它能不能将他的m个城市在有限的经费内实现公路交通。如果可以的话，
输出Yes，否则输出No（两个城市不一定要直接的公路相连，间接公路到达也可以。）

输入描述:
测试输入包含多条测试数据
每个测试数据的第1行分别给出可用的经费c(<1000000)，道路数目n(n<10000)，以及城市数目m(<100)。
接下来的n行给出建立公路的成本信息，每行给出三个整数，分别是相连的两个城市v1、v2(0<v1,v2<=m)
以及建设公路所需的成本h(h<100)。

输出描述:
对每个测试用例，输出Yes或No。

示例1
输入
20 10 5
1 2 6
1 3 3
1 4 4
1 5 5
2 3 7
2 4 7
2 5 8
3 4 6
3 5 9
4 5 2

输出
Yes

示例2
输入
10 2 2
1 2 5
1 2 15

输出
Yes

备注:
两个城市之间可能存在多条线路

解题思路:
m个城市用m-1条边就可以连接起来，这m-1条边权的总和最小的边集构成的树就是该图的最小生成树。
如果最小生成树所花费的代价小于等于可用经费，则可以达到题目要求，否则无法达到题目要求。 

这里使用了kurskal（克鲁斯卡尔）的最小生成树算法：
1.取出图中所有的边用于构造生成树，首先用边权最下的边，并将该边的两个端点标记为已使用状态。
2.然后不断取出剩下的边中权值最小的边，直到访问完所有的边或者生成树构造完成。 
	1.如果加入该边之后构成的图不存在回路，即这条边的两个端点都没有被标记，则将该边加入
	  生成树中，并将该边的两个端点标记为已使用状态，同时累计已经添加到生成树中的顶点数，
	  和累计的边权总和，如果所有顶点全部都添加到生成树中了，则生成树构造完成。 
	2.如果加入该边导致图中存在回路(即两个顶点都已经在生成树中了)，则不使用该边，继续选择
	  剩下的边中权值最小的边，并进行同样的操作
*/ 
#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<cstring>
using namespace std;

int c,n,m;

struct Edge{
	int u,v,w;
	Edge(int u,int v,int w):u(u),v(v),w(w){}
	bool operator>(const Edge& e)const{return w > e.w;}
};

priority_queue<Edge,vector<Edge>, greater<Edge> > Q;

int minSpanTree(){
	int cost = 0, vcnt=0;
	bool s[101]; //标记已经使用了的顶点。
	memset(s,0,sizeof(s));
	while(!Q.empty() && vcnt < m){
		Edge e = Q.top(); Q.pop();
		if(s[e.u] && s[e.v]) continue; //如果两个顶点都已在生成树中，则忽略该边。 
		cost += e.w;		//否则将该边加入生成树中 
//		printf("cost=%d, vcnt=%d\n",cost,vcnt);
		if(cost > c) return 0; //如果总代价已经超过了可用经费，则不能满足题目要求。 
		if(!s[e.u]) ++vcnt;
		if(!s[e.v]) ++vcnt;
		s[e.u] = s[e.v] = 1;
	}
	return vcnt == m;
}


int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int u,v,w;
	while(~scanf("%d%d%d",&c,&n,&m)){
		for(int i=0; i<n; ++i){
			scanf("%d%d%d",&u,&v,&w);
			Q.push(Edge(u,v,w));
//			Q.push(Edge(v,u,w)); 
		}
		printf("%s\n",minSpanTree()?"Yes":"No");
	}
	
	return 0;
}

