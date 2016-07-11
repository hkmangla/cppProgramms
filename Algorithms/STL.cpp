#include<bits/stdc++.h>
using namespace std;
template<class type>
type gcd(type a, type b) {return (b==0)?a:gcd(b,a%b);}

int main()
{
	int t;cin>>t;
	while(t--){
		long long int n,k;cin>>n>>k;
		cout<<gcd(n,k)<<endl;
	}
} 