#include "bits/stdc++.h"
using namespace std;
#define ll long long

int n,m;
ll dp[303][303][303];
std::vector<ll> a[303];

ll solve(int i, int j, int total){
	if(dp[i][j][total] != -1) return dp[i][j][total];
	if(total < i) return INT_MAX;
	if(total > n) return INT_MAX;
	if(total == n && i <= n) return 0;
	if(i >= n) return INT_MAX;
	if(j == m-1) return dp[i][j][total] = min(a[i][j] + solve(i+1,0,total+j+1), solve(i+1,0,total));
	return dp[i][j][total] = min(a[i][j] + solve(i+1,0,total+j+1), solve(i,j+1,total));
}
int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,tt=0; cin>>t;
	while(t--){
		tt++;
		cin>>n>>m;
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++){
			a[i].clear();
			for(int j=0;j<m;j++)
			{
				ll x;
				cin>>x;
				a[i].push_back(x);
			}
			sort(a[i].begin(),a[i].end());
		}
		for(int i=0;i<n;i++){
			a[i][0] += 1;
			for(int j=1;j<m;j++)
			{
				a[i][j] += (a[i][j-1] +2*j+1);
			// cout<<a[i][j]<<" ";
			}
			// cout<<endl;
		}
		cout<<"Case #"<<tt<<": "<<solve(0,0,0)<<endl;
	}
	return 0;
}