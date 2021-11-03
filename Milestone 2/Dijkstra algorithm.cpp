#include<iostream>
#include<vector>
#include<queue>
#define INF 9999999
using namespace std;
vector<pair<int,int> > v[1001];
void dijkstra(int source, int n){
	
	priority_queue< pair<int,int> , vector<pair<int,int> > ,greater<pair<int,int> > > q;
	vector<int> dist(n,INF);
	q.push({0,source});    // first = distance     second = node
	dist[source]=0;
	
	while(!q.empty()){
		int cur_n = q.top().second;   // current node
		int cur_d = q.top().first;    // current distance
		q.pop();
		
		for(pair<int,int> edge : v[cur_n]){
			if(cur_d + edge.second < dist[edge.first]){
				dist[edge.first] = cur_d + edge.second;
				q.push({dist[edge.first],edge.first});
			}
		}
	}
	cout<<"\n\nDistances are : ";
	for(int i=0;i<n;i++){
		cout<<i<<"\t"<<dist[i]<<endl;
	}
}

int main(){
	int n,m,a,b,w;
	cout<<"Enter n and m : ";
	cin>>n>>m;
	cout<<"Enter a b amd w : ";
	while(m--){
		cin>>a>>b>>w;
		v[a].push_back({b,w});
		v[b].push_back({a,w});
	}
	
	dijkstra(0,n);
	
	return 0;
}
