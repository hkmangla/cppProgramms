#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	double n,m,k; char c;
	cin>>n>>m;
	while(m--)
	{
		cin>>c>>k;
		if(c=='+')
				n+=k;
		if(c=='/')
				n/=k;
		if(c=='*')
				n*=k;
		if(c=='-')
				n-=k;
	}
	printf("%0.2lf",n);	
}
