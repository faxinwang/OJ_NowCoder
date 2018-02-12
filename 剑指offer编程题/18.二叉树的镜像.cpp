/*
操作给定的二叉树，将其变换为源二叉树的镜像。

二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/ 


/*
解题思路：
1.首先判断给定结点是否为空指针， 是空指针就直接返回。
2.然后交换给定结点的左右指针的值。
3.递归对左右子树镜像镜像操作(第1,2步)、 
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
