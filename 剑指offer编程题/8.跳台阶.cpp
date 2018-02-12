/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/ 

/*
解题思路：
其实是一个斐波那契数列。
考虑青蛙到达第i层的方法种数：可以从第i-1层跳一层到达， 也可以从第i-2层一次跳2层到达。
假设青蛙到达第i层的方法数为f[i]，则f[i] = f[i-1] + f[i-2]。
另外，f[1]=1, f[2]=2. i从1开始.
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
