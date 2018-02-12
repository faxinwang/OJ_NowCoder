/*
解题思路：
排序题目要求是稳定排序，成绩相同时，先输入的先输出，题目描述与测试数据不相符。
用桶排序可以很好的解决该题，时间复杂度为O(N)，桶排序的思路是：
将关键字(这里是成绩)相同的放到一个vector中，后输入的直接放到相应vector中的末尾。
输出的时候
    如果是升序排序，则从0到100号桶依次输出，每一个桶中从头往后输出(保证了先输入的先输出)。
    如果是降序排序，则从100到0号桶依次输出，每一个桶中从头往后输出(保证了先输入的先输出)。

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n,op;
    string name;
    int score;
    while(cin>>n){
        cin>>op;
        vector<string> v[105];
        for(int i=0;i<n;++i){
            cin>>name>>score;
            v[score].push_back(name);
        }
        if(op){ //升序
            for(int i=0; i<=100; ++i){
                for(int j=0,n=v[i].size(); j<n; ++j) cout<<v[i][j]<<' '<<i<<endl;
            }
        }
        else{ //降序
            for(int i=100; i>=0; --i){
                for(int j=0,n=v[i].size(); j<n; ++j) cout<<v[i][j]<<' '<<i<<endl;
            }
        }
    }

    return 0;
}
