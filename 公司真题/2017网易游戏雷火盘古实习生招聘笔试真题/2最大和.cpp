/*
https://www.nowcoder.net/question/next?pid=4111169&qid=76264&tid=13490337
在一个N*N的数组中寻找所有横，竖，左上到右下，右上到左下，四种方向的直线连续D个数字的和里面最大的值
输入描述:
每个测试输入包含1个测试用例，第一行包括两个整数 N 和 D:
3 <= N <= 100
1 <= D <= N
接下来有N行，每行N个数字d:
0 <= d <= 100

输出描述:
输出一个整数，表示找到的和的最大值

输入例子1:
4 2
87 98 79 61
10 27 95 70
20 64 73 29
71 65 15 0

输出例子1:
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

//计算四个方向上的前缀和，当某个方向上数字个数达到d个时，找出连续
//d个数字的和的最大值 
void dp(int n,int d){
	//计算每一行从左到右的前缀和 
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
	//计算每一列从上到下的前缀和 
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
	//计算从左上角到右下角的前缀和 
	memset(s,0,sizeof(s));
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(i==0 || j==0) s[i][j] = a[i][j];
			else s[i][j] = s[i-1][j-1] + a[i][j];
			if(i==d-1 || j==d-1) ans = max(ans, s[i][j]);
			else if(i>=d && j>=d) ans = max(ans, s[i][j] -  s[i-d][j-d]);
		}
	}
	//计算从右上角到左下角的前缀和 
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
