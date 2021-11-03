#include<iostream>
#include <bits/stdc++.h>
#include<queue>
using namespace std;
#define Row 5
#define Col 5


int isValid(int matrix[][Col],int vis[][Col], int row, int col){
	
	return(row>=0 && row<Row && col>=0 && col<Col && (matrix[row][col] && vis[row][col]==0));
}


void dfs(int matrix[][Col],int vis[][Col], int row, int col){
	vis[row][col] =1;
	static int dx[] = {-1,-1,-1,0,0,1,1,1};
	static int dy[] = {-1,0,1,-1,1,-1,0,1};
	for(int i=0;i<8;i++){
		if(isValid(matrix,vis,row+dx[i],col+dy[i])){
			dfs(matrix,vis,row+dx[i],col+dy[i]);
		}
	}
	
}

int countIslands(int matrix[][Col]){
	int visited[Row][Col] = {0};
	memset(visited,0,sizeof(visited));
	int count=0;
	for(int i=0;i<Row;i++){
		for(int j=0;j<Col;j++){
			if(matrix[i][j] && visited[i][j]==0){
				dfs(matrix,visited,i,j);
				count++;
			}
		}
	}
	return count;
}


int main(){
	int matrix[Row][Col] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };
	//cout<<"Enter elements : ";
//	for(int i=0;i<Row;i++){
//		for(int j=0;j<Col;j++){
//			cin>>matrix[i][j];
//		}
//	}
	
	//int vis[Row][Col] = {0};
	
	int x = countIslands(matrix);
	cout<<"\nNumber of islands are : "<<x;
	
	return 0;
}
