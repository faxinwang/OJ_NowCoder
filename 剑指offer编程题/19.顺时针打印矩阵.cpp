/*
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
���磬����������¾��� 
1   2   3   4 
5   6   7   8 
9   10  11  12 
13  14  15  16 
�����δ�ӡ������
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.


����˼·��
1.�����±�x,y��¼��ǰ�ھ����е�λ��
2.�����ĸ���Ǳ�����¼��ǰ���ң��£� �� �� �ĸ������ϲ��ܼ����ߵ�λ��
3.�����ƶ���ǰλ�ò������ĸ���Ǳ�����ֵ��
��Ҫע�����:
1.��x,y�ߵ�ͷʱ����Ҫ��ʱ�����������һ����
2.��ʱ�����÷�������һ�β���Խ����λ�á�
3.��ת�����ʱ���±�Ҫ����Ӧ�ı䶯�� 
*/ 
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> v;
        if(matrix.size() == 0) return v;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int d1 = col, d2=row, d3=-1, d4=0; //the position that can not reach
        
        unsigned long N = row * col;
		int x=0, y=0;
        while(1){
            //go right
            for(; y < d1; ++y) v.push_back(matrix[x][y]);
            if(v.size() >= N) break;
            --d1; --y; ++x; //turn down //������ת����ͬ 
            
            //go down
            for(; x < d2; ++x) v.push_back(matrix[x][y]);
            if(v.size() >= N) break;
            --d2; --x; --y; //turn left
            
            //go left
            for(; y > d3; --y) v.push_back(matrix[x][y]);
            if(v.size() >= N) break;
            ++d3; ++y; --x; //turn up
            
            //go up
            for(; x > d4; --x) v.push_back(matrix[x][y]);
            if(v.size() >= N) break;
            ++d4; ++x; ++y; //turn right
        }
        return v;
}
    
    
int main(){
	vector<vector<int> > matrix;
	int id=0;
	for(int i=0;i <4; ++i){
		vector<int> v;
		for(int j=0; j<4; ++j) v.push_back(++id);
		matrix.push_back(v);
	}
	
	for(int i=0;i<matrix.size(); ++i){
		for(int j=0; j<matrix[i].size(); ++j) printf("%4d",matrix[i][j]);
		printf("\n");
	}
	
	/*
	1 2 3 4
	5 6 7 8
	9 10 11 12
	13 14 15 16
	*/
	
	vector<int> v = printMatrix(matrix);
	for(int i=0;i<v.size(); ++i) printf("%d ",v[i]);
	
	return 0;
}
