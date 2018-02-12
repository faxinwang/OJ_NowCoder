/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/ 

/*
解题思路：
n为偶数: base^n = base^(n/2) * base^(n/2)
n为奇数: base^n = base^(n/2) * base^(n/2) * base

注意点：
1.当指数为负数时，基数不能为0， 否则会出现分母为0
2.负数向右移动最小变为-1，不会变为0,所以当exponent为负数
  时，要将其转换为相反数，否则会死循环. 

*/
class Solution {
public:
	double Power(double base, int exponent) {
    	if(exponent==0) return 1;
        int flag = exponent<0? exponent=-exponent : 0;
       // if(base == 0 && exponent<0) throw new RuntimeException("分母不能为0");
        double ans = 1;
        while(exponent){
            if(exponent&1) ans *= base;
            base *= base;
            exponent >>=1; //负数向右位移永远不会变为0，最小变为二进制位全为1，即-1 
        }
        return flag? 1/ans : ans;
    }
};
