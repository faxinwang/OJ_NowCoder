/*
����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
*/

/*
����˼·��
����˵���ַ�����
��һ�֣� ÿ��ȡ��һ������Ȼ�󽫸������뵽vector����ǰ�棬�����õ���˳
�������ĿҪ���˳�򣬵�ʱ��vector��ǰ�������Ҫ�ķ�O(N)��ʱ����������
��N�Σ�ʱ�临�Ӷ���O(N^2) 

�ڶ��֣�ÿ��ȡ��һ������Ȼ�󽫸������뵽vector������棬�����ó�������
˳������ĿҪ���˳���෴����ÿ�β����ʱ����O(1)�� Ȼ��ֻ��Ҫ����O(N)��
ʱ�佫˳����������Ϳ����� 
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
