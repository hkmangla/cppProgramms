#include<iostream>
using namespace std;
int o[1000001];
int bin(int a,int b,int item)
{
    while(a<=b)
    {
    	int mid= (a+b)/2;
    	if(item==mid)
    	return 1;
    	else if(item<mid)
    	b=mid-1;
    	else
    	a=mid+1;
	}
	return 0;
}
int main()
{
	int n,k,J;

	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>J;
		o[J]=1;
	}
	for(int i=1;i<=n;i++)
	{
	if(o[i]==0)
	cout<<i<<" ";
	}
	for(int i=0;i<=n;i++)
	{
		o[i]=0;
	}
return 0;
}
