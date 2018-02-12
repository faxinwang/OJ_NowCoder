/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递
增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是
否含有该整数。
*/

/*
解题思路:
从矩阵的右上角开始往左下角查找，
1.如果 target 等于当前元素，则查找结束
2.如果 target 大于当前元素，则target也大于该行当前位置左边的所有元素和该列上面的所有元素，往下走 ++r
3.如果 target 小于当前元素, 既然target是从上面走下来的，那么target肯定大于它上面的数字，但不一定
  大于它左边的数字，所以现在往左边走，--c 
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int r=0, c=array[0].size()-1;
        while(r <array.size() && c>=0){
            if(target == array[r][c]) return true;
            else if(target > array[r][c]) ++r;
            else --c;
        }
        return false;
    }
};
