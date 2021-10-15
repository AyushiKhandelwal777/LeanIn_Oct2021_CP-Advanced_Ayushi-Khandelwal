#include<iostream>
#include<vector>
using namespace std;

bool iscycle(int node, int par,vector<int> arr[], vector<int> vis){
	vis[node] = 1;
	for(int child : arr[node]){
		if(vis[child]==0){
			if(iscycle(child, node,arr,vis)==true)
			return true;
		}else{
			if(child != par){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n,m,a,b;
	cin>>n>>m;
	vector<int> arr[n+1];
	vector<int> vis(n,0);
	while(m--){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	if(iscycle(1,-1,arr,vis)){
	    cout<<"\nTrue";
	}else{
	    cout<<"\nFalse";
	}
	return 0;
}
