#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;

int a[maxn];

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        int _max=0;
        scanf("%d",&N);
        for(int i=0;i<N; ++i)
        {
            scanf("%d",&a[i]);
            if(_max < a[i]) _max = a[i];
        }
        int sum = 0;
        for(int i=0;i<N; ++i) sum += _max - a[i];
        while( sum %(N-1) ) sum += N, ++_max;
        printf("%d %d\n", sum / (N-1), _max);
    }

    return 0;
}