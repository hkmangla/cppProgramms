#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pii pair<int,int>
vector< pii > graph[100001];
bool vis[100001];
pii diameter(int root){
	vector<int> v;
	vis[root] = true;
	int best_value = 0;
	for(int i=0;i<graph[root].size();i++){
		if(!vis[graph[root][i].f]){
			
			pii tmp = diameter(graph[root][i].f);
			best_value = max(best_value, tmp.s);
			v.push_back(graph[root][i].s + tmp.f);
		}
	}
	if(v.size() == 0) return {0, 0};
	if(v.size() == 1) return {v[0], max(v[0],best_value)};
	sort(v.begin(),v.end());
	return {v[v.size()-1], max(v[v.size()-1] + v[v.size()-2], best_value)};
}
int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		memset(vis,false,sizeof(vis));
		for(int i=0;i<=n;i++) graph[i].clear();
		for(int i=0;i<n-1;i++){
			int x,y,c; cin>>x>>y>>c;
			graph[x].push_back({y,c});
			graph[y].push_back({x,c});
		}
		pii result = diameter(1);
		int ans = max(result.f,result.s);
		int cost = (ans > 10000) ? 10000 : (ans > 1000) ? 1000 : (ans > 100) ? 100 : 0;
		cout<<cost<<" "<<ans<<endl;
	}
	return 0;
}