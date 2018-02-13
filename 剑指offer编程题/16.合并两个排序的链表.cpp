/*
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则。
*/

/*解题思路:
思路有点像归并排序，不过过程需要细心，有几点需要注意：
1.当给定的连个链表都为空时，直接返回0
2.创建链表头时，要用两个表头里面较小的那个数，
  需要注意的是，在访问表头结点里面的数据时一定要判断指针是否为空，
  否则会引发空指针异常。
3.当到达某一个链表末尾时，直接可直接将另一个链表剩下的部分拷贝到
  新创建的链表。
4.给先创建的链表尾元素的next值置0

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if(pHead1==0 && pHead2==0) return 0;
        ListNode* newHead = 0;
        if(pHead1 && pHead2){
            newHead = new ListNode(min(pHead1->val,pHead2->val));
            (pHead1->val <= pHead2->val)? pHead1=pHead1->next : pHead2=pHead2->next;
        }else if(pHead1){
            newHead = new ListNode(pHead1->val);
            pHead1 = pHead1->next;
        }else if(pHead2){
            newHead = new ListNode(pHead2->val);
            pHead2 = pHead2->next;
        }
        ListNode* p = newHead;
        while(pHead1 && pHead2){
            if(pHead1->val <= pHead2->val){
                p->next = new ListNode(pHead1->val);
                pHead1 = pHead1->next;
            }else{
                p->next = new ListNode(pHead2->val);
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        while(pHead1){
            p->next = new ListNode(pHead1->val);
            pHead1 = pHead1->next;
            p = p->next;
        }
        while(pHead2){
            p->next = new ListNode(pHead2->val);
            pHead2 = pHead2->next;
            p = p->next;
        }
        p->next = 0;
        return newHead;
    }
};
