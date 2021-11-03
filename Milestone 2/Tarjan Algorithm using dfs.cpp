#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int timer=0;
static int count=0;

void tarjan(int node,vector<int> graph[],bool vis[],int activeArray[], int in[], int low[]){
	vis[node]=1;
	in[node]=low[node]=timer++;
	activeArray[node]=1;
	stack<int> st;
	st.push(node);
	
	for(int child : graph[node]){
		if(vis[child]==true && activeArray[node]==1){
			low[node] = min(low[node],in[child]);
		}else if(vis[child]==false){
			tarjan(child,graph,vis,activeArray,in,low);
			
			if(activeArray[child]==1){
				low[node] = min(low[node], in[child]);
			}
		}
	}
	
	if(in[node]==low[node]){
		count++;
	}
	
// 	cout<<"Count is : "<<count;
}

int main(){
	int n,m,a,b;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	vector<int> graph[n];
	bool vis[n];
	int activeArray[n];
	int in[n],low[n];
	for(int i=0;i<n;i++){
		vis[i]=false;
		activeArray[i]=0;
	}
	cout<<"Enter edges : ";
	for(int i=0;i<m;i++){
		cin>>a>>b;
		graph[a].push_back(b);
	}
	
	for(int i=0;i<n;i++){
		if(vis[i]==false){
			tarjan(i,graph,vis,activeArray,in,low);
		}
	}
	
	cout<<"Count is : "<<count;
	
	return 0;
}
