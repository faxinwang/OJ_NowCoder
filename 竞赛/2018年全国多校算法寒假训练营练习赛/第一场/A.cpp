/*
链接：https://www.nowcoder.com/acm/contest/67/A
来源：牛客网

题目描述 
在绝地求生（吃鸡）游戏里，不同的枪支有不同的威力，更是可以搭配不同的配件，以提升枪支的性能。
每一把枪都有其威力及其可装备配件种类。每一个配件有其所属种类，可以为枪支提供威力的百分比加成。每一把枪
只能装备一个同类配件。给你n把枪支和m个配件，枪的威力为p，可装备的配件数量为k，为k个不同类型的配件，同
种类配件只可以装备一个。配件种类用数字q表示，配件威力加成用一个小数b表示。请你挑选一把枪并为其搭配配件使其威力最大。

假设一把枪的威力是p，装配的k个配件的威力加成是bi，那么枪最后的威力w=p*（1+b1+b2+…+bk）。

输入描述:
数据有多组，处理到文件结束。
第一行两个整数n和m，代表枪支数量和配件数量。
接下来n行，描述n把枪的属性：第一个整数为p，代表枪支的威力；第二个整数为k，代表该枪支可装备的配件数量；后面k个整数，
代表可装备配件的种类。接下来m行，描述m个配件的属性：第一个整数为q，代表配件的种类，第二个浮点数为b，代表配件可以
为枪支提供的威力加成。

输出描述:
每组数据输出为一行，输出一个浮点数，代表合理装备配件后的枪支最大威力。精确到小数点后4位。

示例1
输入
3 6
120 3 1 2 3
100 4 1 2 3 4
110 3 2 3 4
1 0.12
2 0.23
2 0.26
4 0.57
3 0.35
5 0.41

输出
239.8000

说明
对于上面的样例，正确答案应该是，使用第三把枪，配上第三、四、五个配件。
枪的最终威力就是110*（1+0.26+0.57+0.35）=239.8
备注:
对于100%的数据，
1 <= n,m,k,q <= 1000;
0 <= p <= 1000;
0 <= b <= 1。


解题思路：
注意同一种配件可能有不同的攻击加成，所以设一个数组保存B[i]保存第i种配件的最大加成值，
然后按照题目要求直接计算即可。
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define maxn 1005
using namespace std;

struct Gun{
	int pow;
	vector<int> v;
}g[maxn];

float B[maxn];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	int n,m,k,x;
	float b;
	while(scanf("%d%d",&n,&m) != -1){
		for(int i=1; i<=n; ++i){
			scanf("%d%d" , &g[i].pow, &k);
			g[i].v.clear();
			g[i].v.reserve(k);
			for(int j=0; j<k; ++j){
				scanf("%d",&x);
				g[i].v.push_back(x);
			}
		}
		
		memset(B,0,sizeof(B));
		for(int j=0; j<m; ++j){
			scanf("%d%f",&x,&b);
			if(B[x] < b) B[x]=b;
		}
		float ans =0;
		for(int i=1; i<=n; ++i){
			float buf = 1;
			vector<int>& v = g[i].v;
			for(int j=0; j<v.size(); ++j){
				buf += B[v[j]];
			}
			float tmp = buf * g[i].pow;
			if(tmp > ans) ans = tmp;
		}
		printf("%.4f\n",ans);
	}
	
    return 0;
} 