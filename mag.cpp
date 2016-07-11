#include<iostream>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int a[100001],i,l1,l2,l=1;
		for(i=0;i<n;i++)
		cin>>a[i];
		if(n<3)
		{
			cout<<"Magical Array\n";
			continue;
		}
		if(a[n-1]>a[n-2])
		{
			l1=a[n-2];
			l2=a[n-1];
		}
		if(a[n-1]<a[n-2])
		{
			l2=a[n-2];
			l1=a[n-1];
		}
		if(a[n-1]==a[n-2])
		{
			cout<<"Not Possible\n";
			continue;
		}
		for(i=n-3;i>=0;i--)
		{
			if(a[i]>=l1&&a[i]<=l2)
			{
				l=0;
			//	cout<<i<<" ";
				break;
			}
			if(a[i]<l1)
			l1=a[i];
			if(a[i]>l2)
			l2=a[i];
		}
		if(l==1)
		cout<<"Magical Array\n";
		if(l==0)
		cout<<"Not Possible\n";
	}
	return 0;
}
