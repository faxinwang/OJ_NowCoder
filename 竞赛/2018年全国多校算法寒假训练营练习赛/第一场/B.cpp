/*
链接：https://www.nowcoder.com/acm/contest/67/B
来源：牛客网

 L一直喜欢玩游戏王这款声控印卡游戏，使用一套连锁式削血卡组便可战无不胜。每当陷入危机即将败北之际，
L便会高呼“最强的决斗者一切都是必然的！”，然后发动闪光印卡技能，直接翻盘，伤害不多不少，正好足够击败对手。

    发动闪光印卡技能后，L抽取一张牌，然后微微一笑。接着L以一定顺序打出若干张牌，造成的伤害正好等于对方的
生命值。每一张牌都有其发动速度以及效果。如果后发动的一张牌的发动速度不小于前一张牌，则后发动的那张牌会
在前一张牌后进行连锁发动，这张牌的连锁数就是连锁发动的编号。不进行连锁发动的牌，连锁数为1。同一连锁中的牌，
后发动的牌先生效。

如下图，5张牌的速度分别为（1,2,2,2,3），因此它们进行连锁发动。连锁数分别为（1,2,3,4,5），
因为连锁中的牌，后发动的先生效，所以，生效顺序为（5,4,3,2,1）。

    为简化问题，我们假设发动的牌的效果有如下几种：

    1. 对对方造成X点伤害

    2. 对对方造成这张牌的连锁数乘X点的伤害

    3. 同一连锁中的牌全部无效

    4. 连锁中的前一张牌无效

    现在你知道L发动牌的效果、速度和顺序，求L能对对方造成多少伤害。


输入描述:
数据有多组，处理到文件结束
第一行一个整数n，代表L发动了多少张牌。
接下来n行，前两个数是两个整数s和t，代表牌的发动速度和效果（数字对应上述4类效果）。如果是第1、2类效果，
则紧接着一个整数x，代表效果中的X的数值。

输出描述:
每组数据输出一行，一个整数，代表L能对对方造成的伤害。

示例1
输入
9
1 1 300
2 2 400
2 3
2 2 500
1 1 1000
3 4
2 1 600
3 3
3 4

输出
2600

说明
一共发动了9张牌，前四张为一次连锁发动，第四张先生效，连锁数为4，造成4*500伤害。接着第三张牌生效，
使第一二张牌无效。第五六张牌为一次连锁发动，第六张牌先生效，使其连锁的前一张牌，即第五张牌无效。
第七八九张牌为一次连锁发动，第九张牌先生效，使连锁中的前一张牌，即第八张牌无效。接着第七张牌生效，造成600伤害。
总伤害为4*500+600=2600伤害。

备注:
对于100%的数据，
1 <= n,x <= 1000;
1 <= s <= 3;
1 <= t <= 4。


解题思路：
序号连续的几张牌一起发动效果，所以在输入的时候，一旦发现当前输入的序号不与上一张牌连续，就立刻发动前面所有牌，
并计算出其造成的伤害值，累加起来。在计算牌的发动效果的时候，用到了栈。
*/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct Card{
	int s,t,x;
	Card(int s,int t,int x):s(s),t(t),x(x){};
};

int fun(vector<Card>& v){
	int hurt = 0;
	while(v.size()){
		switch(v.back().t){
			case 1:
				hurt += v.back().x; 
			//	printf("hurt:%d\n",v.back().x);
				break;
			case 2:
				hurt += v.back().x * v.size();
			//	printf("hurt:%d\n",v.back().x * v.size());
				break;
			case 3:
				return hurt;
				break;
			case 4:
				v.pop_back();
				break;
		}
		if(v.size()) v.pop_back();
	}
	return hurt;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 

	int n,s,t,x;
	while(scanf("%d",&n) != -1){
		vector<Card> v;
		int hurt=0;
		v.reserve(n);
		for(int i=0; i<n ;++i){
			scanf("%d%d",&s,&t);
			if(t<=2) scanf("%d",&x);
			
			
			if(v.size()==0){
				v.push_back(Card(s,t,x));
			}else{
				if(s < v.back().s){
					hurt += fun(v);
		//			printf("size:%d hurt:%d\n",v.size(),hurt);
					v.clear();
				}
				v.push_back(Card(s,t,x));
			}
		}
		hurt += fun(v);
		
		printf("%d\n",hurt);
	}
	
	
	return 0;
} 