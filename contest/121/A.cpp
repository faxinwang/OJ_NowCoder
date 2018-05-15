#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1000;

struct Gift
{
    int prise;
    string name;
    Gift(int p ,char* s):prise(p),name(s){};
    bool operator<(const Gift& g)const
    {
        if(prise != g.prise) return prise > g.prise;
        return name > g.name;
    }
};

vector<Gift> v;

int main()
{
    #ifdef WFX
    freopen("in.txt","r", stdin);
    #endif
    int T,n,p,k;
    char s[31];
    
    scanf("%d", &T);
    for(int kiss=1; kiss<=T; ++kiss)
    {
        scanf("%d",&n);
        v.clear();
        v.reserve(n);
        for(int i=0; i<n; ++i)
        {
            scanf("%s%d", s,&p );
            v.push_back(Gift(p, s));
        }
        sort(v.begin(), v.end());

        scanf("%d",&k);
        // for(int i=0; i<n; ++i)
        printf("#%d: %s %d\n", kiss, v[k-1].name.c_str(),  v[k-1].prise);
    }

    

    return 0;
}