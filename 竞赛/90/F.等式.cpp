#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL f(LL n)
{
    LL ans = 0;
    for(LL x=n+1,N=n*2; x<=N; ++x)
    {
       double y = (x * n * 1.0) /(x - n);
       if( y - int(y) == 0.0) ++ans;
    }
    return ans;
}

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    LL T,n;
    cin>>T;
    while(T--)
    {
        scanf("%d", &n);
        printf("%lld\n", f(n));
    }

    return 0;
}