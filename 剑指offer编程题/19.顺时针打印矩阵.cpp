/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 
1   2   3   4 
5   6   7   8 
9   10  11  12 
13  14  15  16 
则依次打印出数字
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.


解题思路：
1.设置下标x,y记录当前在矩阵中的位置
2.设置四个标记变量记录当前往右，下， 左， 上 四个方向上不能继续走的位置
3.不断移动当前位置并更新四个标记变量的值。
需要注意的是:
1.当x,y走到头时，需要及时修正，想后退一步。
2.及时修正该方向上下一次不可越过的位置。
3.在转方向的时候，下标要做相应的变动。 
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
            --d1; --y; ++x; //turn down //修正并转向，下同 
            
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
