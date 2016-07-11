#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int t,mod=1000000007;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[100001];
		for(int i=0;i<=n;i++)
		cin>>a[i];
		long long int k=0,l=2*a[0],pov=2;
		for(int i=1;i<=n;i++)
		{
			k=2*k+a[i]*l;
			l+=pov*a[i];
			pov=(pov*2)%mod;
			k%=mod;
			l%=mod;
		}
		cout<<k<<endl;
	}
	return 0;
}
