#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;

int a[maxn], b[maxn];
int ans = -1, N;

void dfs(int n, int k, int val)
{
    if(val < 0) return;
    if(n == N)
    {
        if(ans < val) ans = val;
        return;
    }
    if(k<3) dfs(n+1, k+1, val + a[n+1] - b[n+1]);
    dfs(n+1, k, val - b[n+1] );
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r", stdin);
    #endif
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) scanf("%d", a+i);
    for(int i=1; i<N; ++i) scanf("%d", b+i);
    dfs(0,0,0);
    printf("%d\n",ans);

    return 0;
}