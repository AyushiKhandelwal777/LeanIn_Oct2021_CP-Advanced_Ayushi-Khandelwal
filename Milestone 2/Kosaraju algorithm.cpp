#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> arr[1000];
vector<int> tr[1000];
vector<int> s;
vector<int> order;

vector<int> vis;

void dfs1(int node, vector<int> vis){
	vis[node]=1;
	for(int child:arr[node]){
		if(vis[child]==0){
			dfs1(child,vis);
		}
	}
	s.push_back(node);	
}

void dfs2(int node,vector<int> vis){
	vis[node] = 1;
	for(int child: tr[node]){
		if(vis[child]==0){
			dfs2(child,vis);
		}
	}
	
	order.push_back(node);
}

int main(){
	int v,e,a,b;
	int count=0;
	cout<<"Enter vertices and edges : ";
	cin>>v>>e;
	
	while(e--){
		cin>>a>>b;
		arr[a].push_back(b);
		tr[b].push_back(a);
	}
	for(int i=0;i<v;i++){
		vis[i]=0;
	}
	for(int i=0;i<e;i++){
		if(vis[i]==0){
			dfs1(i,vis);
		}
	}
	
	for(int i=0;i<v;i++){
		vis[i]=0;
	}
	
	for(int i=0;i<e;i++){
		if(vis[order[e-i]]==0){
			dfs2(order[e-i],vis);
			for(int node:s){
				cout<<node<<"\t";
				count++;
			}
			cout<<endl;
		}
	}
	
	cout<<"\nCount is : "<<count;
	
}
