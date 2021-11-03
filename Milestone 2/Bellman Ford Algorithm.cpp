#include<iostream>
#include<stdlib.h>
#include<vector>
#define INF 99999
using namespace std;

struct Edge{
	int src;
	int dest;
	int wt;
};

struct graph{
	int v;
	int e;
	struct Edge *edge;
};


struct graph *newnode(int v,int e){
    struct graph *Graph = new graph;
	Graph->v = v;
	Graph->e = e;
	Graph->edge = new Edge[e];
	return Graph;
}

void bellmanFord(struct graph *graph,int src){
	int v = graph->v;
	int e = graph->e;
	//initializing distance vector to infinity
	vector<int> dist(v,INF);
	dist[src]=0;
	// relaxing the distances
	for(int i=0;i<v;i++){
		for(int j=0;j<e;j++){
			int x = graph->edge[j].src;
			int y = graph->edge[j].dest;
			int weight = graph->edge[j].wt;
			if(dist[x]!=INF && dist[y]>dist[x]+weight){
				dist[y]=dist[x]+weight;
			}
		}
	}
	// checking for negative cycle
	for(int j=0;j<e;j++){
		int x = graph->edge[j].src;
		int y = graph->edge[j].dest;
		int weight = graph->edge[j].wt;
		if(dist[x]!=INF && dist[y]>dist[x]+weight){
			cout<<"\n\nGraph contain negative cycle.";
			return;
		}
	}
	cout<<"\n";
	for(int i=0;i<v;i++){
		cout<<dist[i]<<" ";
	}
}

int main(){
	int v,e;
	cout<<"Enter vertices and edges : ";
	cin>>v>>e;
	int src,dest,wt;
	struct graph *Graph = newnode(v,e);
	cout<<"Enter source, destination and weights\n";
	for(int i=0;i<e;i++){
		cin>>src>>dest>>wt;
		Graph->edge[i].src = src;
		Graph->edge[i].dest = dest;
		Graph->edge[i].wt = wt;
	}
// 	int source;
// 	cout<<"Enter source : ";
// 	cin>>source;
	bellmanFord(Graph,0);
	
	return 0;
}
