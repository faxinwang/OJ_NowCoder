/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该
栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压
入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可
能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/ 


/*
解题思路：
用一个辅助栈s来测试popV的弹出序列是否合法,具体操作过程如下：
1.设置一个变量popIdx记录当前应该出栈的元素的位置,初始值为0.
2.按入栈顺序将元素一个一个的放入辅助栈s中
3.检查s的栈顶元素是否等于popV[popIdx],也就是检查当前栈顶元素
  是否是当前该出栈的元素,如果是,则将该元素从辅助栈s中弹出,并
  将标记位popIdx后移一位来指示下一个应该出栈的元素. 重复这一步
  操作,直到s的栈顶元素不是当前应该出栈的元素. 
4.最后,如果辅助栈s为空,说明弹出序列popV是入栈序列pushV的一个
  合法出栈序列.
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        for(int i=0,n=pushV.size(), popIdx=0; i<n; ++i){
            s.push(pushV[i]);
            while(!s.empty() && s.top() == popV[popIdx]){
                s.pop();
                ++popIdx;
            }
        }
        return s.empty();
    }
};
