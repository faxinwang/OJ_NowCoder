/*
���ӣ�https://www.nowcoder.com/acm/contest/79/C
��Դ��ţ����

ʱ�����ƣ�C/C++ 1�룬��������2��
�ռ����ƣ�C/C++ 262144K����������524288K
64bit IO Format: %lld
��Ŀ���� 
����һ������Ϊn����a��b��ɵ��ַ����������ɾ����������Ĳ��֣����Բ�ɾ����ʹ��ɾ������Ӵ����仯��
����С�ڵ���m�������
�仯�����a[i]!=a[i+1]��Ϊһ�α仯�������µ��ַ���������ĸ������'a'��
�����ʼ��ȫΪb�������0��

��������:
��һ������������n,m����1 <= n <= 105,0 <= m <= 10��
�ڶ�������һ�г���Ϊn����a��b��ɵ��ַ���

�������:
���һ�����ֱ�ʾ�����

ʾ��1
����
8 2
aabbabab

���
6

˵��
ԭ�����Ա��aabbbb��ֻ�ı���һ�Σ��ҳ������

*/ 

#include<iostream>
#include<algorithm>
using namespace std;
char a[100005] = { 0 };
 
int f[15] = { 0 };
int g[15] = { 0 };
int main()
{
#ifdef WFX
freopen("in.txt","g",stdin);
#endif
    int n, m;
    cin >> n >> m;
    scanf("%s", a);
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (a[i] == 'a') 
            {
                f[j] = max( f[j]+1, g[j - 1]+1 );
            }
            else if (f[j - 1])
            {
                g[j] = max( f[j - 1] + 1, g[j]+1 );
            }
        }
        if (a[i] == 'a') f[0] += 1;
 
    }
    cout << max(g[m],f[m]) << endl;
}
