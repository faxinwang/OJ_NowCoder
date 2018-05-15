#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1000;


int main()
{
    #ifdef WFX
    freopen("in.txt","r", stdin);
    #endif
    int n,x,tmp, sum=0;
    scanf("%d%d",&x,&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&tmp);
        sum += tmp;
    }
    printf("%.2lf\n", 1.0*sum/x);


    return 0;
}