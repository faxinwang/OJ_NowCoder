/*
���ӣ�https://www.nowcoder.net/acm/contest/76/E
��Դ��ţ����

��Ŀ���� 
��ս��ʱ�ڣ�A���ɳ������������������ȥ�ռ��鱨����Ϊ�����Ҫ�����Լ�����ݣ�
��������֮��ֻ�ǵ�����ϵ�����ԣ�ĳ�����ֻ�ܵ�����ϵ��һ���ֵļ����ͬʱ�����
Ҳ��֪��������ϵ����˭��
HA�Ǽ���ǵ��ϴ󣬵���Ҳֻ����ϵ�����ֵļ����HA������һ�������и������еļ����
HA��Ҫ֪��������Ҫ���߶��ٸ�������ϵ�ϵļ������֪ͨ�����еļ����

��������:
�ж���������ݡ�
����ÿ���������ݣ�
��һ��Ϊһ������n��m��0<n,m<=500����������������HA��֪ͨ���ļ��������������ı��Ϊ1-n����
�ڶ���Ϊm���ÿո����������xi,����HA��֪ͨ���ļ���ı�ţ�
�����е���n+2�У�ÿһ�е�һ������ai(0<=ai<n)��ʾ��i-2������ܵ�����ϵ���ļ������֮����ai��
�ÿո��������������ʾ���i-2�ܵ�����ϵ���ļ���ı�š�

�������:
���һ�У���������һ������������HA������Ҫ��ϵ�ļ���������HA����֪ͨ�����м�������-1��

ʾ��1
����
3 2
1 2
1 2
1 1
0

���
-1

ʾ��2
����
3 1
1
2 2 3
0
0

���
1

����˼·�� 
����Ϊ�Ӹ�������ͼ�����Ϊ0�Ķ��㿪ʼ������ͼ�е����ж��㣬
�����������Ҫ������֮���ڵĶ���ĸ���, ����Ϊ���Ӧ����
������֮���ڵĵ��������С�ĵ㣬��Ϊ��Ƚϴ�ĵ���ܻ�ͨ��
��Ƚ�С�ĵ���ʵ���������ڶ���ͼӦ�ȴ�a�㿪ʼ���ʣ���Ϊͨ
��a����Է��ʵ�b�㣬����b����ʲ���a�㡣����ʹ��BFS����DFS��
ע��ͼ�п��ܴ��ڻ��� 

9 2
1 5       ����ͼģ������ͼ(�Բ�б���ϵļ�ͷ)��
1 2
1 3                  S 
1 4                /   \
1 1              a      d
1 6			   /  \    / \
1 7	          b--->c  e-->f
1 8       abc���ɻ�   def���ɻ� 
1 9
1 5
Ӧ���2 

9 2
1 9      ����ͼģ������ͼ(�Բ�б���ϵļ�ͷ):
1 2                   S    
1 3                 /   \
1 4                b<----a
1 5               /
1 6              c
1 7             /
1 8            d
0
1 1
Ӧ���1(����a����ʼ����,�����B��,����Ϊ2)

*/ 
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> g[501]; //�����ӱ���ͼ 
int in[501];
bool vis[501];
int n,m,x,u,v;

bool cmp(int a,int b){
	return in[a] < in[b];
}

int BFS(){
	vector<int>& v = g[0];
	sort(v.begin(),v.end(),cmp); //��������������ȴ����С�ĵ㿪ʼ���ʡ� 
	queue<int> Q;
	set<int> s;
	int cnt = 0;
	for(int i=0; i<v.size(); ++i){
		if(vis[v[i]]) continue;
		++cnt;
		//֪ͨ��v[i]���� 
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
