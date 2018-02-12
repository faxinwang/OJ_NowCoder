/*
链接：https://www.nowcoder.com/acm/contest/74/H
来源：牛客网

题目描述 
既然是了断局了，大家就随便玩玩数字呗。
已知一个数列前10项分别是 
{0, 1, 1, 2, 4, 7, 13, 24, 44, 81}
小G不满足呀：我要更多的数！！！不给就不让你们玩了。
小G会问你第n项是什么数字，请回答这个顽皮的孩子吧。

输入描述:
多组数据输入输出；
第一行输入一个整数n（1<=n<=50）

输出描述:
输出数列中的第n个数。

示例1
输入
1
2
3

输出
0
1
1

解题思路：
规律为a[i] = a[i-1] + a[i-2] + a[i-3]
需要算到第50项，用int会溢出，用long long刚好存的下。
*/

#include<iostream> 
#include<cstdio>
using namespace std;
typedef long long LL;

LL a[55]={0,1,1};


int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n;
	for(int i=3;i<=50;++i) a[i] = a[i-1]+a[i-2]+a[i-3];
	while(~scanf("%d",&n)) printf("%lld\n",a[n-1]);
	
	return 0;
}