/*
链接：https://www.nowcoder.com/acm/contest/74/D
来源：牛客网

题目描述 
Wozuinb非常喜欢打炉石传说，但是菜的不行，所以他决定打
竞技场来练练手。系统按顺序给出n张卡牌，每张卡牌都有自
己的使用消耗a[i]，每次只给出一张，wozuinb可以选择或者
弃掉这张牌。每选择一张牌都会按选择顺序放在卡槽中，当
卡槽中放满30张即可组成一套套牌。Wozuinb希望自己的套牌的
消耗满足一个平滑的曲线，即30张卡牌都满足第i张卡牌的消耗
不小于第i-1张(i>1)。请你帮助wozuinb看一看，这些卡牌能不
能组成想要的套牌，如果能组成输出“yes”，如果不能输出“no”。


输入描述:
第一行输入一个整数n，0<n<100。
第二行输入一行数字a[i]，每个数字用空格隔开，代表第i张出现的卡牌的消耗。

输出描述:
输出一行，“yes”或“no”

示例1
输入
5
1 2 3 4 5

输出
no

解题思路：
就是判断给定序列中是否存在一个长度>=30的不下降子序列。
直接用相关的DP算法求解。
*/

#include<iostream>
#include<cstdio>
using namespace std;

int a[105], d[105];

int dp(int n){
	d[1]=1;
	int Max=1; 
	for(int i=2; i<=n; ++i){
		int tmp = 0;
		for(int j=i-1;j>=1; --j){
			if(a[j] <= a[i] &&  tmp<d[j]) tmp = d[j];
		}
		d[i] = tmp + 1;
		if(Max < d[i]) Max = d[i];
	}
	
	return Max;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	if(n<30){printf("no"); return 0;}
	for(int i=1;i<=n;++i) scanf("%d", &a[i]);
	printf("%s",dp(n)>=30? "yes":"no");
	
	return 0;
} 