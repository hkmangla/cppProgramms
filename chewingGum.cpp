#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int n,k;
	// int b[4] = {1,2,4,5};
	// cout<<lower_bound(b,b+4,3)-b<<endl;
	scanf("%lld%lld",&n,&k);
	long long int a[100001];
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	// for(long long int i=0;i<n;i++)
	// {
	// 	if(a[i]>=k)
	// 	{
	// 		n = i;
	// 		break;
	// 	}
	// }
	long long int ans = 0;
	for(long long int i=n-1;i>0;i--)
	{
		long long int f = lower_bound(a,a+i,a[i]-k+1) - a;
		// cout<<f<<endl;
		ans += f;
	}
	printf("%lld\n",ans );;
	return 0;
}