#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		char a[1001],b[1001];
		cin>>a>>b;
		int l=0;
		for(int i=0;i<strlen(a);i++)
		{
			for(int j=0;j<strlen(b);j++)
			{
				if(a[i]==b[j])
				{
					l=1;
					break;
				}
			}
		}
		if(l==0)
		cout<<"No\n";
		if(l==1)
		cout<<"Yes\n";
	}
	return 0;
}
