/*
��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�
����˳�����������һ������������������һ����ά�����һ���������ж���������
���и�������
*/

/*
����˼·:
�Ӿ�������Ͻǿ�ʼ�����½ǲ��ң�
1.��� target ���ڵ�ǰԪ�أ�����ҽ���
2.��� target ���ڵ�ǰԪ�أ���targetҲ���ڸ��е�ǰλ����ߵ�����Ԫ�غ͸������������Ԫ�أ������� ++r
3.��� target С�ڵ�ǰԪ��, ��Ȼtarget�Ǵ������������ģ���ôtarget�϶���������������֣�����һ��
  ��������ߵ����֣���������������ߣ�--c 
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int r=0, c=array[0].size()-1;
        while(r <array.size() && c>=0){
            if(target == array[r][c]) return true;
            else if(target > array[r][c]) ++r;
            else --c;
        }
        return false;
    }
};
