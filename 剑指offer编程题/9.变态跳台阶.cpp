/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/ 

/*
解题思路：
设想青蛙在第i层，则青蛙有i种途径直接到达该层，分别是从第j层一次跳i-j层到达。 
其中 0<= j < i, 设青蛙到达第i层的方法数有d[i]中，则 d[i] = sum( d[j] ), 0<=j<i. 
又有：d[0] = 1, d[1] = 1 
这样，通过递推即可计算出d[i]

简化：
f(n-1) = f(0) + f(1)+f(2)+f(3) + ... + f((n-1)-1) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2)

f(n) = f(0) + f(1) + f(2) + f(3) + ... + f(n-2) + f(n-1) = f(n-1) + f(n-1)

可以得出：

f(n) = 2*f(n-1) 

因此可以使用O(n)时间计算出结果。 
*/
class Solution {
public:
    int jumpFloorII(int number) {
		int *d = new int[number+1];
        d[0] = 1;
        d[1] = 1;
        for(int i=2; i<=number; ++i){
            d[i] = 0;
            for(int j=i-1; j>=0; --j) d[i] += d[j];
        }
        int ans = d[number];
        delete[] d;
        return ans;
    }
};
