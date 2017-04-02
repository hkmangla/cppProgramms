#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define f first 
#define s second

vector<pair<int,pii>> edges;
int n,e,id[1000001];

void initial(){
	for(int i=0;i<=n;i++) id[i] = i;
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
std::vector<pii> adj[101];
void kruskal(){
	for(int i=0;i<e;i++){
		int x = edges[i].s.f;
		int y = edges[i].s.s;
		int w = edges[i].f;
		if(root(x) != root(y)){
			adj[x].push_back({w,y});
			adj[y].push_back({w,x});
			unions(x,y);
		}
	}
}

int bfs(int s, int d){
	queue<int> Q;

	Q.push(s);
	int w = 1e9;
	bool vis[101];
	pii par[101];
	memset(vis,false,sizeof(vis));
	while(!Q.empty()){
		int node = Q.front();
		Q.pop();
		// cout<<node<<endl;
		if(node == d) break;
		if(vis[node]) continue;
		vis[node] = true;
		for(int i=0;i<adj[node].size();i++){
			if(!vis[adj[node][i].s]){
				par[adj[node][i].s] = {node,adj[node][i].f};
				Q.push(adj[node][i].s);
			}
		}
	}
	int curr = d;
	vector<int> v;
	while(curr != s){
		v.push_back(curr);
		w = min(w,par[curr].s);
		curr = par[curr].f;
	}
	v.push_back(s);
	for(int i=v.size()-1;i>=0;i--) cout<<v[i]<<" ";
		cout<<endl;
	return w;
}
int main(int argc, char const *argv[])
{
	ios_base :: sync_with_stdio(false);
	int x,y,w;
	cin>>n>>e;
	initial();
	for(int i=0;i<e;i++){
		cin>>x>>y>>w;
		edges.push_back({w,{x,y}});
	}
	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());
	kruskal();
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<"--> ";
	// 	for(int j=0;j<adj[i].size();j++) cout<<adj[i][j].s<<" ";
	// 		cout<<endl;
	// }
	int s,d,p; cin>>s>>d>>p;
	cout<<(p+1)/(bfs(s,d)-1) + 1<<endl;
	return 0;
}