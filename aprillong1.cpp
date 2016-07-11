#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char a[100001]; int n,r=0,g=0,b=0;
		cin>>n;
		cin>>a;
		n = strlen(a);
		for(int i=0;i<n;i++)
		{
			if(a[i]=='R')
				r++;
			if(a[i]=='B')
				b++;
			if(a[i]=='G')
				g++;
		}
    cout<<n-max(r,max(g,b))<<endl;
	}
	return 0;
}