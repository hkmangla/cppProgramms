#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,h=0,k,i,j;
		cin>>n;
		n = n-1;
		int nn=n;
		while(n--){
				cin>>i>>j>>k;
                if(h<k)
                	h=k;
		}
        cout<<h<<endl;
        while(nn--)
        	cout<<"0\n";
	}
	return 0;
}