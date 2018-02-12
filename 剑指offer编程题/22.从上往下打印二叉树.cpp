/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

/*
解题思路:
用队列层序遍历二叉树, 
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

