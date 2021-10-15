#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int node, bool vis[], vector<int> arr[]){
	queue<int> q;
	vis[node] = true;
	q.push(node);
	
	while(!q.empty()){
		int fr = q.front();
		cout<<fr<<"\t";
		q.pop();
		for(int child: arr[fr]){
			if(vis[child]==false){
				vis[child]=true;
				q.push(child);
			}
		}
	}
	return;
}

int main(){
	int n, m,a,b;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	vector<int> arr[n];
	bool vis[n];
	for(int i=0;i<n;i++){
		vis[i]=0;
	}
	
	while(m--){
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int k;
	cout<<"Enter k : ";
	cin>>k;
	bfs(k,vis,arr);
	
	return 0;
}
