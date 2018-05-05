/*
链接：https://www.nowcoder.com/acm/contest/118/G
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld
题目描述 

程序员A和B要去一起坐火车，这列火车上的每一排都有4个座位，而且这四个座位
被过道分成了两半。当A和B到了车上时，一些位子已经有人了。
A和B是好基友，于是他们想要找一对连在一起的座位。两个连在一起的座位是同一排但是不被过道隔开的两个座位。给定一列火车上
的座位情况，请你寻找一下能否找到一对连座？

输入描述:
每组样例第一行为一个整数n，1<=n<=1000，表示火车一共有n排座位。
之后的n行每行为一个含有五个字符的字符串，第i个字符串的五个字符表示第i排座位的情况。每一个字符串的第三个字符都为字符‘|’，
表示过道，其余每个字符表示一个座位的占用情况。字符'O'表示座位为空，字符'X'表示座位上已经有人，即被占用。

输出描述:
如果能够找到一组连座，则先输出一行字符串“YES”(不要输出引号)在第一行，在接下来的n
行输出车的座位情况，除了A和B的座位用字符'+'表示，其余输出格式与输入格式中车的座位情况一致。
如果不能够找到一组连座，仅输出一行“NO”（不要输出引号）即可。
有多组座位安排方式时，将A和B安排在前面的排，如果同一排还有两组可行解，选择将A和B排在左边。
例如一组车的情况为这样的时候，应该将其安排为箭头右边的情况。
OO|OO --> ++|OO
OO|OO --> OO|OO

示例1
输入
6
OO|OX
XO|XX
OX|OO
XX|OX
OO|OO
OO|XX
4
XO|OX
XO|XX
OX|OX
XX|OX
5
XX|XX
XX|XX
XO|OX
XO|OO
OX|XO


输出
YES
++|OX
XO|XX
OX|OO
XX|OX
OO|OO
OO|XX
NO
YES
XX|XX
XX|XX
XO|OX
XO|++
OX|XO


说明
注意
第一组样例中，下面的安排是不合法的。
O+|+X
XO|XX
OX|OO
XX|OX
OO|OO
OO|XX

解题思路:
每输入一行, 就判断该行是否有符合要求的座位. 如果有, 修改相应的字符串, 保存到vector中.

*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

vector<string> v;
char row[5];

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    
    int n;
    while(~scanf("%d",&n))
    {
        bool found = false;
        v.clear();

        for(int i=0;i<n; ++i)
        {
            scanf("%s", row);
            if(!found && row[0] == 'O' && row[1] == 'O') //查看改行左边是否有两个空位, 是则占用
            {
                row[0] = row[1] = '+';
                found = true;
            }
            else if(!found && row[3] =='O' && row[4]=='O') //查看该行右边是否有两个空位, 是则占用
            {
                row[3] = row[4] = '+';
                found = true;
            }
            v.push_back(string(row));
        }
        printf("%s\n", found? "YES" : "NO");
        for(int i=0; i<n; ++i) cout<<v[i]<<endl; //输出座位情况
    }

    return 0;
}