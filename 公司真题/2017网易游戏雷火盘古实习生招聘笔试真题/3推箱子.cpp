/*
https://www.nowcoder.net/question/next?pid=4111169&qid=76263&tid=13490337
���һ������������ӡ�����������Ϸ��������������һ��N*M�ĵ�ͼ�ϣ���1����ҡ�1�����ӡ�
1��Ŀ�ĵ��Լ������ϰ��������ǿյء���ҿ�������������4�������ƶ������ǲ����ƶ�����ͼ����
�ƶ����ϰ���ȥ���������������ƶ��Ƶ������ӣ�����Ҳ�ᰴ��������ƶ�һ�񣬵�Ȼ������Ҳ��
�ܱ��Ƴ���ͼ���Ƶ��ϰ�������ӱ��Ƶ�Ŀ�ĵ��Ժ���ϷĿ���ɡ����ڸ�������Ϸ��ʼ�ǳ�ʼ
�ĵ�ͼ���֣�����������������Ҫ�ƶ����ٲ����ܹ�����ϷĿ���ɡ� 

��������:
ÿ�������������1����������
��һ��������������N��M��ʾ��ͼ�Ĵ�С������0<N��M<=8��
��������N�У�ÿ�а���M���ַ���ʾ���е�ͼ������ . ��ʾ�յء�X��ʾ��ҡ�*��ʾ���ӡ�
#��ʾ�ϰ���@��ʾĿ�ĵء�
ÿ����ͼ�ض�����1����ҡ�1�����ӡ�1��Ŀ�ĵء�

�������:
���һ�����ֱ�ʾ���������Ҫ�ƶ����ٲ����ܽ���ϷĿ���ɡ���������δ�ɲ��˵�ʱ�����-1��

��������1:
4 4
....
..*@
....
.X..
6 6
...#..
......
#*##..
..##.#
..X...
.@#...

�������1:
3
11


����˼·��
����������Ϊ����װ��������̵ĳ�ʼ״̬���������ӵ���Ŀ�ĵص�״̬��
ÿһ��״̬�����˵��ƶ����������չ���ĸ��µ�״̬����Ҫ�������¹����ж�
����չ����״̬�Ƿ�Ϸ���
1.�˵�λ�ò���Խ��
2.��������������ӣ�����ҲҪ�ƶ�
3.���ӵ�λ�ò���Խ��
4.�˺����Ӳ������ϰ��� 
������Ҫ�����ٲ���������ʹ�ý���BFS������
*/

#include<iostream>
#include<cstdio>
#include<queue>
#define maxn 10
using namespace std;

int N,M;
bool vis[maxn][maxn][maxn][maxn]; //vis[i][j][x][y]��ʾС����i,j,������x,y��״̬�Ѿ����ʹ���
int dir[4][2]={0,1,0,-1,1,0,-1,0};
char mp[maxn][maxn];
struct Point{
	int x,y;//�˵����� 
	int bx,by; //���ӵ����� 
	int step;//���� 
	Point(int x,int y,int bx,int by,int step):x(x),y(y),bx(bx),by(by),step(step){}
};

//����ΪС�˵���������ӵ�����
int BFS(int x,int y,int bx,int by){
	queue<Point> Q;
	Q.push(Point(x,y,bx,by,0));
	vis[x][y][bx][by] = 1;
	while(!Q.empty()){
		Point p = Q.front(); Q.pop();
		if(mp[p.bx][p.by] == '@') return p.step; //����Ŀ�ĵ� 
		for(int i=0;i<4;++i){
			Point nxt = p;
			nxt.x += dir[i][0];
			nxt.y += dir[i][1];
			if(nxt.x < 0 || nxt.x>=N || nxt.y<0 || nxt.y >=M) continue; //Խ�� 
			if(mp[nxt.x][nxt.y] == '#') continue; //�˲������ϰ��� 
			//��������������ӣ�������ҲҪ�ƶ���Ȼ���жϸ��ƶ��Ƿ�Ϸ� 
			if(nxt.x==nxt.bx && nxt.y ==nxt.by){
				nxt.bx += dir[i][0];
				nxt.by += dir[i][1];
				if(nxt.bx <0 || nxt.bx >=N || nxt.by<0 || nxt.by>=M) continue;
			}
			if(!vis[nxt.x][nxt.y][nxt.bx][nxt.by]){
				vis[nxt.x][nxt.y][nxt.bx][nxt.by] = 1;
				++nxt.step;
				Q.push(nxt);
			}
		}
	}
	return -1;
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int x,y, bx,by;
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>mp[i][j];
			if(mp[i][j] == 'X'){
				x=i;
				y=j;
			}
			else if(mp[i][j]=='*'){
				bx = i;
				by = j;
			}
		}
	}
	cout<<BFS(x,y,bx,by)<<endl;
	
	return 0;
}
