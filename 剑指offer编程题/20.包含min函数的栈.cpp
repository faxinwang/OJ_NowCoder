/*
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

/*
解题思路：
用两个栈_data,_min:
_data保存存入栈中的数据，
_min的栈顶元素保存_data栈中当前的最小元素。
具体操作为:
1.在入栈操作push中，如果当前存入栈中的数据小于等于当前栈中的
  最小元素，则将该元素存入_data栈后，还要存入_min栈，也就是要保持
  _min的栈顶始终为当前_data栈中的最小元素。
2.在出栈操作pop()中，如果当前出栈的元素是栈中的最小元素，则还要将该
  元素从_min栈中弹出，只需对_min栈进行一次pop()操作就可以了。 
*/


class Solution {
public:
    stack<int> _data;
    stack<int> _min;
    void push(int value) {
        _data.push(value);
        if(_min.empty() || value <= _min.top() ) _min.push(value);
    }
    void pop() {
        int value = _data.top();
        _data.pop();
        if(value == _min.top()) _min.pop();
    }
    int top() {
        return _data.top();
    }
    int min() {
        return _min.top();
    }
};

