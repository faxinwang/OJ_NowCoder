/*
����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������
ǰ���������������Ľ���ж������ظ������֡���������ǰ���������
{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
*/ 


/*
����˼·��
ǰ�������е����ݣ�[rootNode,[left sub tree] , [right sub tree] ] 
���������е����ݣ�[[left sub tree] , rootNode, [right sub tree]] 
��ˣ����Խ������������е����ݣ��ŵ�preLeft, vinLeft�У����ڵݹ鹹��
���������������������е����ݷŵ� preRight, vinRight�У����ڵݹ�ָ�
��������������ɺ󷵻��������ĵ�ַ��
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
        if(pre.size()==0) return 0; //�ؽ���� 
		vector<int> preLeft,preRight;
        vector<int> vinLeft,vinRight;
        bool found = 0;
        //��������ǰ�������������е����� 
        for(int i=0,n=vin.size(); i<n; ++i){
            if(vin[i] == pre[0]){
                found = 1; //�ҵ��˸��ڵ㡣 
                continue;
            }
            //���ҵ����ڵ�֮ǰ��vin[i]���������е�����
			//�ҵ����ڵ�֮��vin[i]���������е����� 
			found? vinRight.push_back(vin[i]) : vinLeft.push_back(vin[i]);
        }
        for(int i=1,n=pre.size(); i<n; ++i){
            preLeft.size() < vinLeft.size() ? preLeft.push_back(pre[i]) : preRight.push_back(pre[i]);
        }
        TreeNode *root = new TreeNode(pre[0]);
        //�ݹ鹹�������� 
        root->left = reConstructBinaryTree( preLeft, vinLeft );
        //�ݹ鹹��������
        root->right = reConstructBinaryTree( preRight, vinRight );
        return root; //���ظ��ڵ� 
    }
};
