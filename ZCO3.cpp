#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long int x,ans=0,a[1001];
	for(int i=0;i<1001;i++)
	a[i]=0;
	for(int i=0;i<n;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=0;i<1001;i++)
	{
		for(int j=i;j<1001;j++)
		{
			ans+=(a[i]*a[j])*(j-i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
