#include<iostream>
#include<math.h>
using namespace std;
int a[500001],b[1000001];
int main()
{
	int t,i,j,k,n;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(i = 0; i < n; i ++)
		{
		  cin>>a[i];
		  for( j = 1; j < sqrt(a[i]); j++)
		  {
			if(a[i] % j == 0)
			{
				b[j]++;
				b[a[i]/j]++;
			}
	      }
	      if((int)sqrt(a[i])==sqrt(a[i]))
	      b[(int					)sqrt(a[i])]++;
	    }
	    for( i = k; i < n; i++);
	}
}
