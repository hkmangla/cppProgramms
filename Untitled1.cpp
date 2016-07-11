#include<iostream>
using namespace std;
int gcf(int a, int b)
{
	if(b==0)
	return a;
	else
	return gcf(b, a%b);
}
int main()
{
	int t,n,i,j,k,l,m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>m;
		l=gcf(n,m);
		l=n/gcf(n,m);
		if(n==1)
		cout<<"Yes\n";
		else if(m==0)
		cout<<"No 1\n";
		else if(gcf(n,m)==1)
		cout<<"Yes\n";
		else
		cout<<"No "<<l<<endl;
	}
	return 0;
}
