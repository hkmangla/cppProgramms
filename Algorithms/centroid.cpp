// Name     : Hemant Mangla
// username : hkmangla
// Country	: India
// College  : Deenbandhu Chhotu Ram University of Science and Technology Murthal
// emailId  : hemantmangla78@gmail.com
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,b) for(int i=a;i<b;i++)
#define MAXN 100005

vector<int> adj[100001];
vector<int> centroidTree[MAXN+1];
int centroidMarked[MAXN+1];
int setsubtreeSize(int s,bool vis[],int subtree[],int *n){
	if(vis[s] or centroidMarked[s]) return 0;
	vis[s] = true;
	*n += 1;
	subtree[s] = 1;
	rep(i,adj[s].size()){
		subtree[s] += setsubtreeSize(adj[s][i],vis,subtree,n);
	}
	return subtree[s];
}

int findCentroid(int s,int n,int subtree[],bool vis[]){
	bool isCentroid  = true;
	vis[s] = true;
	int hC = 0;
	rep(i,adj[s].size()){
		int e = adj[s][i];
		if(!vis[e]){	
			if(subtree[e] > n/2) isCentroid = false;
			if(hC == 0 || subtree[e] > subtree[hC]) hC = e;
		}
	}
	if(isCentroid and subtree[s] > n/2) return s;
	return findCentroid(hC,n,subtree,vis);
}

int getCentroid(int s){
	bool vis[MAXN+1];
	int subtree[MAXN+1];
	memset(vis,false,sizeof(vis));
	memset(subtree,0,sizeof(subtree));
	int n = 0;
	setsubtreeSize(s,vis,subtree,&n);
	memset(vis,false,sizeof(vis));
	int centroid = findCentroid(s,n,subtree,vis);
	centroidMarked[centroid] = true;
	return centroid;
}

int decomposeTree(int s){
	int cent = getCentroid(s);
	// cout<<cent<<" ";
	rep(i,adj[cent].size()){
		// cout<<adj[cent][i]<<" ";
		if(!centroidMarked[adj[cent][i]]){
			int cent_sub = decomposeTree(adj[cent][i]);
			centroidTree[cent].push_back(cent_sub);
			centroidTree[cent_sub].push_back(cent);
		}
	}
	return cent;
}
int main(int argc, char const *argv[])
{
	memset(centroidMarked,false,sizeof(centroidMarked));
	int n; cin>>n;
	rep(i,n-1){
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	decomposeTree(1);
	rep(i,n) {
		cout<<i+1<<" ";
		for(auto it:centroidTree[i+1]) cout<<it<<" ";
			cout<<endl;
	}
	// cout<<endl;
	return 0;
}