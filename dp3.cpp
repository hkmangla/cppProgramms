#include<iostream>
using namespace std;
#include<string.h>
int b[1000001];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		char a[1000001],n;
		cin>>a;
		n=strlen(a);
		for(int i=0;i<n-2;i++)
		{
			if(a[i]!=a[i+1]||a[i]!=a[i+2]||a[i+1]!=a[i+2])
			b[i]++;
		}
		int k1=0,k2=0,k3=0,l=0;
		for(int i=0;i<n;i++)
		{
			if(i%3==0)
			{
				if(b[i]==1)
				k1++;
				if(b[i]==0)
				k1=0;
			}
			if(i%3==1)
			{
				if(b[i]==1)
				k2++;
				if(b[i]==0)
				k2=0;
			}
			if(i%3==2)
			{
				if(b[i]==1)
				k3++;
				if(b[i]==0)
				k3=0;
			}
			l = max(max(l,k1),max(k2,k3));
		}
		cout<<n-3*l<<endl;
		for(int i=0;i<n;i++)
		{
			b[i]=0;
		}
	}
	return 0;
}
