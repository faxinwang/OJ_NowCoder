/*
链接：https://www.nowcoder.net/acm/contest/76/F
来源：牛客网

题目描述 
从实验室出来后，你忽然发现你居然把自己的电脑落在了实验室里，但是实验室的老师已
经把大门锁上了。更糟的是，你没有那个老师的电话号码。你开始给你知道的所有人打电
话，询问他们有没有老师的电话，如果没有，他们也会问自己的同学来询问电话号码。那
么，你能联系到老师并且拿到电脑吗。

输入描述:
存在多组测试样例
每组样例的第一行分别是两个整数n(1<n<=50)，m(1<m<=2000)，n是在题目当中出现的人数，
其中你的序号是1号，实验室老师的序号是n。
接下来的m行，每行有两个整数x(1<=x<=n)，y(1<=y<=n)，代表x有y的电话号码。

输出描述:
对于每组测试样例，如果你最终能联系到老师，输出“Yes”，否则输出“No”。

示例1
输入
5 5              有向图模型如下： 
1 3                  2 --->5----->8
2 3                /            /  \
3 4              1-->3--->6--->7    9
2 4               \     / 
4 5                  4

输出
Yes

示例2
输入
4 3
1 2
2 3
4 1

输出
No


解题思路：
该题求是否存在从1到n的一条边，即1与n的连通性，如果连通则输出Yes，否则输出No.
除了可以用DFS，这种方法似乎更容易理解，有点类似与迪杰斯特拉最短路径算法，
就是从源点1开始不断向相邻的边进行扩展，将与1相邻的顶点放到集合s中，然后不断
扩展与之相邻的边，但因为这里是有向图，而且不是按照顶点序号顺序输入的，所以
需要全部输入后排序一下再进行扩展。 
*/

#include<iostream> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 51
using namespace std;

bool s[maxn];
//directed edge
struct DEdge{
	int beg,end;
	DEdge(int b,int e):beg(b),end(e){}
	bool operator<(const DEdge& e)const {return beg < e.beg;}
};

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n,m,x,y;
	while(~scanf("%d%d",&n,&m)){
		memset(s,0,sizeof(s));
		s[1] = 1;
		vector<DEdge> v;
		v.reserve(m);
		for(int i=0;i<m;++i){
			scanf("%d%d",&x,&y);
			v.push_back(DEdge(x,y));
		}
		sort(v.begin(),v.end());
		//从1往n扩展，将所有1可以到达的顶点放到同一个集合中,该集合将不断扩展 
		for(int i=0;i<m; ++i){
			if(s[v[i].beg]) s[v[i].end] = 1;
		}
		printf("%s\n",s[n]?"Yes":"No");
	}
	
	return 0;
}
