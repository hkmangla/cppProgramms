#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

vector<pii> adj[100001];
int dist[100001];
bool vis[100001];
void init(int n){
	for(int i=0;i<n+1;i++){
		dist[i] = 1e9;
		vis[i] = false;
	}
}

void dijkstra(int s){
	priority_queue<pii> Q;
	Q.push({0,s});
	dist[s] = 0;
	while(!Q.empty()){
		pii p = Q.top();
		Q.pop();
		int n = p.s;
		if(vis[n]) continue;
		vis[n] = true;
		for(int i=0;i<adj[n].size();i++){
			int e = adj[n][i].s;
			int w = adj[n][i].f;
			if(dist[n] + w < dist[e]){
				dist[e] = dist[n] + w;
				Q.push({-dist[e],e});
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	init(n);
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({w,y});
		adj[y].push_back({w,x});
	}

	// Bellman Ford's algorithm do the same work in O(V.E), But this
	// will do that in only O(V + ElogV) due to use of min_priority Queue
	for(int j=1;j<=n;j++){
		cout<<j<<"--> ";
		init(n);
		dijkstra(j);
		for(int i=0;i<n;i++)
			cout<<dist[i+1]<<" ";
		cout<<endl;
	}
	return 0;
}