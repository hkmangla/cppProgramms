#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,r,g,b;
		cin>>r;
		cin>>g;
		cin>>b
		cin>>k;
		int ans = 3*k - 2;
		if(r < (k-1)) ans = ans - k+1 + r;		
		if(g < (k-1)) ans = ans - k+1 + g;
		if(b < (k-1)) ans = ans - k+1 + b;	
        cout<<ans<<endl;
	}
	return 0;
}