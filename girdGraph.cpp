#include "bits/stdc++.h"
using namespace std;
bool graph[1000001];
bool vis[1000001];
int m;
int n;
vector<int> successor(int s){
	int x = s/m, y = s%m;
	std::vector<int> v;
	int a[] = {2,-2,1,-1};
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
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
long long fact[1000001];
long long mod = 1000000007;
int main(int argc, char const *argv[])
{	
	fact[0] = fact[1] = 1;
	for(int i=2;i<=1000000;i++){
		fact[i] = (fact[i-1]*i)%mod;
	}
	int t; cin>>t;
	while(t--){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				vis[i*m+j] = false;
				graph[i*m+j] = false;
			}
		}
		cin>>n>>m;
		int q; cin>>q;
		for(int i = 0;i<q;i++){
				int x,y; cin>>x>>y;
				x--; y--;
				vis[x*m + y] = false;
				graph[x*m + y] = 1;
		}
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<m;j++)
		// 		cout<<graph[i*m+j]<<" ";
		// 	cout<<endl;
		// }
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<m;j++)
		// 		{
		// 			if(graph[i*m+j]){
		// 			cout<<i*m+j<<"-->";
		// 			std::vector<int> v = successor(i*m+j);
		// 			for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
		// 			cout<<endl;
		// 			}
		// 		}
		// 	cout<<endl;
		// }
		int value;
		long long ans = 1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!vis[i*m + j] and graph[i*m + j]){
					value = bfs(i*m+j);
					ans = (ans*fact[value])%mod;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}