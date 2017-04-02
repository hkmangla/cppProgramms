#include "bits/stdc++.h"
using namespace std;
bool visited[100001];
vector<int> graph[100001];
bool isCyclic(int s, int parent){
	visited[s] = true;
	for(int i=0;i<graph[s].size();i++){
			if(!visited[graph[s][i]]){
				return isCyclic(graph[s][i],s);
			}
			else if(graph[s][i] != parent) return true;
		}
	return false;
}

int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		while(m--){
			int x,y; cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int flag = false;
	    memset(visited,false,sizeof(visited));
	    for(int i=1;i<=n;i++){
	    	if(!visited[i]) flag = flag || isCyclic(i,-1);
	    }
	    cout<<flag<<endl;
		for(int i=0;i<=n;i++)
			graph[i].clear();
	}
	return 0;
}






