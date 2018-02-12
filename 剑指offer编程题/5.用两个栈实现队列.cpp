/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/ 

/*
解题思路：
stack1存数据，stack2作为中转工具,具体操作为：
每次往队列中push数据时直接存入stack1中，
每次需要pop数据出队列时，由于该数据在stack1的最底部，
需要将stack1的数据全部pop出来并push入stack2，这时
stack1最低端的数据正好在stack2的顶端，用一个变量暂存
这个顶端要出队列的数据，然后将stack2中的数据一个一个pop
出来并push入stack1中，恢复其原有的顺序，然后再返回刚才
暂存的数据。
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
