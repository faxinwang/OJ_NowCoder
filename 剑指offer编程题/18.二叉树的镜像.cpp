/*
���������Ķ�����������任ΪԴ�������ľ���

�������ľ����壺Դ������ 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	���������
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/ 


/*
����˼·��
1.�����жϸ�������Ƿ�Ϊ��ָ�룬 �ǿ�ָ���ֱ�ӷ��ء�
2.Ȼ�󽻻�������������ָ���ֵ��
3.�ݹ�������������������(��1,2��)�� 
*/


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/

class Solution {
public:
    void Mirror(TreeNode *root) {
		if(root ==0) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        Mirror(root->left);
        Mirror(root->right);
    }
};
