#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1000;

vector<int> v2;

int cal(vector<int>& v)
{
    int cnt=0, n = v.size();
    for(int i=n-1; i>=0; --i)
    {
        if(v[0] == v2[i]) continue;
        if(v[i] == v2[i]) continue;
        // if(v[i] != v2[i] || v[i] < v[0])
        // {
        //     ++cnt;
        //     int j=n-1;
        //     while(v[j] != v2[i]) --j;
        //     // printf("v2[%d]=%d v[%d]=%d\n ", i, v2[i], j, v[j]  );
        //     v.erase(v.begin()+j);
        //     v.insert(v.begin(), v2[i]);
        // }
         ++cnt;
        int j=n-1;
        while(v[j] != v2[i]) --j;
        // printf("v2[%d]=%d v[%d]=%d\n ", i, v2[i], j, v[j]  );
        v.erase(v.begin()+j);
        v.insert(v.begin(), v2[i]);

    }
    return cnt;
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r", stdin);
    #endif
    int n,x;
    scanf("%d",&n);
    printf("n=%d\n",n);
    vector<int> v(n,0);
    for(int i=0; i<n; ++i) scanf("%d", &v[i]), cerr<<v[i]<<" ";
    cerr<<endl;

    v2=v;
    sort(v2.begin(), v2.end());

    printf("%d\n", cal(v));
    // for(int i=0; i<n; ++i) printf("%d ",v[i]);

    return 0;
}