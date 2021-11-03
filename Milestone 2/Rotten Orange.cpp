#include<iostream>
using namespace std;
/*
2 = Rotten orange
1 = fresh orange
0 = no orange
BFS on grid approach
*/
const int row=3;
const int col = 5;

bool isValid(int i,int j){
	if(i>=0 && i<row && j>=0 && j<col){
		return true;
	}
	return false;
}

int rottenOrange(int matrix[][col]){
	int no=2;
	bool changed = false;
	while(true){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(matrix[i][j]==no){
					if(isValid(i+1,j) && matrix[i+1][j]==1){
						matrix[i+1][j] = matrix[i][j]+1;
						changed = true;
					}
					if(isValid(i,j+1) && matrix[i][j+1]==1){
						matrix[i][j+1] = matrix[i][j]+1;
						changed = true;
					}
					if(isValid(i-1,j) && matrix[i-1][j]==1){
						matrix[i-1][j] = matrix[i][j]+1;
						changed = true;
					}
					if(isValid(i,j-1) && matrix[i][j-1]==1){
						matrix[i][j-1] = matrix[i][j]+1;
						changed = true;
					}
				}
			}
		}
		
		if(!changed){
			break;
		}
		changed = false;
		no++;
	}
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(matrix[i][j]==1){
				return -1;
			}
		}
	}
	return no-2;
}

int main(){
	//cin>>row>>col;
	int matrix[row][col] = { { 2, 1, 0, 2, 1 },
                    		 { 1, 0, 1, 2, 1 },
                    		 { 1, 0, 0, 2, 1 } };
 ;
//	for(int i=0;i<row;i++){
//		for(int j=0;j<col;j++){
//			cin>>matrix[i][j];
//		}
//	}
	
	int x = rottenOrange(matrix);
	cout<<"\n\nMaximum time : "<<x;	
	return 0;
}
