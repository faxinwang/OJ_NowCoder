#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp(int n)
{
    LL d[50]={1,1};
    for(int i=2; i<=n; ++i)
    {
        for(int j=1; j<=i; ++j) d[i] += d[i-j];
        // printf("%d ",d[i]);
    }
    return d[n];
}



int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        cout<<dp(N)<<endl;
    }

    return 0;
}