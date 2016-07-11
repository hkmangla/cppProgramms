#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(a==0)
	return b;
	else
	return gcd(b%a,a);
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		long long int k=0;
		for(int i=1;i<=n;i++)
		{
			k+=(n/gcd(i,n));
		}
		cout<<k<<endl;
	}
	
}
