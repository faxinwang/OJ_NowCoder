/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的
前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/ 


/*
解题思路：
前序序列中的数据：[rootNode,[left sub tree] , [right sub tree] ] 
中序序列中的数据：[[left sub tree] , rootNode, [right sub tree]] 
因此，可以解析出左子树中的数据，放到preLeft, vinLeft中，用于递归构建
左子树，解析出右子树中的数据放到 preRight, vinRight中，用于递归恢复
右子树，构建完成后返回树根结点的地址。
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0) return 0; //重建完成 
		vector<int> preLeft,preRight;
        vector<int> vinLeft,vinRight;
        bool found = 0;
        //解析出当前结点的左右子树中的数据 
        for(int i=0,n=vin.size(); i<n; ++i){
            if(vin[i] == pre[0]){
                found = 1; //找到了根节点。 
                continue;
            }
            //在找到根节点之前，vin[i]是左子树中的数据
			//找到根节点之后，vin[i]是右子树中的数据 
			found? vinRight.push_back(vin[i]) : vinLeft.push_back(vin[i]);
        }
        for(int i=1,n=pre.size(); i<n; ++i){
            preLeft.size() < vinLeft.size() ? preLeft.push_back(pre[i]) : preRight.push_back(pre[i]);
        }
        TreeNode *root = new TreeNode(pre[0]);
        //递归构建左子树 
        root->left = reConstructBinaryTree( preLeft, vinLeft );
        //递归构建右子树
        root->right = reConstructBinaryTree( preRight, vinRight );
        return root; //返回根节点 
    }
};
