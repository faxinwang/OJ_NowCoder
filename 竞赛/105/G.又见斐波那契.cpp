/*
链接：https://www.nowcoder.com/acm/contest/105/G
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
这是一个加强版的斐波那契数列。给定递推式

F(i) = F(i-1) + F(i-2) + i^3 + i^2 + i + 1   (i>=2)
F(1) = 1
F(0) = 0

求F(n)的值，由于这个值可能太大，请对109+7取模。

输入描述:
第一行是一个整数T(1 ≤ T ≤ 1000)，表示样例的个数。
以后每个样例一行，是一个整数n(1 ≤ n ≤ 1018)。

输出描述:
每个样例输出一行，一个整数，表示F(n) mod 1000000007。

示例1
输入
4
1
2
3
100

输出
1
16
57
558616258

解题思路:
这题需要使用矩阵快速幂:

                   |F(n)  |        |F(n+1) |
                   |F(n-1)|        |F(n)   |
                   | n^3  |        |(n+1)^3|
     A         X   | n^2  |     =  |(n+1)^2|
                   | n^1  |        |(n+1)^1|
                   |  1   |        |   1   |   


|1 1 1 1 1 1|      | F1 |      | F1 + F0 + 2^3 + 2^2 + 2^1 + 1    |    | F2 |
|1 0 0 0 0 0|      | F0 |      | F2 + 0  + 0   +   0 + 0   + 0    |    | F1 |
|0 0 1 3 3 1|  X   | 2^3|   =  | 0 + 0 + 1*2^3 + 3*2^2 + 3*2^1 + 1|  = | 3^3|
|0 0 0 1 2 1|      | 2^2|      | 0 + 0 + 0 + 1*2^2 + 2*2^1 + 1    |    | 3^2|
|0 0 0 0 1 1|      | 2^1|      | 0 + 0 + 0 + 0 + 1^2 + 1          |    | 3^1|
|0 0 0 0 0 1|      |  1 |      | 0 + 0 + 0 + 0 + 0   + 1          |    |  1 |


     A         X     F2     =                                            F3


根据规律:
A * F2 = F3
A * F3 = F4
 .....
A * F(n-1) = F(n)

递推可得, 当n>=2时, 有
A^(n-2) * F2 = F(n) = F(n-1) + F(n-2) + n^3 + n^2 + n^1 + 1

为了方便我们计算系数矩阵A的n-1次方即可直接获得Fn
A^(n-1) * F2 = F(n+1) = F(n) + F(n-1) + (n+1)^3 + (n+1)^2 + (n+1) + 1

知道了上面这些后, 重点就是如何计算系数矩阵A了

第一行: x11 * F(n-1) + x12 * F(n-2) + x13 * n^3 + x14*n^2 + x15*n + x16 * 1 = F(n)
很显然 x11 ~ x16 都为1

第二行: x21 * F(n-1) + x22 * F(n-2) + x23 * n^3 + x24*n^2 + x25*n + x26 * 1 = F(n-1)
显然: x21=1, 其他都为0

第三行: x31 * F(n-1) + x32 * F(n-2) + x33 * n^3 + x34*n^2 + x35*n + x36 * 1 = (n+1)^3
很显然 x31 = x32 = 0, 然后计算得:
(n+1)^3 = n^3 + 3*n^2 + 3*n + 1 = x33 * n^3 + x34*n^2 + x35*n + x36 * 1
所以 x33=1, x34=3, x35=3, x36=1

第四行: x41 * F(n-1) + x42 * F(n-2) + x43 * n^3 + x44*n^2 + x45*n + x46 * 1 = (n+1)^2
很显然 x41 = x42 = x43 = 0, 然后计算得:
(n+1)^2 = n^2 + 2*n + 1 = x44*n^2 + x45*n + x46 * 1
所以 x44 = 1, x45 = 2, x46=1

第五行: x51 * F(n-1) + x52 * F(n-2) + x53 * n^3 + x54*n^2 + x55*n + x56 * 1 = n+1
很显然 x51 = x52 = x53 = x54 = 0, 然后计算得:
n + 1 = x55 * n + x56 * 1
所以 x55=1, x56=1

第六行: x61 * F(n-1) + x62 * F(n-2) + x63 * n^3 + x64*n^2 + x65*n + x66 * 1 = 1
很显然: x61~x65 = 0, x66=1

*/


#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

struct Matrix
{
    int N,M;
    vector<vector<LL> > a;

    //n rows, m columns
    Matrix(int n=0, int m=0):M(m),N(n)
    {
        a.reserve(n);
        for(int i=0; i<n; ++i) a.push_back(vector<LL>(m, 0));
    }

    void identify()
    {
        for(int i=0; i<N; ++i)
        for(int j=0; j<M; ++j) 
        a[i][j] = (i==j? 1 : 0);
    }

    void print()
    {
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<M; ++j) printf("%d ",a[i][j]);
            printf("\n");
        }
    }

    Matrix operator*(const Matrix& m)
    {
        Matrix ret(N, m.M);
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<m.M; ++j)
            {
                ret.a[i][j] = 0;
                for(int k=0; k<M; ++k)
                {
                    ret.a[i][j] += a[i][k] * m.a[k][j] % MOD;
                    if(ret.a[i][j] >= MOD) ret.a[i][j] -= MOD;
                }
            }
        }
        return ret;
    }
};

//快速计算矩阵A的N次方
Matrix qpow(Matrix A, LL N)
{
    Matrix ret(A.N, A.M);
    ret.identify();
    while(N)
    {
        if(N & 1) ret = ret * A;
        A = A * A;
        N >>= 1;
    }
    // ret.print();
    return ret;
}


int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif

    int a[6][6] = {{1,1,1,1,1,1},
                   {1,0,0,0,0,0},
                   {0,0,1,3,3,1},
                   {0,0,0,1,2,1},
                   {0,0,0,0,1,1},
                   {0,0,0,0,0,1}};
    LL T, N;
    Matrix A(6,6); //系数矩阵
    for(int i=0; i<6; ++i)
    for(int j=0; j<6; ++j)
    A.a[i][j] = a[i][j];
    
    Matrix F2(6,1);
    F2.a[0][0] = 1; //F(1)
    F2.a[1][0] = 0; //F(0)
    F2.a[2][0] = 8; //2^3
    F2.a[3][0] = 4; //2^2
    F2.a[4][0] = 2; //2^1
    F2.a[5][0] = 1; // 1

    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld", &N);
        if(N == 0)
        {
            printf("0\n");
            continue;
        }
        
        //F(n+1) = F(n) + F(n-1) + (n+1)^3 + (n+1)^2 + (n+1) + 1
        Matrix Fn1 = qpow(A, N-1) * F2; 
        printf("%lld\n", Fn1.a[0][0]);
    }

    return 0;
}