/*
链接：https://www.nowcoder.com/acm/contest/106/J
来源：牛客网

时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32768K，其他语言65536K
64bit IO Format: %lld

题目描述
It’s universally acknowledged that there’re innumerable trees in the campus of HUST.
And there are many different types of trees in HUST, each of which has a number represent its type. 
The doctors of biology in HUST find 4 different ways to change the tree’s type x into a new type y:
1.    y=x+1
2.    y=x-1
3.    y=x+f(x)
4.    y=x-f(x)

The function f(x) is defined as the number of 1 in x in binary representation. For example, f(1)=1, f(2)=1, 
f(3)=2, f(10)=2.

Now the doctors are given a tree of the type A. The doctors want to change its type into B. Because each 
step will cost a huge amount of money, you need to help them figure out the minimum steps to change the 
type of the tree into B. 

Remember the type number should always be a natural number (0 included).

输入描述:
One line with two integers A and B (0<=A,B<=1e6), the init type and the target type.

输出描述:
You need to print a integer representing the minimum steps.

示例1
输入
5 12

输出
3

说明
The minimum steps they should take: 5->7->10->12. Thus the answer is 3.

解题思路:
将x到y的四种变换看成是x到y的四条路径, 直接BFS 配合优先级队列即可, 步数小的优先.
为了简化代码, 这里使用了函数指针数组.

*/

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 1e6+5;

int A,B;
bool vis[maxn];

struct Node
{
    int type, step;
    Node(int t=0,int s=0):type(t),step(s){}
    bool operator<(const Node& nd)const { return step > nd.step; }
};

int F(int x)
{
    int cnt =0;
    while(x)
    {
        cnt += x&1;
        x>>=1;
    }
    return cnt;
}

int f1(int x){return x+1; }
int f2(int x){return x-1; }
int f3(int x){return x+F(x); }
int f4(int x){return x-F(x); }

//函数指针数组
int (*func[4])(int x) = {f1,f2,f3,f4};

priority_queue<Node> Q;

int BFS(int A, int B)
{
    if(A == B) return 0;
    Q.push(Node(A,0));
    vis[A] = 1;
    while(!Q.empty())
    {
        
        Node p = Q.top(); Q.pop();
        for(int i=0; i<4; ++i)
        {
            int type = func[i](p.type);
            if(type  == B) return p.step + 1;
            if(!vis[type])
            {
                vis[type] = 1;
                Q.push(Node(type, p.step +1));
            }
        }
    }
    return 0;
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    int A,B;
    scanf("%d%d",&A,&B);
    printf("%d\n", BFS(A,B));

    return 0;
}