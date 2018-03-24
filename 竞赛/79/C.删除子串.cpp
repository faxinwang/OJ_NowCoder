/*
链接：https://www.nowcoder.com/acm/contest/79/C
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 262144K，其他语言524288K
64bit IO Format: %lld
题目描述 
给你一个长度为n且由a和b组成的字符串，你可以删除其中任意的部分（可以不删），使得删除后的子串“变化”
次数小于等于m次且最长。
变化：如果a[i]!=a[i+1]则为一次变化。（且新的字符串的首字母必须是'a'）
如果初始串全为b，则输出0。

输入描述:
第一行输入两个数n,m。（1 <= n <= 105,0 <= m <= 10）
第二行输入一行长度为n且由a和b组成的字符串

输出描述:
输出一个数字表示最长长度

示例1
输入
8 2
aabbabab

输出
6

说明
原串可以变成aabbbb，只改变了一次，且长度最长。

*/ 

#include<iostream>
#include<algorithm>
using namespace std;
char a[100005] = { 0 };
 
int f[15] = { 0 };
int g[15] = { 0 };
int main()
{
#ifdef WFX
freopen("in.txt","g",stdin);
#endif
    int n, m;
    cin >> n >> m;
    scanf("%s", a);
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (a[i] == 'a') 
            {
                f[j] = max( f[j]+1, g[j - 1]+1 );
            }
            else if (f[j - 1])
            {
                g[j] = max( f[j - 1] + 1, g[j]+1 );
            }
        }
        if (a[i] == 'a') f[0] += 1;
 
    }
    cout << max(g[m],f[m]) << endl;
}
