#include<iostream>
#include<string.h>
using namespace std;
int mod = 1000000007;

long long int powermod(long long int base, long long int exponent) {
    long long int result = 1;
    while (exponent > 0) {
       if ((exponent % 2) == 1) {
           result = (result * base) % mod;
       }
       base = (base * base) % mod;
       exponent = exponent / 2;
    }
    return result;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,k;
		cin>>n;
		cin>>k;
		long long int ans = (k*powermod(k-1,n-1))%mod;
		cout<<ans<<endl;
        
	}
	return 0;
}