#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1000;

// bool vis[maxn];

int main()
{
    #ifdef WFX
    freopen("in.txt","r", stdin);
    #endif
    int T,n,k;
    vector<int> v;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        v.reserve(n);
        for(int i=1; i<=n; ++i) v.push_back(i);
        int i=0, flag=1;
        while(v.size())
        {
            i += k-1;
            if( i >= v.size()) i %= v.size();
            if(flag) printf("%d", v[i]), flag=0;
            else printf(" %d", v[i]);
            v.erase(v.begin() + i);
        }
        cout<<endl;
    }

    return 0;
}