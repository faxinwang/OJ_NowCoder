/*
链接：https://www.nowcoder.com/acm/contest/75/B
来源：牛客网

题目描述 
uu遇到了一个小问题，可是他不想答。你能替他解决这个问题吗？
问题：给你k对a和r是否存在一个正整数x使每队a和r都满足：x mod a=r，求最小正解x或无解。


输入描述:
第一行是正整数k(k<=100000)
接下来k行，每行有俩个正整数a，r(100000>a>r>=0)

输出描述:
在每个测试用例输出非负整数m，占一行。
如果有多个可能的值，输出最小的值。
如果没有可能的值，则输出-1。

示例1
输入
2
8 7
11 9

输出
31

解题思路：
使用中国剩余定理

*/

#include<iostream>
#include<cstdio>
using namespace std;
int M[100001],R[100001];
typedef long long LL;
 
LL gcd(LL a,LL b){
    while(a&&b) a>b?a=a%b:b=b%a;
    return a+b;
}
 
LL ext_gcd(LL a,LL b, LL& x, LL& y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    LL d = ext_gcd(b, a%b, x, y);
    LL tx = x;
    x = y;
    y = tx - a / b * y;
    return d;
}
 
LL china_remain(int n){
    LL a = M[0], r1=R[0];
    LL x0,y0;
    for(int i=1; i<n; ++i){
        LL b=M[i],r2=R[i];
        LL r = r2 - r1;
        LL d = ext_gcd(a,b,x0,y0);
        if(r % d) return -1; //无解
        LL x = x0 * r / d; //求原方程的解
        LL t = b / d;
        //将x化为原方程的最小正整数解
        x = ((x % t) + t) % t;
        r1 = a * x + r1;
        a = a * b / d; //新的a 为 a和b的最小公倍数,LCM(a,b) = a*b/GCD(a,b)
    }
     
    if(r1 == 0){
        r1 = 1;
        for(int i=0;i<n;++i) r1 = r1 * M[i] / gcd(r1,M[i]);
    }
    return r1;
}
 
int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int T,n;
    // scanf("%d",&T);
    // for(int t =1; t <= T; ++t){
        scanf("%d",&n);
        for(int i=0;i<n;++i) scanf("%lld%lld",&M[i],&R[i]);
        printf("%lld\n", china_remain(n));
    // }
     
    return 0;
}