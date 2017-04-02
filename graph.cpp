#include "bits/stdc++.h"
using namespace std;
bool graph[1000001];
bool vis[1000001];
int m;
int n;
vector<int> successor(int s){
	int x = s/m, y = s%m;
	std::vector<int> v;
	int a[] = {0,1,-1};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(abs(a[i]) == abs(a[j])) continue;
			int next_x = x+a[i],next_y = y+a[j];
			if(next_x >=n or next_x < 0 or next_y >= m or next_y < 0 or !graph[next_x*m + next_y]) continue;
			else{
				v.push_back(next_x*m + next_y);
			} 
		}
	}
	return v;
}

int bfs(int s){
	queue<int> Q;
	Q.push(s);
	vis[s] = true;
	int count = 0;count ++;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		vector<int> succ = successor(v);
		for(int i=0;i<succ.size();i++){
			if(!vis[succ[i]]){
				vis[succ[i]] = true;
				count ++;
				Q.push(succ[i]);
			}
		}
	}
	return count;
}
int main(int argc, char const *argv[])
{
		ios_base :: sync_with_stdio(false);
		cin>>n>>m;
		int remain = 0;
		int q; cin>>q;
		for(int i = 0;i<n;i++){
			for(int j=0;j<m;j++){
				int x; cin>>x;
				vis[i*m + j] = false;
				graph[i*m + j] = x;
				remain += x;
			}
		}
		int value;
		while(q--){	
			int i,j; cin>>i>>j;
			i--; j--;
			if(!vis[i*m + j] and graph[i*m + j]){
				remain -= bfs(i*m+j);
				printf("%d\n", remain);
			}
			else{
				// cout<<remain<<endl;
				printf("%d\n", remain);
			}		
		}
	return 0;
}