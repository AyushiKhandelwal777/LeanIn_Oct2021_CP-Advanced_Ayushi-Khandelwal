#include<iostream>
#include<vector>
using namespace std;

void distance(int node, int k, vector<int> &d, vector<int> arr[], int vis[]){
	vis[node] = 1;
	if(k<0){
		return;
	}
	for(int child:arr[node]){
		vis[child] == 1;
		if(vis[child]==0){
			distance(child,k-1,d,arr,vis);
		}
		if(k==0){
			d.push_back(child);
		}
	}
	
	for(int i=0;i<d.size();i++){
		cout<<d[i]<<" ";
	}
}

int main(){
	int n,m,a,b;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	vector<int> arr[n];
	int vis[n] = {0};
	vector<int> d;
	while(m--){
	    cin>>a>>b;
	    arr[a].push_back(b);
	    arr[b].push_back(a);
	}
	int node,k;
	cout<<"Enter node : ";
	cin>>node;
	cout<<"Enter k : ";
	cin>>k;
	distance(node,k,d,arr,vis);
	
	
	return 0;
}
