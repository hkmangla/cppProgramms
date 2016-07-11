#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	FILE fb = fopen("")
	int t,f=0;cin>>t;
	while(t--)
	{	
	int c,n;fscanf(fb"")
	int a[n],x=0,y=0;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		for(int j=1;j<n;j++)
		{
			if((a[i]+a[j])==c && i!=j){
				if(a[i]>=a[j])
				{
					x=i;
					y=j;
				}
				else
				{
					x=j;
					y=i;
				}
				break;
			}
		}
		if((x+y)!=0)
			break;
	}
	x++;y++;
	f++;
	cout<<"Case #"<<f<<": "<<x<<" "<<y<<endl;
	}
	return 0;
}