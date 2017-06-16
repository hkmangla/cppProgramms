#include "bits/stdc++.h"
using namespace std;
#define MAXN 100000

struct node
{
	int val,par=0,sbtsz=1,seg_base=0,chainId,depth=0;

};
node nodes[MAXN+1];
vector<int> adj[MAXN+1];
int n;
int head[MAXN+1],segPos,chainId;
int par[MAXN+1][20];
int base_array[MAXN+1],tree[6*MAXN+1];

void hld(int s,int prev){
	if(head[chainId] == 0){
		head[chainId] = s;
	}
	nodes[s].chainId = chainId;
	nodes[s].seg_base = segPos;
	base_array[segPos] = nodes[s].val;
	segPos ++;

	int count = 0;
	for(auto v:adj[s]){
		if(v != prev){	
			if(count) chainId ++;
			hld(v,s);
			count++;
		}
	}
}
int dfs(int s,int prev){
	nodes[s].depth = nodes[nodes[s].par].depth + 1;
	for(auto v:adj[s]){
		if(v != prev){
			nodes[v].par = s;
			par[v][0] = s;
			nodes[s].sbtsz += dfs(v,s);
		}
	}
	return nodes[s].sbtsz;
}
void preComputeSparseMatrix(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<20;j++){
			if(par[i][j-1] != -1)
				par[i][j] = par[par[i][j-1]][j-1];
		}
	}
}
void buildHLD(int startNode){
	dfs(startNode,0);
	preComputeSparseMatrix();
	//sort childs by subtree Size
	vector<pair<int,int>> vc;
	for(int i=1;i<=n;i++){
		vc.clear();
		for(auto v:adj[i]){
			vc.push_back({nodes[v].sbtsz,v});
		}
		sort(vc.begin(), vc.end());
		adj[i].clear();
		for(auto v:vc) adj[i].push_back(v.second);
		reverse(adj[i].begin(), adj[i].end());
	}
	hld(startNode,0);
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<"--> ChainID: "<<nodes[i].chainId<<" seg_base: "<<nodes[i].seg_base<<endl; 
	// }
	// for(int i=0;i<5;i++)
	// 	cout<<head[i]<<endl;
}
int lca(int u,int v){
	if(nodes[v].depth < nodes[u].depth) swap(u,v);
	int diff = nodes[v].depth - nodes[u].depth;
	for(int i=0;i<20;i++){
		if((diff>>i) & 1)  v = par[v][i];
	}
	if(u == v) return u;
	for(int i=19;i>=0;i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}
void treeInput(){
	int m,x,y; cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		nodes[i].val = x;
	}
	cin>>m;
	while(m--){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}
void buildSegTree(int nd,int a,int b){
	if(a > b) return;
	if(a == b){
		tree[nd] = base_array[a];
		return;
	}
	buildSegTree(nd*2,a,(a+b)/2);
	buildSegTree(nd*2+1,(a+b)/2+1,b);
	tree[nd] = min(tree[nd*2],tree[nd*2+1]);
}
void upSegTree(int nd,int a,int b,int idx,int val){
	if(a > b or idx < a or idx > b) return;
	if(a == b){
		tree[nd] = val;
		return;
	}
	upSegTree(nd*2,a,(a+b)/2,idx,val);
	upSegTree(nd*2+1,(a+b)/2+1,b,idx,val);
	tree[nd] = min(tree[nd*2],tree[nd*2+1]);
}
void change(int posNode, int val){
	upSegTree(1,0,n-1,nodes[posNode].seg_base,val);
}
int RMQ(int nd,int a,int b,int l,int r){
	if(a > b or r < a or l > b) return INT_MAX;
	if(a >= l and b <= r){
		return tree[nd];
	}
	int q1 = RMQ(nd*2,a,(a+b)/2,l,r);
	int q2 = RMQ(nd*2+1,(a+b)/2+1,b,l,r);
	return min(q1,q2);
}
int search(int u,int v){
	int chain_u,chain_v = nodes[v].chainId,ans = INT_MAX;
	while(true){
		chain_u = nodes[u].chainId;
		if(chain_u == chain_v){
			ans = min(ans,RMQ(1,0,n-1,nodes[v].seg_base,nodes[u].seg_base));
			break;
		}
		else{
			ans = min(ans,RMQ(1,0,n-1,nodes[head[chain_u]].seg_base,nodes[u].seg_base));
			u = nodes[head[chain_u]].par;
		}
	}
	return ans;
}

int minInPath(int u,int v){
	int LCA = lca(u,v);
	return min(search(u,LCA),search(v,LCA));
}
int main(int argc, char const *argv[])
{
	treeInput();
	buildHLD(1);
	buildSegTree(1,0,n-1);
	int q; cin>>q;
	while(q--){
		int qt,a,b; cin>>qt>>a>>b;
		if(qt){
			cout<<minInPath(a,b)<<endl;
		}
		else{
			change(a,b);
		}
	}
	return 0;
}