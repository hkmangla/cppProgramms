#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		long long int n,m,k,a[100001];
		double l=0,ll;
		cin>>n>>m>>k;
		for(int i=0;i<k;i++)
		cin>>a[i];
		ll = (m*(m+1))/2;
		for(int i =0 ;i < k;i++)
		{
			int y= a[i]%m;
			if(y==0)
			y=m;
			int x = (a[i]-1)/m;
			double u =((m-y+1)*y)/ll;
			u = u*((n-x)*(x+1));
			l+=u;
		}
		ll = (n*(n+1))/2;
		double ans = l/ll;
		printf("%0.16f\n",ans);
	}
}
