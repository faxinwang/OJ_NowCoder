/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/ 

/*
解题思路:
相似二叉查找树(BST)中, 左子树上的元素都小于等于根结点中的元素,
右子树上的元素都大于等于根节点中的元素, 并且左右子树又都是一个
二叉查找树.所以在一个合法的后续遍历序列 
seq: [[elements of left sub tree], [elements of right sub tree], rootElem]中,
前半部分的元素都小于等于rootElem, 后半部分的元素都大于等于rootElem.
并且前半部分和后半部分又都符合上述规则. 
根据上述规则可以很容易地写出递归函数.

这里有一个非递归的写法,原理是在BST中左子树上的元素都小于右子树上的元素,
在判断整个树是不是BST时,可以暂时将左子树看成右子树的左子树,这样就不用对
左子树和右子树进行递归,而只需要循环判断右子树就可以了 
*/ 

class Solution {
public:
    //递归
    /*
    bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.size() == 0) return false;
        return isPostOrderOfBST(sequence,0, sequence.size()-1);
    }
    bool isPostOrderOfBST(vector<int> &v, int L,int R){
        if( R <= L) return true;
        int i = R-1;
        while(i>=L && v[i] > v[R]) --i;
        for(int j=i-1; j>=L; --j) if(v[j] > v[R]) return false;
        return isPostOrderOfBST(v,L,i-1) && isPostOrderOfBST(v,i,R-1);
    }
    */
    //非递归
    bool VerifySquenceOfBST(vector<int> seq) {
		int size = seq.size();
        if(size == 0) return false;
        while(--size){
            int i=0;
            while(seq[i] < seq[size]) ++i;
            while(seq[i] > seq[size]) ++i;
            if(i < size) return false;
        }
        return true;
    }
};
