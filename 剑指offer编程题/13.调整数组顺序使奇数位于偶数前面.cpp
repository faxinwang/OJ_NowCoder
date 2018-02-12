/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组
的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间
的相对位置不变。
*/

/*
解题思路：
对数组遍历两次:
第一次，将所有的奇数移动到数组前面，将所有的偶数取出来放到一个临时数组
第二次，将所有的偶数复制到数组后面。
时间复杂度O(n)

也可以用冒泡排序的思路，将所有的奇数视作相等，所有的偶数视作相等，并且奇数小于偶数 
不过这样时间复杂度为O(n^2)
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> tmp;
      	tmp.reserve(array.size());
        int k=0;
        for(int i=0,n=array.size(); i<n; ++i){
            if(array[i] & 1) {
                array[k++] = array[i];
            }else{
                tmp.push_back(array[i]);
            }
        }
        for(int n=array.size(), i=0; k<n; ++k,++i) array[k] = tmp[i];
    }
};
