/*
https://www.nowcoder.net/question/next?pid=4111169&qid=76262&tid=13490337
给定一个字符串，请你将字符串重新编码，将连续的字符替换成“连续出现的个数+字符”。
比如字符串AAAABCCDAA会被编码成4A1B2C1D2A。

输入描述:
每个测试输入包含1个测试用例
每个测试用例输入只有一行字符串，字符串只包括大写英文字母，长度不超过10000。

输出描述:
输出编码后的字符串

输入例子1:
AAAABCCDAA

输出例子1:
4A1B2C1D2A
*/ 

#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;

string itos(int n){
	string s="";
	while(n){
		s += n % 10 + '0'; 
		n /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	string s,ans;
	cin>>s;
	for(int i=0,cnt=0,n=s.size();i <n; ++i){
		if(s[i]==s[i+1]) ++cnt;
		else{
			ans += itos(cnt+1) + s[i];
			cnt=0;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
