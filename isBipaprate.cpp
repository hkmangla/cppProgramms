#include "bits/stdc++.h"
using namespace std;
int color[100001];
vector<int> graph[100001];

bool bfs(int s){
	queue<int> q;
	q.push(s);
	color[s] = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int i=0;i<graph[node].size();i++){
			if(color[graph[node][i]] == -1){
				color[graph[node][i]] = 1 - color[node];
				q.push(graph[node][i]);
			}
			else if(color[graph[node][i]] == color[node])
				return false;
		}
	}
	// for(int i=1;i<=8;i++) cout<<color[i]<<" ";
	return true;
}

int main(int argc, char const *argv[])
{
	int t,k=0; cin>>t;
	while(t--){
			k++;
		int n,m; cin>>n>>m;
		while(m--){
			int x,y; cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int flag = true;
	    memset(color,-1,sizeof(color));
		for(int i=1;i<=n;i++){
			// cout<<color[i]<<" ";
			if(color[i] == -1) {
				flag = flag && bfs(i);
			}
		}
		cout<<"Scenario #"<<k<<":"<<endl;
		if(flag) cout<<"No suspicious bugs found!"<<endl;
		else cout<<"Suspicious bugs found!"<<endl;
		for(int i=0;i<=n;i++)
			graph[i].clear();
	}
	return 0;
}






