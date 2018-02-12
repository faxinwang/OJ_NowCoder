/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩
形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/ 

/*
解题思路：
这题我感觉是d[i] = d[i-2] * 2 + d[i-1] 
但答案是斐波那契 d[i] = d[i-2] + d[i-1] 
*/

class Solution {
public:
    int rectCover(int number) {
		int *d = new int[number+1];
        d[1] = 1;
        d[2] = 2;
        for(int i=3; i<=number; ++i){
            d[i] = d[i-2] + d[i-1];
        }
        int ans = d[number];
        delete[] d;
        return ans;
    }
};
