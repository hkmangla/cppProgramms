#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;cin>>t;
	long long int ifc[100001],fact[100001]; int mod=1000000007;
	fact[0]=1;fact[1]=1,ifc[0]=1,ifc[1]=1;
	for(int i=2;i<100001;i++)
	{
	fact[i]=(i*fact[i-1])%mod;
	ifc[i] = ((mod-mod/i)*ifc[mod%i])%mod;
	}
	for(int i=2;i<100001;i++)
	{
	ifc[i] = (ifc[i-1]*ifc[i])%mod;
	}
	while(t--)
	{
		char a[100001];
		cin>>a;
		int n=strlen(a),f[26]={0};
		for(int i=0;i<n;i++)
		f[a[i]-97]++;
		long long int p=fact[n],ans,tt=1;
		for(int i=0;i<26;i++)
		{
			p= (p*ifc[f[i]])%mod;
		}
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<i;j++)
			{
			tt+=(f[i]*f[j]);
			tt%=mod;
			}
		}
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<i;j++)
			for(int k=0;k<j;k++)
			{
			tt+=(f[i]*f[j]*f[k]*2);
			tt%=mod;
			}
		}
		
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<i;j++)
			{
			tt+=((((f[i]*(f[i]-1))/2)%mod)*((f[j]*(f[j]-1))/2)%mod);
			tt%=mod;
			}
		}
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
			{
			if(i!=j)
			{
			for(int k=0;k<j;k++)
			{
				if(i!=k)
			tt+=(((f[i]*f[j])%mod)*((f[k]*(f[i]-1))%mod));
			tt%=mod;
			}
			}
			}
		}
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<i;j++)
			for(int k=0;k<j;k++)
		for(int l=0;l<k;l++)
		{
			tt+=(((f[i]*f[j])%mod)*((f[k]*f[l]*3)%mod));
			tt%=mod;
		}
		}
		ans = (p*p - p*tt)%mod;
		if(ans<0)
		ans+=mod;
		cout<<ans<<endl;
	}
	return 0;	
}
