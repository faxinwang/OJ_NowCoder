/*
链接：https://www.nowcoder.com/acm/contest/90/G
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述 
景驰公司自成立伊始，公司便将“推动智能交通的发展，让人类的出行更安全，更高效，更经济，更舒适”
作为公司使命，通过产业融合、建设智能汽车出行行业的方式，打造“利国、利民、利公司、利个人”的无
人驾驶出行系统。公司的愿景是成为中国第一、世界一流的智能出行公司。

有一天，景驰公司的工程师在真车上做测试。
景驰公司的试验车上面有一个奇怪的图案，这是一个n*m的矩阵，这辆车可以到处开，每次可以左旋右旋，
小明想知道转完之后的图案是怎么样的
具体来说：有一个n*m的字符矩阵，只包含3种字符（‘+’‘-’，‘|’）,通过一通乱旋之后变成什么样子？

输入描述:
第一行测试样例数T（0<T<=100）
每个测试样例第一行两个正整数n,m(0<n,m<=30)
接下来的n行是一个n*m的字符矩阵
字符矩阵之后是一串只包含‘L’(左旋)和‘R’（右旋）的字符串，长度不超过1000
每个样例间输出一个空行

输出描述:
第一行两个正整数n,m
接下来的n行是一个n*m的字符矩阵
每个样例后面输出一个空行

示例1
输入
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

输出
3 2
-+
+|
-+

2 3
|+|
+-+


备注:
左旋即逆时针旋转，右旋即顺时针旋转
-通过一次左旋或右旋会变成|
|通过一次左旋或右旋会变成-

解题思路：
麻烦的地方主要在于旋转矩阵，只要控制好下标就没什么问题。

逆时针旋转：最后一列将作为旋转之后矩阵的第0行，第0行的
最后一个元素将作为旋转矩阵后第0行中的第0个元素，其他位置类推

顺时针旋转： 第0列将作为旋转之后矩阵的第0行，最后一行 
的第0个元素将作为旋转矩阵后第0行的第0个元素，其他位置类推 
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
