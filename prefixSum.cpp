#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[])
{
	int n; cin>>n;
	int sum = 0;
	for(int i=1;i<=n;i+=2){
		cout<<i<<" ";
		sum+=i;
		// cout<<sqrt(sum)<<" ";
	}
	int target = n;
	if(n%2 == 1) target+=3;
	else target+=2;
	int k = 1;
	bool vis[n+1];
	memset(vis,false,sizeof(vis));
	for(int i=n/2;i>=k;i-=2) {
		if((i+k) == target/2){
			if((k+1)<(i-1)){
				cout<<2*i<<" "<<2*i-2<<" "<<2*k<<" "<<2*k+2<<" ";
				sum +=(4*(i+k));
				// cout<<sqrt(sum)<<" ";
				vis[i]=vis[i-1]=vis[k]=vis[k+1] = true;
			}
			k+=2;
		}
		else {
			if((k+3)<(i-1)){
				cout<<2*i<<" "<<2*i-2<<" "<<2*k+6<<" "<<2*k+4<<" ";
				sum += (4*(i+k+2));		
				// cout<<sqrt(sum)<<" ";
				vis[i]=vis[i-1]=vis[k+3]=vis[k+2] = true;
			}
			k+=4;
		}
		target += 4;
		// cout<<i<<" ";
	}
	for(int i=1;i<=n/2;i++) 
		if(!vis[i]) {
			cout<<2*i<<" ";
		}
		cout<<endl;
	return 0;
}