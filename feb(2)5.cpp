#include<iostream>
using namespace std;
int b[1000001],c[1000001],r[1000001],sum[1000001];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m,l=0;
		cin>>n>>m;
		int a[n+1][m+1];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			cin>>a[i][j];
			if(l<a[i][j])
			l=a[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			b[a[i][j]]++;
			}
			for(int j=0;j<m;j++)
			{
				if(c[a[i][j]]<b[a[i][j]])
				c[a[i][j]]=b[a[i][j]];
				b[a[i][j]]=0;
			}
		}
		for(int j=0;j<m;j++)
		{
			for(int i=0;i<n;i++)
			{
			b[a[i][j]]++;
			}
			for(int i=0;i<n;i++)
			{
				if(r[a[i][j]]<b[a[i][j]])
				r[a[i][j]]=b[a[i][j]];
				b[a[i][j]]=0;
			}
		}
		int ll=0;
		for(int i=0;i<=l;i++)
		{
			sum[i]=c[i]+r[i];
			if(ll<sum[i])
			ll=sum[i];
		}
		cout<<ll<<endl;
	}
	return 0;
}
