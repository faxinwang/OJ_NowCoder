/*
链接：https://www.nowcoder.com/acm/contest/106/F
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
It’s universally acknowledged that there’re innumerable trees in the campus of HUST.
One day the tree manager of HUST asked you to sort N trees increasing by their heights ai. 
Because you were a warm-hearted and professional programmer, you immediately wrote the Bubble 
Sort to finish the task. However, you were so tired that made a huge mistake:

for(int i=1;i<n;i++)
    for(int j=1;j<=n-i;j++)
         if(a[j+k]<a[j]) swap(a[j+k],a[j]);

Usually k=1 is the normal Bubble Sort. But you didn't type it correctly. When you now realize it, 
the trees have been replanted. In order to fix them you must find the first place that goes wrong, 
compared with the correctly sorted tree sequence.

If every trees are in their correct places then print -1. And you should know k can be equal to 1 
which means you didn't make any mistake at all. Also you don't need to consider the part j+k beyond n.

输入描述:
The first line contains two integers N and K as described above.
Then the next line are N integers indicating the unsorted trees.

输出描述:
A integer in a single line, indicating the first place that goes wrong. Or -1 means no mistake.

示例1
输入
5 2
2 3 1 4 5

输出
2

解题思路:
首先以k为步长进行一趟错误的冒泡排序, 在使用该序列跟正确的排序比较, 第一个不匹配的位置即为第一个出错的位置.

后来有测试了一下, 可以直接跟正确的排序进行比较, 第一个不匹配的位置即为第一个出错的位置.

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+5;

int a[maxn], b[maxn];

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif

    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    if(k == 1)
    {
        printf("-1\n");
        return 0;
    }

    //错误的冒泡排序
    // for(int i=1; i<n; ++i)
    // {
    //     for(int j=0; j<n-i && j+k < n; ++j)
    //     {
    //         if( a[j+k] < a[j]) swap(a[j], a[j+k]);
    //     }
    // }
    //只需进行一次即可找到第一个错排的位置
    // for(int j=0; j+k <n; ++j)
    // {
    //     if(a[j+k] < a[j]) swap(a[j], a[j+k]);
    // }
    // for(int i=0; i<n; ++i) printf("%d ", a[i]);

    //跟正确的排序对比,寻找第一个错排的位置
    sort(b, b+n);
    int ans=-1;
    for(int i=0; i<n; ++i)
    {
        if(a[i] != b[i]){ ans = i+1; break; }
    }
    printf("%d\n",ans);

    return 0;
}