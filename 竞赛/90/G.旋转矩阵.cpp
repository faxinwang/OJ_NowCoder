/*
���ӣ�https://www.nowcoder.com/acm/contest/90/G
��Դ��ţ����

ʱ�����ƣ�C/C++ 1�룬��������2��
�ռ����ƣ�C/C++ 32768K����������65536K
64bit IO Format: %lld
��Ŀ���� 
���۹�˾�Գ�����ʼ����˾�㽫���ƶ����ܽ�ͨ�ķ�չ��������ĳ��и���ȫ������Ч�������ã������ʡ�
��Ϊ��˾ʹ����ͨ����ҵ�ںϡ�������������������ҵ�ķ�ʽ�����조��������������˾�������ˡ�����
�˼�ʻ����ϵͳ����˾��Ը���ǳ�Ϊ�й���һ������һ�������ܳ��й�˾��

��һ�죬���۹�˾�Ĺ���ʦ���泵�������ԡ�
���۹�˾�����鳵������һ����ֵ�ͼ��������һ��n*m�ľ������������Ե�������ÿ�ο�������������
С����֪��ת��֮���ͼ������ô����
������˵����һ��n*m���ַ�����ֻ����3���ַ�����+����-������|����,ͨ��һͨ����֮����ʲô���ӣ�

��������:
��һ�в���������T��0<T<=100��
ÿ������������һ������������n,m(0<n,m<=30)
��������n����һ��n*m���ַ�����
�ַ�����֮����һ��ֻ������L��(����)�͡�R�������������ַ��������Ȳ�����1000
ÿ�����������һ������

�������:
��һ������������n,m
��������n����һ��n*m���ַ�����
ÿ�������������һ������

ʾ��1
����
2
2 3
+-+
|+|
LLRRR

3 2
-+
+|
-+
LLL

���
3 2
-+
+|
-+

2 3
|+|
+-+


��ע:
��������ʱ����ת��������˳ʱ����ת
-ͨ��һ����������������|
|ͨ��һ����������������-

����˼·��
�鷳�ĵط���Ҫ������ת����ֻҪ���ƺ��±��ûʲô���⡣

��ʱ����ת�����һ�н���Ϊ��ת֮�����ĵ�0�У���0�е�
���һ��Ԫ�ؽ���Ϊ��ת������0���еĵ�0��Ԫ�أ�����λ������

˳ʱ����ת�� ��0�н���Ϊ��ת֮�����ĵ�0�У����һ�� 
�ĵ�0��Ԫ�ؽ���Ϊ��ת������0�еĵ�0��Ԫ�أ�����λ������ 
*/ 
#include<bits/stdc++.h>
using namespace std;

void print(vector<string>& v)
{
    printf("%d %d\n",v.size(), v[0].size());
    for(int i=0;i<v.size(); ++i) cout<<v[i]<<endl;
    cout<<endl;
}


vector<string> rotateL(vector<string> & v1)
{
    vector<string> v2;
    v2.reserve(v1[0].size());
    for(int c = v1[0].size()-1; c>=0; --c)
    {
        string s;
        for(int r = 0, n=v1.size(); r<n; ++r)
        {
            if(v1[r][c] =='+') s += '+';
            else s += v1[r][c]== '|'? '-' : '|';
        }
        v2.push_back(s);
    }
    // cout<<"rotate L"<<endl;
    // print(v2);
    return v2;
}

vector<string> rotateR(vector<string> & v1)
{
    vector<string> v2;
    v2.reserve(v1[0].size());
    for(int c=0,m=v1[0].size(); c<m; ++c)
    {
        string s;
        for(int r = v1.size()-1; r>=0; --r)
        {
            if(v1[r][c] =='+') s += '+';
            else s += v1[r][c]== '|'? '-' : '|';
        }
        v2.push_back(s);
    }
    // cout<<"rotate R"<<endl;
    // print(v2);
    return v2;
}


int main()
{  
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        vector<string> v;
        string s, op;
        scanf("%d%d",&n,&m);
        v.reserve(n);
        for(int i=0;i<n;++i)
        {
            cin>>s;
            v.push_back(s);
        }
        cin>>op;
        for(int i=0; i<op.size(); ++i) v = op[i]=='L' ? rotateL(v) : rotateR(v);
        print(v);
    }

    return 0;
}
