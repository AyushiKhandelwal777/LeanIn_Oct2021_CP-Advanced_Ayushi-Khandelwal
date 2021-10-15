#include<iostream>
#include<vector>
using namespace std;
//diameter is longest distance between two leaf nodes
// it can or cannot pass from root node
void dfs(int node, int d, int &maxdis, int &maxnode, int vis[], vector<int> arr[]){
	vis[node] = 1;
	if(d>maxdis){
		maxdis = d;
		maxnode = node;
	}
	for(int child: arr[node]){
		if(vis[child]==0){
			dfs(child,d+1,maxdis,maxnode,vis,arr);
			//dfs(maxnode,0,0,0,vis,arr)
		}
	}
	return;
}
/*
maxdis  3
maxnode 4

dfs(3,0,0,0)
dfs(6,1,0,0)
dfs(7,1,1,6)
dfs(8,2,1,6)
dfs(1,1,2,8)
dfs(2,2,2,8)
dfs(4,3,2,8)
*/

int main(){
	int n,m;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	vector<int> arr[n];
	int vis[n];
	for(int i=0;i<n;i++){
		vis[i]=0;
	}
	int a,b;
	while(m--){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int maxd=0,maxnode=0,d=0;
	dfs(0,d,maxd,maxnode,vis,arr);
	dfs(maxnode,d,maxd,maxnode,vis,arr);
	cout<<"\n\n"<<maxd;
	
	return 0;
}
