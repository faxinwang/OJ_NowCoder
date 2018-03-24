/*
链接：https://www.nowcoder.com/acm/contest/90/D
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述 
掌握未来命运的女神 psd 师兄在拿了朝田诗乃的 buff 后决定去实习。
埃森哲公司注册成立于爱尔兰，是一家全球领先的专业服务公司，为客户提供战略、咨询、数字、技术和运
营服务及解决方案。他们立足商业与技术的前沿，业务涵盖40多个行业，以及企业日常运营部门的各个职能。
凭借独特的业内经验与专业技能，以及翘楚全球的交付网络，他们帮助客户提升绩效，并为利益相关方持续
创造价值。埃森哲是《财富》全球500强企业之一，目前拥有约41.1万名员工，服务于120多个国家的客户。
于是psd打算去埃森哲公司投一下简历。
于是他用英文写了一篇简历，由于手速太快了以致自己都不知道写了什么。
然而面试官 xwc 一眼就看到了重点：大学打过 ACM！
xwc：“
    听说你很低袄？考你个题：
    忽略字母大小写，你这篇简历去掉最长的回文子序列后还有多长？
”
psd 顺手就把这个问题抛给了你。

输入描述:
多组输入，每组输入一个长度不超过 1234 的没空格的字符串，是 psd 的简历。

输出描述:
每组输出一个整数，如题。

示例1
输入
google

输出
2

示例2
输入
aBc,bAd

输出
2

解题思路：
将求最长回文子序列转换为求源序列和翻转序列的最长公共子序列。
只需要求出最长公共子序列，然后用文档总长度减去最长公共子序列的长度即为答案。
序列下标从0开始时，一直WA一直WA。 从1开始一发就AC了。可能还是不够熟练。
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1300;

char a[maxn], b[maxn];
int d[maxn][maxn];

int dp(int N)
{
    for(int i=1;i<=N; ++i)
    {
        for(int j=1; j<=N; ++j)
        {
            if( a[i] == b[j] ) d[i][j] = d[i-1][j-1] + 1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
            // printf("%d ", d[i][j]);
        }
        // printf("\n");
    }
    // printf("d[%d][%d]=%d\n",N,N,d[N][N]);
    return d[N][N];
}

int main()
{
#ifdef WFX
freopen("in.txt","r", stdin);
#endif
    while(scanf("%s",a+1) != -1)
    {
        memset(d,0,sizeof(d));
        int Len = strlen(a+1);
        for(int i=Len,j=1; i>=1; --i,++j) b[j] = a[i] = tolower(a[i]);
        b[Len+1] = 0;
        // puts(a+1);
        // puts(b+1);
        printf("%d\n", Len - dp(Len));
    }
   
    return 0;
}
