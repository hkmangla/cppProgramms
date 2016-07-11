#include<iostream>
using namespace std;
int main()
{
	int t,i,j,k,l,n,a[100000];
	cin>>t;
	while(t--)
	{
		long long int sum = 0, j =0;
		cin>>n;
		for(i = 0; i < n; i ++)
		{
			cin>>a[i];
			sum += a[i];
		}
		l = (n * (n-1))/2;
		k = (sum - l) % n;
		if( k != 0)
		{
			cout<<"-1\n";
		}
		else
		{
			k = ( sum - l ) / n;
			for(i = 0; i < n; i++)
			{
				if(a[i] > k)
			    j = j + a[i] - k;
				k ++;
			}
			cout << j << endl;
		}
	}
}
