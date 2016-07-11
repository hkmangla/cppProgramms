#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,m;
		cin>>n>>m;
		if (n==1 && m == 1)
		{
			cout<<"No\n";
			continue;
		}
		if(n==1 || m == 1)
		{
			if (n > 2 || m > 2)
				cout<<"No\n";
			else
				cout<<"Yes\n";
			continue;
		}
		if(n%2==0 || m%2==0)
			cout<<"Yes\n";
		else
			cout<<"No\n";

	}
	return 0;
}