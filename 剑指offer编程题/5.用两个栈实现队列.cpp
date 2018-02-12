/*
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/ 

/*
����˼·��
stack1�����ݣ�stack2��Ϊ��ת����,�������Ϊ��
ÿ����������push����ʱֱ�Ӵ���stack1�У�
ÿ����Ҫpop���ݳ�����ʱ�����ڸ�������stack1����ײ���
��Ҫ��stack1������ȫ��pop������push��stack2����ʱ
stack1��Ͷ˵�����������stack2�Ķ��ˣ���һ�������ݴ�
�������Ҫ�����е����ݣ�Ȼ��stack2�е�����һ��һ��pop
������push��stack1�У��ָ���ԭ�е�˳��Ȼ���ٷ��ظղ�
�ݴ�����ݡ�
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()) stack2.push(stack1.top()), stack1.pop();
        int front = stack2.top();
		stack2.pop();
		while(!stack2.empty()) stack1.push(stack2.top()), stack2.pop();
		return front;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
