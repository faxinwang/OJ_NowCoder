/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
*/ 

/*
����˼·��
��ʵ��һ��쳲��������С�
�������ܵ����i��ķ������������Դӵ�i-1����һ�㵽� Ҳ���Դӵ�i-2��һ����2�㵽�
�������ܵ����i��ķ�����Ϊf[i]����f[i] = f[i-1] + f[i-2]��
���⣬f[1]=1, f[2]=2. i��1��ʼ.
*/

class Solution {
public:
    int jumpFloor(int number) {
        int a = 1, b = 2, sum;
        if(number ==1 || number == 2) return number==1? a : b;
        for(int i=3; i<=number; ++i){
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
};
