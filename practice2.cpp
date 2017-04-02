#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define f first 
#define s second

vector<pair<int,pii>> edges;
int n,e,id[1000001];
vector<pii> adj[100001];
void initial(){
	for(int i=0;i<=n;i++) {
		id[i] = i;
		adj[i].clear();
	}
	edges.clear();
}

int root(int x){
	while(id[x] != x){
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}
void unions(int x, int y){
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}
int kruskal(){
	int mincost = 0;
	for(int i=0;i<e;i++){
		int x = edges[i].s.f;
		int y = edges[i].s.s;
		int w = edges[i].f;
		if(root(x) != root(y)){
			adj[x].push_back({w,y});
			adj[y].push_back({w,x});
			mincost += w;
			unions(x,y);
		}
	}
	return mincost;
}
bool realN[101];
int bfs(int s){
	queue<int> Q;
	bool vis[101];
	Q.push(s);
	int ans = 0;
	memset(vis,false,sizeof(vis));
	while(!Q.empty()){
		int p = Q.front();
		Q.pop();
		int l = p;
		if(vis[l]) continue;
		vis[l] = true;
		for(int i=0;i<adj[l].size();i++){
			if(!vis[adj[l][i].s] and !realN[adj[l][i].s]) {
				Q.push(adj[l][i].s);
				ans += adj[l][i].f;
			}
		}
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while(t--){

	int x,y,w;
	int k;
	cin>>n>>e;
	cin>>k;
	initial();
	for(int i=0;i<e;i++){
		cin>>x>>y>>w;
		edges.push_back({w,{x,y}});
	}
	sort(edges.begin(), edges.end());
	kruskal();
	memset(realN,false,sizeof(realN));
	for(int j=0;j<n;j++){
		for(int i=k+1;i<=n;i++){
				int child = 0;
				for(int K=0;K<adj[i].size();K++){
					if(!realN[adj[i][K].s]) child ++;
				}
				if(child == 1) realN[i] = true;
		}
	}
	cout<<bfs(1)<<endl;
	}
	return 0;
}