#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,vector<int> arr[], int vis[]){
	vis[node] = 1;
	//cout<<endl<<node<<"\t";
	for(int i=0;i<arr[node].size();i++){
		int child = arr[node][i];
		if(vis[child]==0){
			dfs(child,arr,vis);
		}
	}
}

int main(){
	int n,m,b,a;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	vector<int> arr[n];
	int vis[n+1];
	for(int i=0;i<n;i++){
		vis[i]=0;
	}
	cout<<"Enter a and b : ";
	while(m--){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	int count=0;
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			dfs(i,arr,vis);
			count++;
		}
	}
	
	cout<<endl<<"Number of connected component of graph is : "<<count;
	return 0;
}
