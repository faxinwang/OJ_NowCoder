/*
链接：https://www.nowcoder.com/acm/contest/105/D
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
Fibonacci数是非常有名的一个数列,它的公式为 f(n)=f(n-1)+f(n-2),f(0)=1,f(1)=2。 
我们可以把任意一个数x表示成若干不相同的Fibonacci数的和， 比如说14 = 13+1 = 8+5+1 = 8+3+2+1。
如果把Fibonacci数列作为数的位权，即f(i)作为第i位的位权，每位的系数只能是0或者1，从而得到一个01串。 
比如14可以表示成 100001，11001，10111。 我们再把这个01串看成2进制，再转成10进制以后就变成了 33，25，23。
为了避免歧义，我们将使用最小的那个值23。

请按照这个过程计算一下10进制整数通过上述转换过程得到的10进制整数。

输入描述:
第一行是一个整数T(1 ≤ T ≤ 10000)，表示样例的个数。
以后每行一个样例，为一个十进制正整数x(1 ≤ x ≤ 109)。

输出描述:
每行输出一个样例的结果。

示例1
输入
5
1
10
100
1000
1000000000

输出
1
14
367
10966
4083305275263

解题思路:
首先打表计算出题目给定范围内的Fibonacci数, 然后对于每个给定的数x, 一定可以用一组Fibonacci数的和表示
将x表示成若干个Fibonacci数的和, 记录所用数字的下标存在bit数组里, 然后根据f[i] = f[i-1] + f[i-2]的性质, 
将使用的位f[i] 拆分成f[i-1] 和 f[i-2] (前提是f[i-1]和f[i-2]没有使用), 为了避免遗漏, 需要顺着和逆序各来一次
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100;
typedef long long LL;

LL f[maxn];
int bit[maxn];

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    int T,len, x;
    f[0] = 1;
    f[1] = 2;
    for(len = 2; ; ++len)
    {
        f[len] = f[len-1] + f[len-2];
        if(f[len] > 1e9) break; //len = 43
    }

    scanf("%d", &T);
    while(T--)
    {
        memset(bit,0,sizeof(bit));
        scanf("%d", &x);
        //从高位开始, 最后x一定会变被减为0
        for(int i=len-1; i>=0; --i)
        {
            if(x >= f[i])
            {
                x -= f[i];
                bit[i] = 1;
            }
        }

        for(int i=2; i<len; ++i)
        {
            if(bit[i] && !bit[i-1] && !bit[i-2])
            {
                bit[i] = 0;
                bit[i-1] = bit[i-2] = 1;
            }
        }

        for(int i=len-1; i>=2; --i)
        {
            if(bit[i] && !bit[i-1] && !bit[i-2])
            {
                bit[i] = 0;
                bit[i-1] = bit[i-2] = 1;
            }
        }

        LL ans = 0;
        for(int i=0; i<len; ++i)
        {
            if(bit[i]) ans += 1LL << i;
        }
        printf("%lld\n", ans);
    }

    return 0;
}