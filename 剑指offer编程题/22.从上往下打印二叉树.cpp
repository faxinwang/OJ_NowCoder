/*
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
*/

/*
����˼·:
�ö��в������������, 
*/

/* 
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(0), right(0) {
	}
};
*/ 

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> v;
        queue<TreeNode*> Q;
        if(root == 0) return v;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* node = Q.front();
            Q.pop();
            v.push_back(node->val);
            if(node->left) Q.push(node->left);
            if(node->right) Q.push(node->right);
        }
        return v;
    }
};

