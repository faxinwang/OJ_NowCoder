/*
链接：https://www.nowcoder.net/acm/contest/76/H
来源：牛客网

题目描述 
老李见和尚赢了自己的酒，但是自己还舍不得，所以就耍起了赖皮，对和尚说，光武不行，
再来点文的，你给我说出来1-8的全排序，我就让你喝，这次绝不耍你，你能帮帮和尚么？

输入描述:
无

输出描述:
1~8的全排列，按照全排列的顺序输出，每行结尾无空格。

示例1
输入
No_Input

输出
Full arrangement of 1~8

备注:
1~3的全排列  ：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/ 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[]={1,2,3,4,5,6,7,8};

int main(){
	do{
		for(int i=0;i<7; ++i) printf("%d ",a[i]);
		printf("%d\n",a[7]);
	}while(next_permutation(a,a+8));
	
	return 0;
}
