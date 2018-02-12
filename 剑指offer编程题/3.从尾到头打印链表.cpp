/*
输入一个链表，从尾到头打印链表每个节点的值。
*/

/*
解题思路：
这里说两种方法：
第一种： 每次取出一个数，然后将该数插入到vector的最前面，这样得到的顺
序就是题目要求的顺序，但时在vector最前面插入需要耗费O(N)的时间这样共操
作N次，时间复杂度是O(N^2) 

第二种：每次取出一个数，然后将该数插入到vector的最后面，这样得出的序列
顺序与题目要求的顺序相反，但每次插入的时间是O(1)， 然后只需要花费O(N)的
时间将顺序调整过来就可以了 
*/ 

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
    	vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        for(int i=0,n=v.size(); i<n/2; ++i) swap(v[i], v[n-i-1]);
        return v;
    }
};
