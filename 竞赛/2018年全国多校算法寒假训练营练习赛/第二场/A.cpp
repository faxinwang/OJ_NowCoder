/*
链接：https://www.nowcoder.com/acm/contest/74/A
来源：牛客网

题目描述 
小鱼儿吐泡泡，嘟嘟嘟冒出来。小鱼儿会吐出两种泡泡：大泡泡"O"，小泡泡"o"。
两个相邻的小泡泡会融成一个大泡泡,两个相邻的大泡泡会爆掉。
（是的你没看错，小气泡和大气泡不会产生任何变化的，原因我也不知道。）
例如:ooOOoooO经过一段时间以后会变成oO。

输入描述:
数据有多组，处理到文件结束。
每组输入包含一行仅有'O'与'o'组成的字符串。

输出描述:
每组输出仅包含一行，输出一行字符串代表小鱼儿吐出的泡泡经过融合以后所剩余的泡泡。

示例1
输入
ooOOoooO

输出
oO

说明
自左到右进行合并

备注:
对于100%的数据，
字符串的长度不超过100。

解题思路：
直接模拟合并的过程即可。
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	string s;
	while(cin>>s){
		vector<char> v;
		v.reserve(s.size());
		for(int i=s.size()-1; i>=0; --i) v.push_back(s[i]);
		bool end = true;
		do{
			end = true;
			for(int i=v.size()-1; i>=0;--i){
				if(v[i] == v[i-1]){
					end = false;
					if(v[i]=='o'){
						v[i-1] = 'O';
						v.erase(v.begin()+i);
						break;
					}else{
						v.erase(v.begin()+i-1, v.begin()+i+1);
						break;
					}
				}
			}
//			for(int i=v.size()-1; i>=0; --i) printf("%c",v[i]);
//			cout<<endl;
		}while(!end);
		
		for(int i=v.size()-1; i>=0; --i) printf("%c",v[i]);
		cout<<endl;
	}
	
	return 0;
}