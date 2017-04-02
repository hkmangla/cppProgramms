#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define f first 
#define s second

vector<pii> adj[100001];

int prims(int x){
	bool vis[100001];
	memset(vis,false,sizeof(vis));
	priority_queue<pii> Q;
	Q.push({0,x});
	int minCost = 0;
	while(!Q.empty()){
		pii p = Q.top();
		Q.pop();
		int n = p.s; 
		if(vis[n]) continue;
		minCost += p.f;
		vis[n] = true;
		for(int i=0;i<adj[n].size();i++){
			if(!vis[adj[n][i].s]) Q.push(adj[n][i]);
		}
	}
	return -minCost;
}

int main(int argc, char const *argv[])
{
	int n,e;
	cin>>n>>e;
	int x,y,w;
	for(int i=0;i<e;i++){
		cin>>x>>y>>w;
		adj[x].push_back({-w,y});
		adj[y].push_back({-w,x});
	}
	cout<<prims(1)<<endl;
	return 0;
}