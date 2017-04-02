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
int kruskal(){
	int minCost = 0;
	for(int i=0;i<e;i++){
		int x = edges[i].s.f;
		int y = edges[i].s.s;
		int w = edges[i].f;
		if(root(x) != root(y)){
			minCost += w;
			unions(x,y);
		}
	}
	return minCost;
}
int main(int argc, char const *argv[])
{
	int x,y,w;
	cin>>n>>e;
	initial();
	for(int i=0;i<e;i++){
		cin>>x>>y>>w;
		edges.push_back({w,{x,y}});
	}
	sort(edges.begin(), edges.end());
	cout<<kruskal()<<endl;
	return 0;
}