#include<iostream>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		long long int n,k,a[100001],x,b[100001];
		long long int ans=0,l=-100000,kk;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			kk=a[i]*b[i];
			int g=b[i];
			if(b[i]<0)
			g=-b[i];
			if(g>l)
			{
			l = g;
			x =i;
			}
			ans+=kk;
		}
		l=k*b[x];
		if(l<0)
		l=-l;
		ans+=l;
		cout<<ans<<endl;
	}
}
