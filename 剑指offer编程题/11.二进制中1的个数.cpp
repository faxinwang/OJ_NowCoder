/*
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

/*
����˼·��
����һ: 
ͳ����λ�������н��Ϊ��Ĵ���. 


������:
ͨ�� n = n&(n-1) ���ÿ�ν�n�Ķ��������е����ұߵ�1���0,
�����Ĵ�����Ϊn�Ķ���������1�ĸ���
*/


//����һ 
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt=0;
         for(int i=0; i<32; ++i) n&(1<<i)? ++cnt : 0;
         return cnt;
     }
};

//������ 
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt=0;
         for(; n ; ++cnt) n = n&(n-1);
         return cnt;
     }
};
