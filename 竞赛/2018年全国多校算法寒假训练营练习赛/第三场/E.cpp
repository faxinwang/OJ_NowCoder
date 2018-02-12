/*
链接：https://www.nowcoder.com/acm/contest/75/E
来源：牛客网

题目描述 
给定一个整数N（0≤N≤10000），求取N的阶乘

输入描述:
多个测试数据，每个测试数据输入一个数N

输出描述:
每组用一行输出N的阶乘

示例1
输入
1
2
3

输出
1
2
6

解题思路：
高精度阶乘裸题.
*/

#include <iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
 
string factorial(int n){
    string s="1";
    if(n <= 1) return s;
    for(int i=2; i<=n; ++i){
        int carry = 0;
        for(int j=0,len=s.size(); j<len; ++j){
            carry += (s[j] - '0') * i;
            s[j] = carry % 10 + '0';
            carry /= 10;
        }
        while(carry){
            s += carry % 10 + '0';
            carry /= 10;
        }
    }
    for(int i=0,j=s.size()-1; i<j; ++i,--j){
        char ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }
    return s;
}
 
int main(){
    int n;
    while(~scanf("%d",&n)){
        cout<<factorial(n)<<endl;
    }
 
    return 0;
}