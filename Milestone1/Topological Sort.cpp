#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void topologicalSort(vector<int> arr[],int in[], int n){
	queue<int> q;
	for(int i=0;i<n;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int temp = q.front();
		cout<<temp<<" ";
		q.pop();
		for(int child:arr[temp]){
			in[child]--;
			if(in[child]==0){
				q.push(child);
			}
		}
	}
	
}

int main(){
	int n,m,a,b;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	vector<int> arr[n];
	int in[n] = {0};
	while(m--){
		cin>>a>>b;
		arr[a].push_back(b);
		in[b]++;
	}
	
	topologicalSort(arr,in,n);
	
	return 0;
}
