/*
解题思路：
求一个正整数x约数的个数，只需要找出i从1到sqrt(x)中x%i==0的个数，乘以2即为总的约数个数。
1.当x%i==0时，x/i也是x的约数.
2.1和x也是x的约数.
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int fun(int x){
    int ans =0,i;
    for(i=1; i*i<x; ++i){
        //两个约数分别是i 和 x/i
        if(x % i == 0) ans +=2;
    }
    if(i*i==x) ++ans; // 相同的约数算一个
    return ans;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n,x;
    while(~scanf("%d",&n)){
        for(int i=0; i<n; ++i){
            scanf("%d",&x);
            printf("%d\n",fun(x));
        }
    }

    return 0;
}