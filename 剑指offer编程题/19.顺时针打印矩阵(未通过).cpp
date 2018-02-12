#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int d1, d2,d3, d4;

vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> v;
        if(matrix.size() == 0) return v;
        int row = matrix.size();
        int col = matrix[0].size();
        
        d1 = col; d2=row; d3=-1; d4=0; 
        
        printf("%d %d %d %d\n",d1,d2,d3,d4);
        int N = row * col, x=0, y=0;
        while(1){
            //go right
            --d1;
            for(; y<=d1; ++y) v.push_back(matrix[x][y]), printf("[%d,%d]\n",x,y);
            if(v.size() >= N) break;
            
            //go down
            d2 -=1;
            for(; x<=d2; ++x) v.push_back(matrix[x][y]), printf("[%d,%d]\n",x,y);;
            if(v.size() >= N) break;
            //go left
            d3 -= 1;
            for(; y>=d3; --y) v.push_back(matrix[x][y]), printf("[%d,%d]\n",x,y);;
            if(v.size() >= N) break;
            //go up
            d4 += 1;
            for(; x>=d4; --x) v.push_back(matrix[x][y]), printf("[%d,%d]\n",x,y);;
            if(v.size() >= N) break;
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
