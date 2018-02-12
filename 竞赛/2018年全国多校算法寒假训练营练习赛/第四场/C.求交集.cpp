/*
链接：https://www.nowcoder.net/acm/contest/76/C
来源：牛客网

题目描述 
给你两个升序排列的集合，求出两个集合的交集。

输入描述:
有多个测试用例，输入到文件结束。
对于每一个测试用例：
第一行输入两个整数n,m(0<n,m<=1000000),分别代表第一个集合和第二个集合的元素的数量。
第二行输入n个整数，表示第一个集合中的元素，元素之间用空格隔开。
第三行输入m个整数，表示第二个集合中的元素，元素之间用空格隔开。
两个集合中的元素范围在[-1000000000,1000000000]区间内。

输出描述:
每个测试用例用一行来输出两个集合的交集的所有元素（元素用空格隔开且按升序排列），
若交集为空则输出"empty"。

示例1
输入
2 3
1 3
1 2 3

输出
1 3

解题思路：
求两个升序序列A,B(集合，所以无重复数字)的交集. 
1.设置两个指针i，j分别指向两个序列当前考虑的位置。初始时i,j都为0，指向两个序列的第一个元素
2.然后循环进行如下操作：
	1.首先考虑A[i]: 在B中定位到 B[j] >= A[i]的元素，如果B[j]==A[i]，则找到了一个共有元素，
	  就 ++i,考虑A中的下一个元素
	2.然后考虑B[j]：在A中定位到A[i] >= B[j]的元素, 如果A[i]== B[j]， 则找到了一个共有元素，
	  就 ++j,考虑B中的下一个元素
	3.如果i到达A序列的末尾或者j到达B序列的末尾，则退出循环
3.输出所有找到的共有元素，或者在找到的时候直接输出，注意最后一个元素后面没有空格 
*/ 
#include<iostream>
#include<cstdio>
#define maxn 1000005
using namespace std;

int a[maxn],b[maxn];

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n,m,x;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0; i<n; ++i) scanf("%d",&a[i]);
		for(int i=0; i<m; ++i) scanf("%d",&b[i]);
		int i=0,j=0,flag=0;
		while(1){
			while(i<n && a[i] < b[j]) ++i;
			if(i==n) break;
			if(a[i] == b[j]){
				if(flag==0){
					flag=1;
					printf("%d",a[i]);
				}else printf(" %d",a[i]);
				if(++i == n) break;
			}
			while(j<m && b[j] < a[i]) ++j;
			if(j==m) break;
			if(a[i] == b[j]){
				if(flag==0){
					flag = 1;
					printf("%d",a[i]);
				}else printf(" %d",a[i]);
				if(++j == m) break;
			}
		}
		printf("%s\n",flag?"":"empty");
	}
	
	return 0;
}
