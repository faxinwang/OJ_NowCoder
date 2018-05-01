/*
链接：https://www.nowcoder.com/acm/contest/106/C
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
It’s universally acknowledged that there’re innumerable trees in the campus of HUST. 

Thus a professional tree manager is needed. Your task is to write a program to help manage the trees. 
Initially, there are n forests and for the i-th forest there is only the i-th tree in it. Given four 
kinds of operations.
1 u v, merge the forest containing the u-th tree and the forest containing the v-th tree;
2 u, separate the u-th tree from its forest;
3 u, query the size of the forest which contains the u-th tree;
4 u v, query whether the u-th tree and the v-th tree are in the same forest.

输入描述:
The first line contains an integer T, indicating the number of testcases.
In each test case:
The first line contains two integers N and Q, indicating the number of initial forests and 
the number of operations.
Then Q lines follow, and each line describes an operation.

输出描述:
For each test cases, the first line should be "Case #i:", where i indicate the test case i.
For each query 3, print a integer in a single line.
For each query 4, print "YES" or "NO" in a single line.

示例1
输入
1
10 8
3 1
4 1 2
1 1 2
3 1
4 1 2
2 1
3 1
4 1 2

输出
Case #1:
1
NO
2
YES
1
NO


*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
int f[maxn], w[maxn], si[maxn];
 
void init() {
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
        w[i] = i;
        si[i] = 1;
    }
}
 
int fnd(int x) {
    return f[x] == x ? x : f[x] = fnd(f[x]);
//    while (f[x] != f[f[x]]) f[x] = fnd(f[x]);
//    return f[x];
}
 
void unon(int x, int y) {
    x = fnd(x), y = fnd(y);
    if (x == y) return ;
    f[y] = x;
    si[x] += si[y];
}
 
int main() {
    int t, num = 1;
    scanf("%d", &t);
    while (t--) {
        init();
        printf("Case #%d:\n", num++);
        int n, q, cnt, x, u, v;
        scanf("%d %d", &n, &q);
        cnt = n + 1;
        while (q--) {
            scanf("%d", &x);
            if (x == 1) {
                scanf("%d %d", &u, &v);
                unon(w[u], w[v]);
            } else if (x == 2) {
                scanf("%d", &u);
                v = fnd(w[u]);
                si[v]--;
                w[u] = ++cnt;
            } else if (x == 3) {
                scanf("%d", &u);
                printf("%d\n", si[fnd(w[u])]);
            } else {
                scanf("%d %d", &u, &v);
                printf("%s\n",fnd(w[u]) == fnd(w[v]) ? "YES" : "NO");
            }
        }
    }
    return 0;
}