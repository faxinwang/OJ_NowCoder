/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

/*
解题思路：
方法一: 
统计逐位与运算中结果为真的次数. 


方法二:
通过 n = n&(n-1) 语句每次将n的二进制数中的最右边的1变成0,
操作的次数即为n的二进制数中1的个数
*/


//方法一 
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt=0;
         for(int i=0; i<32; ++i) n&(1<<i)? ++cnt : 0;
         return cnt;
     }
};

//方法二 
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt=0;
         for(; n ; ++cnt) n = n&(n-1);
         return cnt;
     }
};
