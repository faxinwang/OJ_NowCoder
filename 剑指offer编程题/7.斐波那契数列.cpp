/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
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


