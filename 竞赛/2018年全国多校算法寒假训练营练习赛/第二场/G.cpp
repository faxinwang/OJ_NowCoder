/*
链接：https://www.nowcoder.com/acm/contest/74/G
来源：牛客网

题目描述 

	杭州人称傻乎乎的人为62，而嘟嘟家这里没有这样的习俗。



	相比62，他那里的人更加讨厌数字38，当然啦，还有4这个



	数字！所以啊，嘟嘟不点都不想见到包含38或者4的数字。



	每次给出一个区间[n，m],你能找到所有令人讨厌的数字吗？


输入描述:
多组输入输出；
输入的都是整数对n、m（0<n≤m<1000000），
如果遇到都是0的整数对，则输入结束。

输出描述:
对于每次的输入
输出全部令人讨厌的数的个数

示例1
输入
1 100
0 0

输出
20

解题思路：
首先一次性算出给定数据范围内的令人讨厌的数字的个数，保存在数组a中，a[i]表示0到i中令人讨厌
的数字的个数，a[i] - a[j-1]就表示区间[j,i]中令人讨厌的数字的个数。
*/

#include <iostream>
#include <cstdio>
#define maxn 1000005
using namespace std;

int a[maxn];
inline bool check(int n){
	while(n){
		if(n % 10==4 || n%100 ==38) return 1;
		n /= 10;
	}
	return 0;
}
void init(){
	for(int i=1; i<maxn; ++i){
		a[i] = check(i)?a[i-1]+1 : a[i-1];
	}
}

int Fun(int n,int m)
{
    return a[m] - a[n-1];
}


int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n,m;
    init();
    while(scanf("%d%d",&n,&m) && (m||n)){
        cout<<Fun(n,m)<<endl;
    }



    return 0;
}