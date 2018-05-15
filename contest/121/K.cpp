#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 1e8;
const int maxn = 305;

int d[maxn][maxn];
int ans=INF;

int dp(int L, int R)
{
    int ans = INF;
    if(L >= R) return 0;
    if(L + 1 == R ) return L;
    if(d[L][R]) return d[L][R];
    for(int i = L+1; i < R; ++i)
    {
        ans = min(ans, dp(L, i-1) + i );
        ans = min(ans, i + dp(i+1, R) );
    }
    return d[L][R] = ans;
}

void dfs(int L, int R, int val)
{
    if(L + 1 >= R)
    {
        if(L + 1 == R) val += L;
        ans = min(ans, val);
        return;
    }
    int M = (L+R)/2;
    dfs(L, M,  val + M + 1);
    
    dfs(L, M-1, val+M);

    dfs(M+1, R, val + M);

    dfs(M, R, val + M - 1);
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r", stdin);
    #endif
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans = INF;
        dfs(1, n, 0);
        printf("%d\n", ans);
    }
    

    return 0;
}