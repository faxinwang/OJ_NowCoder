/*
���ӣ�https://www.nowcoder.net/acm/contest/76/H
��Դ��ţ����

��Ŀ���� 
���������Ӯ���Լ��ľƣ������Լ����᲻�ã����Ծ�ˣ������Ƥ���Ժ���˵�����䲻�У�
�������ĵģ������˵����1-8��ȫ�����Ҿ�����ȣ���ξ���ˣ�㣬���ܰ�����ô��

��������:
��

�������:
1~8��ȫ���У�����ȫ���е�˳�������ÿ�н�β�޿ո�

ʾ��1
����
No_Input

���
Full arrangement of 1~8

��ע:
1~3��ȫ����  ��
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/ 
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[]={1,2,3,4,5,6,7,8};

int main(){
	do{
		for(int i=0;i<7; ++i) printf("%d ",a[i]);
		printf("%d\n",a[7]);
	}while(next_permutation(a,a+8));
	
	return 0;
}
