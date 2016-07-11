//Problem Code : 
//Codechef Id : hemant_1996
//Codechef Name : Hemant Mangla
//
#include<iostream>
#include<string.h>
using namespace std;
namespace ii {
	int n,i,j,k=0,l=0,m=0,x=0,y=0,a[100001];
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int i,j,k,l,check = 0; char a[25002],b[25002];
		cin>>a>>b;
		k = strlen(a);
		l = strlen(b);
		if(k>=l)
		{
		j=0;
		for(i=0;i<k;i++)
		{
			if(a[i]==b[j])
			j++;
			if(j==l)
			{
				cout<<"YES\n";
				check = 1;
				break;
			}
		}}
		if(k<l)
		{
			j=0;
		for(i=0;i<l;i++)
		{
			if(b[i]==a[j])
			j++;
			if(j==k)
			{
				cout<<"YES\n";
				check = 1;
				break;
			}
		}
		}
		if(check == 0)
		cout<<"NO\n";
	}
	return 0;
}
