/*
���ӣ�https://www.nowcoder.com/acm/contest/79/B
��Դ��ţ����

ʱ�����ƣ�C/C++ 1�룬��������2��
�ռ����ƣ�C/C++ 262144K����������524288K
64bit IO Format: %lld
��Ŀ���� 
T95��������Ȼ���������Լ�����̫���ˣ�

����T95�������ʡ���Ȼ��T95��ϲ��������

������n��������n�����ͣ���i��������ʹ��ֵ��ai����i�����͵Ŀ���ֵ��bi

Ϊ�˼��ʣ�T95�Ե����ʹ������ܴ������ܲ��Ĵ���

����T95̫���ˣ�ÿ��������һ��֮��ͻỵ��

����T95ϲ���Բ�ͬ�Ŀ�ζ��ÿ����������һ��

������˹�˺��պ���ֵ���֭bug��T95ÿ��3�ξͻ�õ������m����ֵ

����T95��֪�������Եõ�����󣨿���ֵ�ĺ�-ʹ��ֵ�ĺͣ��Ƕ���

��������:
��һ��������n,m

�ڶ���n������ʾai

������n������ʾbi

�������:
���һ��һ������ʾ��

ʾ��1
����
5 10
0 1 3 6 8
0 4 5 6 6

���
23

˵��
�������ͣ�
�ܣ�1,0,3
�ԣ�6,5,6
���⣺10

��ע:
����100%�����ݣ���1 <= n <= 1000000 , 0<=ai,bi,m<=2000000000

����˼·��
��ai�������򣬶�bi��������Ȼ�����sum{ 1<=i<=n | bi - ai } + i/3*m�����ֵ�� 

*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
typedef long long LL;

LL a[maxn], b[maxn];


int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
    for(int i=1; i<=n; ++i) scanf("%d", &b[i]);

    sort(a+1, a+n+1);
    sort(b+1, b+n+1, greater<int>());

    LL sum=0, i=1, ans=0;
    for(int k=0; i<=n; ++i)
    {
        sum += b[i] - a[i];
        if( ++k == 3)
        {
            sum += m;
            k = 0;
        }
        if(sum > ans) ans = sum;
        if(sum < 0) break;
    }
    
    cout<<ans<<endl;

    return 0;
}
