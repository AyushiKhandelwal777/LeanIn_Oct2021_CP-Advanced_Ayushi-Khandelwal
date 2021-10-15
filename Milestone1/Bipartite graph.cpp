// Run this program on online compiler

#include<iostream>
#include<vector>
using namespace std;

bool bipartite(int node, int c, vector<int> color, int vis[], vector<int> arr[]){
	vis[node]=1;
	color[node]=c;
	for(int child: arr[node]){
		if(vis[child]==0){
			if(bipartite(child, c^1, color,vis,arr)==false){
				return false;
			}
		}else{
			if(color[child]==color[node]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int n,m,b,a,d=0;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	vector<int> arr[n];
	int vis[n+1];
	vector<int> color(n,0);
	for(int i=0;i<n;i++){
		vis[i] = 0;
	}
	cout<<"Enter a and b : ";
	while(m--){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	cout<<"\n\n";
	if(bipartite(1,0,color,vis,arr)){
		cout<<"True";
	}else{
		cout<<"False";
	}
	
}
