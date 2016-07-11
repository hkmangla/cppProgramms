#include<iostream>
#include<string.h>
using namespace std;

int main(){
	long long int fact[100001]; int mod=1000000007;
fact[0]=1; fact[1]=1;
for(int i=2;i<100001;i++)
fact[i]=(i*fact[i-1])%mod;
	int t; cin>>t;
	while(t--)
	{
		char a[1000003];
		cin>>a;
		int n=strlen(a),c[27],l=0;
		for(int i = 0;i<27;i++)
		c[i]=0;
		for(int i=0;i<n;i++)
		{
			int k = a[i]-97;
			if(c[k]==0)
			{
				c[k]++;
				l++;
			}
		}
		long long int ans=(fact[l]*fact[l-1])%mod;
		if(l>3)
		cout<<ans<<endl;
		else
		cout<<"0\n";
	}
	return 0;
}
