/*
https://www.nowcoder.net/question/next?pid=4111169&qid=76262&tid=13490337
����һ���ַ��������㽫�ַ������±��룬���������ַ��滻�ɡ��������ֵĸ���+�ַ�����
�����ַ���AAAABCCDAA�ᱻ�����4A1B2C1D2A��

��������:
ÿ�������������1����������
ÿ��������������ֻ��һ���ַ������ַ���ֻ������дӢ����ĸ�����Ȳ�����10000��

�������:
����������ַ���

��������1:
AAAABCCDAA

�������1:
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
