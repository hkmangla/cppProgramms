#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		long long int ans,n; int mod=1000000009;
		cin>>n;
		if(!(n%2)){
			n = n/2;
			if(n%3==0)
			ans = ((8*(((n/3)*(n+1))%mod)*(2*n+1)) - 6*(n*n))%mod;
			if((n+1)%3==0)
			ans = ((8*((((n+1)/3)*(n))%mod)*(2*n+1)) - 6*(n*n))%mod;
			if((2*n+1)%3==0)
			ans = ((8*(((n)*(n+1))%mod)*((2*n+1)/3)) - 6*(n*n))%mod;

			// ans = ((8*n*(n+1)*(2*n+1))/3 - 6*(n*n))%mod;
		}
		else{
			n = (n+1)/2;
			if(n%3==0)
			ans = ((4*(((n/3)*(2*n+1))%mod)*(2*n-1)) - 3-6*((n)*(n-1)))%mod;
			if((2*n+1)%3==0)
			ans = ((4*(((n)*((2*n+1)/3))%mod)*(2*n-1)) - 3-6*((n)*(n-1)))%mod;
			if((2*n-1)%3==0)
			ans = ((4*(((n)*(2*n+1))%mod)*((2*n-1)/3)) - 3-6*((n)*(n-1)))%mod;
		
		
		}
		cout<<ans<<endl;
	}
}