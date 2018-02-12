/*
https://www.nowcoder.net/question/next?pid=4111169&qid=76264&tid=13490337
��һ��N*N��������Ѱ�����кᣬ�������ϵ����£����ϵ����£����ַ����ֱ������D�����ֵĺ���������ֵ
��������:
ÿ�������������1��������������һ�а����������� N �� D:
3 <= N <= 100
1 <= D <= N
��������N�У�ÿ��N������d:
0 <= d <= 100

�������:
���һ����������ʾ�ҵ��ĺ͵����ֵ

��������1:
4 2
87 98 79 61
10 27 95 70
20 64 73 29
71 65 15 0

�������1:
193
*/
#include<iostream> 
#include<cstdio> 
#include<cstring>
#define maxn 105
using namespace std;

int a[maxn][maxn];
int s[maxn][maxn];
int ans=0;

//�����ĸ������ϵ�ǰ׺�ͣ���ĳ�����������ָ����ﵽd��ʱ���ҳ�����
//d�����ֵĺ͵����ֵ 
void dp(int n,int d){
	//����ÿһ�д����ҵ�ǰ׺�� 
	for(int i=0;i<n;++i){
		for(int j=0;j<n; ++j){
			if(j==0){
				s[i][j] = a[i][j];
			}else{
				s[i][j] = s[i][j-1] + a[i][j];
				if(j==d-1) ans = max(ans, s[i][j]);
				else if(j>=d) ans = max(ans, s[i][j] - s[i][j-d]);
			}
		}
	}
	//����ÿһ�д��ϵ��µ�ǰ׺�� 
	memset(s,0,sizeof(s));
	for(int j=0; j<n; ++j){
		for(int i=0; i<n; ++i){
			if(i==0){
				s[i][j] = a[i][j];
			}else{
				s[i][j] = s[i-1][j] + a[i][j];
				if(i==d-1) ans = max(ans, s[i][j]);
				else if(i>=d) ans = max(ans, s[i][j] - s[i-d][j]);
			}
		}
	}
	//��������Ͻǵ����½ǵ�ǰ׺�� 
	memset(s,0,sizeof(s));
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(i==0 || j==0) s[i][j] = a[i][j];
			else s[i][j] = s[i-1][j-1] + a[i][j];
			if(i==d-1 || j==d-1) ans = max(ans, s[i][j]);
			else if(i>=d && j>=d) ans = max(ans, s[i][j] -  s[i-d][j-d]);
		}
	}
	//��������Ͻǵ����½ǵ�ǰ׺�� 
	memset(s,0,sizeof(s));
	for(int i=0; i<n; ++i){
		for(int j=n-1;j>=0; --j){
			if(i==0 || j==n-1) s[i][j] = a[i][j];
			else s[i][j] = s[i-1][j+1] + a[i][j];
			
			if(i==d-1 || j==n-d) ans = max(ans, s[i][j]);
			else if(i>=d && j<n-d) ans = max(ans, s[i][j] - s[i-d][j+d]);
		}
	}
}


int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int N,D;
	scanf("%d%d",&N,&D);
	for(int i=0;i<N;++i){
		for(int j=0;j <N; ++j){
			scanf("%d",&a[i][j]);
		} 
	}
	dp(N,D);
	printf("%d\n",ans);
	
	return 0;
}
