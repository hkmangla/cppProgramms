#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a[55],sum = 0,mul = 1,ans=0;
		cin>>n;
		for(int i = 0; i< n ; i++)
		{
			cin>>a[i];
		}
		for(int i = 0; i< n ; i++)
		{sum = 0; mul = 1;
			for(int j = i; j < n; j++)
			{
				sum = sum + a[j];
				mul = mul*a[j];
				if(sum == mul)
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
