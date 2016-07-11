#include<iostream>
using namespace std;
int a[1001][1001],b[1000001],c[1000001];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,m,l=0;
		cin>>n>>m;
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
				for(int k=0;k<m;k++)
				b[a[i][k]]++;
				for(int k=0;k<n;k++)
				{
					if(k!=i)
					b[a[k][j]]++;
				}
				for(int ii=1;ii<=l;ii++)
				{
					if(c[ii]<b[ii])
					c[ii]=b[ii];
			    	b[ii]=0;
				}
			}	
		}
		int ll=0;
		for(int i=0;i<=l;i++)
		{
			if(ll<c[i])
			ll=c[i];
		}
		for(int i=0;i<=l;i++)
		{
			b[i]=0;
			c[i]=0;
		}
		cout<<ll<<endl;
	}
	return 0;
}
