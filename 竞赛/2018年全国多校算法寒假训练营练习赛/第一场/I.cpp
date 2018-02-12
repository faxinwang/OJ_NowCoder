/*
链接：https://www.nowcoder.com/acm/contest/67/I
来源：牛客网

题目描述 
    lulu喜欢小于等于1000的正整数，但是如果某个数是a或b的倍数，lulu会讨厌这个数。如果某个数里包含了a和b两
个数里包含的数，lulu也会讨厌。（例如a=14，b=23，如果数字中包含1、2、3、4这四个数中的任意一个数，lulu就
会讨厌这个数）。现在告诉你a，b，你能说出lulu喜欢的数有多少个么。

输入描述:
第一行是样例数T
第2到2+T-1行每行有2个整数a b。

输出描述:
输出lulu喜欢的数的个数

示例1
输入
3
2 3
14 23
1234 5678

输出
171
190
7

说明
a=1234 b=5678的时候，只考虑含有数字9，0的数，只有7个，分别是9,99,999,90,990,909,900

备注:
对于100%的数据，
0 < T <= 20;
0 <= a <= 99999;
0 <= b <= 99999。


解题思路：
将数a和b中的数组分解出来并记录里面包含的数字，f[i]=1表示a或b中有数字i，
然后暴力枚举0到1000的数字
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int f[10];

void process(int a){
	while(a){
		f[a%10] = 1;
		a/= 10;
	}
}

bool hit(int a){
	
	while(a){
		if(f[a%10]) return 1;
		a /= 10;
	}
	return 0;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
	int T,a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		process(a);
		process(b);
		int ans = 0;
		for(int i=1; i<=1000; ++i) if(i%a && i%b && !hit(i)) ++ans;
		printf("%d\n",ans);
		memset(f,0,sizeof(f));
	}
	
	return 0;
}