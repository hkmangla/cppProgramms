#include<iostream>
using namespace std;
int main(){
	long long int n,t;cin>>n>>t;
	while(t--)
	{
		long long int q;
		cin>>q;
		if(q>(n+1) && q<=(3*n))
		{
			q-=(n+1);
			if(q<=n)
				cout<<q<<endl;
			else
			{
				q-=n;
				q = n - q;
				cout<<q<<endl;
			}
		}
		else
			cout<<"0\n";
	}
}