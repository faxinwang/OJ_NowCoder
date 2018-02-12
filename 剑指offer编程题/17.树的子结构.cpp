/*
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
*/ 


/*
����˼·��
1.�����ж�A,B�Ƿ�Ϊ�գ�����һ��Ϊ�գ� ���������ֱ�ӷ���false 
2.��A,B����Ϊ�գ��������ж�B�Ƿ���A������������ǣ��򷵻�true.
3.��A���������еݹ�����Ƿ�����ӽṹB �����ҵ��ͷ���true 
4.��A���������еݹ�����Ƿ�����ӽṹB �����ҵ��ͷ���true 
5.����false��A�в������ӽṹB

��Ҫ��дһ����������equal(TreeNode *rt1, TreeNode *rt2)�ж���rt1��rt2�Ƿ���ͬ��
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
