/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
*/

/*
����˼·��
������ջ_data,_min:
_data�������ջ�е����ݣ�
_min��ջ��Ԫ�ر���_dataջ�е�ǰ����СԪ�ء�
�������Ϊ:
1.����ջ����push�У������ǰ����ջ�е�����С�ڵ��ڵ�ǰջ�е�
  ��СԪ�أ��򽫸�Ԫ�ش���_dataջ�󣬻�Ҫ����_minջ��Ҳ����Ҫ����
  _min��ջ��ʼ��Ϊ��ǰ_dataջ�е���СԪ�ء�
2.�ڳ�ջ����pop()�У������ǰ��ջ��Ԫ����ջ�е���СԪ�أ���Ҫ����
  Ԫ�ش�_minջ�е�����ֻ���_minջ����һ��pop()�����Ϳ����ˡ� 
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

