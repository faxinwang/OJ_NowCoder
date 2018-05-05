/*
链接：https://www.nowcoder.com/acm/contest/118/B
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述 

喜爱ACM的PBY同学遇到了一道数学难题，已知底数n，请你帮他准确的计算出结果a = nπ（n的π次方），结果保留小数点后x位。

输入描述:
第一行是一个整数t，表示测试实例的个数；
然后是t行输入数据，每行包含两个正整数n和x，表示底数和保留位数。
（1 <= t <= 100，1 <= n <= 500，1 <= x <= 6）

输出描述:
对于每组输入数据，分别输出结果a，每个输出占一行。

示例1
输入
3
1 3
7 6
9 1

输出
1.000
451.807873
995.0

解题思路:
用acos(-1)计算出PI的精确值. 然后直接用pow计算次方.

*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;

//计算PI
const double PI = acos(-1);

int main()
{
    #ifdef WFX
    freopen("in.txt","r", stdin);
    #endif
    int T, n, x;
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%d%d", &n, &x);
        printf("%.*lf\n", x , pow(n, PI)); //动态设置输出精度
        
        /* //用c++的格式控制输出设定的小数位数
        cout.setf(ios::showpoint);
        cout.setf(ios::fixed);
        cout.precision(x);
        cout<<pow(n, PI)<<endl;
        */
    }

    return 0;
}