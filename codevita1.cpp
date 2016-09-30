#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n,k,ans=0,x,y;
	cin>>n>>k;
	long long int a[n+1],b[n+1],c[n+1];
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long int minn = 100000000,maxn= -1000000000;
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(b[i] > maxn)
		{
			x = i;
			maxn = b[i];
		}
		if(b[i] < minn)
		{
			y = i;
			minn = b[i];
		}
	}
	// cout<<abs(maxn)<<" "<<abs(minn)<<endl;
	if(abs(maxn) > abs(minn)){
		if(maxn > 0)
		{
			a[x] -= 2*k;
		}
		else
		{
			a[x] += 2*k;
		}
	}

	if(abs(maxn) <= abs(minn)){
		if(minn > 0)
		{
			a[y] -= 2*k;
		}
		else
		{
			a[y] += 2*k;
		}
	}
	for(int i=0;i<n;i++){
		// cout<<a[i]<<" "<<b[i]<<endl;
		ans += a[i]*b[i];
	}
	cout<<endl<<ans<<endl;
}