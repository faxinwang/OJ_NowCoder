/*
链接：https://www.nowcoder.com/acm/contest/105/B
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述 
有一个只包含大写字母和数字的字符串S，和一个6*6的字符组成的正方形如下图，正方形中恰好包含0-9和A-Z各一个字符。
正方形的一行在字符串S中的出现次数是这行6个字符在S中出现次数的总和，正方形的一列在字符串S中的出现次数是这列6个
字符在S中出现次数的总和。如果正方形中一个字符所在行的出现次数是所有行中最多，并且所在列的出现次数是所有列中最多，
这个字符是需要被找出的。

012345
6789AB
CDEFGH
IJKLMN
OPQRST
UVWXYZ

输入描述:
第一行是一个整数T(1 ≤ T ≤ 400)，表示样例的个数。
每个样例一行字符串S，长度1≤ len ≤ 500。

输出描述:
每组数据输出一行需要找出的所有字符，如果需要找出的字符有多个，所在行不同的按行从小到大排序，所在行相同的按列从小到大排序。

示例1
输入
3
13579
AADD
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ

输出
13
7ADG
0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ

解题思路:
需要理解字符矩阵中某一行(列)出现的次数是通过该行(列)中其他字符出现的次数计算出来的.

所以先要统计出字符矩阵中所有字符出现的次数,然后借此计算出所有行和列出现的次数.

然后通过出现次数最高的行(可能不唯一)和出现次数最高的列(可能不唯一)定位到需要找出的字符.

将所有找出的字符按题目要求的顺序输出即可.

*/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

char s[505];
int a[255];

string mtx[6];

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    mtx[0]="012345";
    mtx[1]="6789AB";
    mtx[2]="CDEFGH";
    mtx[3]="IJKLMN";
    mtx[4]="OPQRST";
    mtx[5]="UVWXYZ";

    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        scanf("%s",s);
        //统计所有字符出现的次数
        for(int i=0; s[i]; ++i) ++a[s[i]];

        int row[6], col[6];
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        //计算每一行每一列出现的次数
        for(int i=0; i<6; ++i)
        {
            for(int j=0; j<6; ++j) row[i] += a[mtx[i][j]];
            for(int j=0; j<6; ++j) col[i] += a[mtx[j][i]];
        }

        //找出出现次数最高的行和列
        vector<int> rr, cc;
        rr.push_back(0);
        cc.push_back(0);
        for(int i=1; i<6; ++i)
        {
            if(row[i] == row[rr.back()]) rr.push_back(i);
            else if(row[i] > row[rr.back()])
            {
                rr.clear();
                rr.push_back(i);
            }

            if(col[i] == col[cc.back()]) cc.push_back(i);
            else if(col[i] > col[cc.back()])
            {
                cc.clear();
                cc.push_back(i);
            }
        }

        //根据出现次数最高的行和列找出相应的字符.
        string ans;
        for(int i=0; i<rr.size(); ++i)
        {
            for(int j=0; j<cc.size(); ++j) ans += mtx[ rr[i] ][ cc[j] ];
        }
        cout<<ans<<endl;
    }

    return 0;
}