#include "bits/stdc++.h"
using namespace std;
int dist[101][101];
int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = 1e9;
		}
	}
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		dist[x][y] = w;
		dist[y][x] = w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<i<<"--> ";
		for(int j=1;j<=n;j++)
			cout<<dist[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}