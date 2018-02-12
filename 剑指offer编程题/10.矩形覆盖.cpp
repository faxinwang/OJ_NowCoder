/*
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С��
�����ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*/ 

/*
����˼·��
�����Ҹо���d[i] = d[i-2] * 2 + d[i-1] 
������쳲����� d[i] = d[i-2] + d[i-1] 
*/

class Solution {
public:
    int rectCover(int number) {
		int *d = new int[number+1];
        d[1] = 1;
        d[2] = 2;
        for(int i=3; i<=number; ++i){
            d[i] = d[i-2] + d[i-1];
        }
        int ans = d[number];
        delete[] d;
        return ans;
    }
};
