#include "bits/stdc++.h"
using namespace std;
int n,s,m,p;
int a[2502];
int profit(int l, int r){
	int add = 0,sub = 0;
	for(int i=l;i<=r;i++){
		if(a[i] > a[l]) sub += (a[i] - a[l]);
		else add += (a[l] - a[i]);
	}
	return ((r-l)*s - add*p - sub*m);
}

int main(int argc, char const *argv[])
{
	cin>>n>>s>>m>>p;
	for(int i=1;i<=n;i++) cin>>a[i];
	int dp[n+2];
	memset(dp,0,sizeof(dp));
	for(int j=1;j<=n;j++){
		for(int i=0;i<j;i++){
			dp[j] = max(dp[j],dp[i]+profit(i+1,j));
		}
		cout<<dp[j]<<" ";
	}
	cout<<endl;
	cout<<dp[n]<<endl;
	return 0;
}