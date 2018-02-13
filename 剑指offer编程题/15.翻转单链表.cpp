/*
输入一个链表，反转链表后，输出链表的所有元素。
*/

/*
解题思路：
逐个取出链表中的元素，采用头插法创建新链表。
设置两个指针p1和p2,开始时p1指向链表头pHead，p2指向表头的next结点。
然后用一个变量nxt保存p2的next值，也就是第三个结点的地址，然后让
p2->next指向p1, 让p1指向p2, 让p2指向刚才保存的临时变量nxt,直到p2
变为空值，此时链表已翻转完成，并且p1指向了最后一个结点，也就是新
的表头。

需要注意的是，由于pHead现在变成了表未，所以其next值应该为0. 我提交
的时候就是忘记了这一步导致超时，原因就是访问链表元素时不能正常终止。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead==0) return 0;
        ListNode* p1 = pHead;
        ListNode* p2 = pHead->next;
        pHead->next = 0; //不要忘记头结点将变成尾结点，所以next要置为零
        while(p2){
            ListNode* nxt = p2->next; //保存p2的next值，避免链表断开
            p2->next = p1;
            p1 = p2;
            p2 = nxt;
        }
        return p1;
    }
};