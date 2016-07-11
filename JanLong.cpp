#include<iostream>
#include<math.h>
using namespace std;
int prime[100000];
void addprime()
{
	int x,i,j,k=3;
	prime[0]=2;
prime[1]=3;
prime[2]=5;
	for(i=6;i<=100000;i++)
	{
		x=0;
		if(i%6==1||i%6==5)
		{
		for(j=2;prime[j]<sqrt(i)+1;j++)
		{
			if(i%prime[j]==0)
			{
				x=1;
				break;
			}
		}
		if(x==0)
		{
			prime[k]=i;
			k++;
		}
	}
	}
}
int main()
{
//	ios::sync_with_stdio(false);
	addprime();
	int t,i,j,k,l;
	cin>>t;
	while(t--)
	{
		int ans=0;
		int n,a[100001];
		cin>>n;
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=1;i<n;i++)
		{
			if(a[i]<a[i-1])
			{
				ans+=a[i-1]-a[i];
				a[i]=a[i-1];
			}
		}
		int tt,x=1000000;
		j=0;
		while(1)
		{
			k=prime[j];
			l=0;tt=0;
			for(i=0;i<n;i++)
			{
				l+=(k-a[i]%k)%k;
				tt+=k-a[i];
			}
			if(x>l)
			x=l;
			if(tt>=x||x==0)
			break;
			j++;
		}
		ans+=x;
		cout<<ans<<endl;
	}
	return 0;
}
