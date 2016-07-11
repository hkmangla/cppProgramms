#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,m,k,a[100001];
	long long int sum = 0,amin1=0,amin2=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int first=0,last = n-1;
	cout<<sum<<" ";
	for(int i=1;i<k;i++)
	{
		if(a[first]>=a[last])
		{
			sum-=a[last];
			last-=1;
			amin1 += a[last];
		}
		if(a[first]<a[last])
		{
			sum-=a[first];
			first+=1;
			amin2 += a[first];
		}
		long long int ans = sum;
		if(amin1>ans)
			ans= amin1;
		if(amin2>ans)
			ans = amin2;
		cout<<ans<<" ";
	}
	cout<<endl;
	return 0;
}