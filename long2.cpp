#include "bits/stdc++.h"
using namespace std;

vector<int> tree[50002];
int ans,n,l,r;
int a[50002];
bool visited[50002];

void dfs(int v, int parent, int count){
	// ans += count;
	// cout<<ans<<endl;
	// cout<<"count at "<<v<<" is: "<<count<<endl;
	visited[v] = true;
	// path.push_back(v);
	// for(int i=0;i<path.size();i++)
	// 	cout<<path[i]<<" ";
	// cout<<"---->"<<count;
	if(count >= l && count <= r) ans ++;
	// cout<<endl;
	for(int i=0;i<tree[v].size();i++){
		int u = tree[v][i];
		// if(count >= l && count <= r) ans++;		
		if(!visited[u]){
			if(parent != -1){
				if(a[parent] < a[v] && a[v] > a[u])
					dfs(u,v,count+1);
				else
					dfs(u,v,count);
			}
			else{
				dfs(u,v,count);
			}
		}
	}
}
void init(){
	for(int i=0;i<=n;i++)
	{
		tree[i].clear();
		visited[i] = false;
	}
}
int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while(t--){
		cin>>n;
		cin>>l>>r;
		init();
		for(int i=0;i<n;i++)
			cin>>a[i+1];
		ans = 0;
		for(int i=0;i<n-1;i++){
			int x,y; cin>>x>>y;
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		// vector<int> path;
		for(int i=1;i<=n;i++)
		{
			// cout<<"Path from node "<<i<<":"<<endl;
			dfs(i,-1,0);
			// cout<<endl<<endl;
			for(int i=1;i<=n;i++)
			visited[i] = false;			
		}
		cout<<ans/2<<endl;
	}
	return 0;
}