/*
输入一个链表，输出该链表中倒数第k个结点。
*/

/*
解题思路：
设两个指针p1,p2开始时都指向链表头listHead，然后将p1向后移动k步，
然后p1,p2同步往后移动,当p1到达链表末尾时(此时p1==0),p2就
指向了倒数第k个结点。
需要注意的问题：
1.当k==0时，直接返回0
2.当listHead==0时，直接返回0
3.当链表长度小于k是，返回0
4.当链表长度==k时，返回链表头指针listHead
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(!pListHead) return 0;
        if(k == 0) return 0;
        ListNode* p1 = pListHead;
        ListNode* p2 = pListHead;
        for(int i=0,n=k-1; i<n; ++i){
            if((p1 = p1->next) == 0) return 0;
        }
        if((p1 = p1->next) == 0) return pListHead; //链表长度等于k
        while(p1){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};