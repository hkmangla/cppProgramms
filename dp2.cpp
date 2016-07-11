#include<iostream>
using namespace std;
int dp(int a[], int n)
{
	int i,b[n];
	int res,re=0,min = INT_MAX;
	for(i=0;i<n-1;i++)
	{
		for(int j=0;j<i;j++)
		b[j]=a[j];
		b[i]=(a[i]+a[i+1])%100;
		for(int j=i+1;j<n-1;j++)
		b[j]=a[j+1];
		res = a[i]*a[i+1] + dp(b,n-1);
		if(min>res)
		min=res;
		re = min;
	}
	return re;
}
int main()
{
	int a[100];int t,n,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i = 0;i<n;i++)
		cin>>a[i];
		cout<<dp(a,n)<<endl;
	}
	return 0;
}
