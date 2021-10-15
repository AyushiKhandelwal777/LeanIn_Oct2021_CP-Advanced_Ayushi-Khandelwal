#include<iostream>
#include<vector>
using namespace std;

vector<int> dfs(int node, int d, vector<int> dis,vector<int> arr[], int vis[]){
	vis[node] = 1;
	dis[node] = d;
//	for(int i=0;i<arr[node].size();i++){
//		int child = arr[node][i];
//		if(vis[child]==0){
//			dfs(child,d+1,dis,arr,vis);
//		}
//	}

	for(int child : arr[node]){
		if(vis[child]==0){
			dfs(child,d+1,dis,arr,vis);
		}
	}
	
	return dis;
}

int main(){
	int n,m,b,a,d=0;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	vector<int> arr[n];
	int vis[n+1];
	vector<int> dis(n,0);
	
	for(int i=0;i<n;i++){
		vis[i] = 0;
	}
	cout<<"Enter a and b : ";
	while(m--){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int k;
	cout<<"Enter the value from where you want to traverse : ";
	cin>>k;
	vector<int> distance = dfs(k,d,dis,arr,vis);
	cout<<"\n\n";
	for(int i=0;i<n;i++){
		cout<<distance[i]<<" ";
	}
	return 0;
}
