/*
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*/ 

/*
����˼·��
nΪż��: base^n = base^(n/2) * base^(n/2)
nΪ����: base^n = base^(n/2) * base^(n/2) * base

ע��㣺
1.��ָ��Ϊ����ʱ����������Ϊ0�� �������ַ�ĸΪ0
2.���������ƶ���С��Ϊ-1�������Ϊ0,���Ե�exponentΪ����
  ʱ��Ҫ����ת��Ϊ�෴�����������ѭ��. 

*/
class Solution {
public:
	double Power(double base, int exponent) {
    	if(exponent==0) return 1;
        int flag = exponent<0? exponent=-exponent : 0;
       // if(base == 0 && exponent<0) throw new RuntimeException("��ĸ����Ϊ0");
        double ans = 1;
        while(exponent){
            if(exponent&1) ans *= base;
            base *= base;
            exponent >>=1; //��������λ����Զ�����Ϊ0����С��Ϊ������λȫΪ1����-1 
        }
        return flag? 1/ans : ans;
    }
};
