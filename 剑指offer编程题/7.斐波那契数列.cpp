/*
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
n<=39
*/ 

class Solution {
public:
    int Fibonacci(int n) {
		int a=0,b=1,sum = a+b;
        if(n <=0) return 0;
        for(int i=3;i<=n; ++i){
            a = b;
            b = sum;
            sum = a + b;
        }
        return sum;
    }
};


