/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/ 


/*
解题思路：
1.首先判断A,B是否为空，若有一个为空， 则根据题意直接返回false 
2.若A,B均不为空，则首先判断B是否是A的子树，如果是，则返回true.
3.在A的左子树中递归查找是否存在子结构B ，若找到就返回true 
4.在A的右子树中递归查找是否存在子结构B ，若找到就返回true 
5.返回false，A中不存在子结构B

需要编写一个辅助函数equal(TreeNode *rt1, TreeNode *rt2)判断树rt1与rt2是否相同。
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool equal(TreeNode* rt1, TreeNode* rt2){
        if(rt2 == 0) return true; 
        if(rt1 == 0) return false;
        if(rt1->val != rt2->val) return false;
        return isSubtree(rt1->left, rt2->left) && isSubtree(rt1->right, rt2->right);
    }
    
    bool HasSubtree(TreeNode* rt1, TreeNode* rt2){
		if(rt1==0 || rt2 == 0) return false;
        return equal(rt1, rt2) || 
            HasSubtree(rt1->left, rt2) || 
            HasSubtree(rt1->right, rt2);
    }
};
