/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��
*/ 

/*
����˼·:
���ƶ��������(BST)��, �������ϵ�Ԫ�ض�С�ڵ��ڸ�����е�Ԫ��,
�������ϵ�Ԫ�ض����ڵ��ڸ��ڵ��е�Ԫ��, �������������ֶ���һ��
���������.������һ���Ϸ��ĺ����������� 
seq: [[elements of left sub tree], [elements of right sub tree], rootElem]��,
ǰ�벿�ֵ�Ԫ�ض�С�ڵ���rootElem, ��벿�ֵ�Ԫ�ض����ڵ���rootElem.
����ǰ�벿�ֺͺ�벿���ֶ�������������. 
��������������Ժ����׵�д���ݹ麯��.

������һ���ǵݹ��д��,ԭ������BST���������ϵ�Ԫ�ض�С���������ϵ�Ԫ��,
���ж��������ǲ���BSTʱ,������ʱ��������������������������,�����Ͳ��ö�
�����������������еݹ�,��ֻ��Ҫѭ���ж��������Ϳ����� 
*/ 

class Solution {
public:
    //�ݹ�
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
    //�ǵݹ�
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
