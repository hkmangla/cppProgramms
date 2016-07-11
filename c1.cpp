#include<iostream>
#include<math.h>
using namespace std;
int main()
{
		int x[5],y[5],i,j,k;
	for(int i=0;i<4;i++)
	{
		cin>>x[i]>>y[i];
	}
	int m,n,area;
	m=sqrt(pow(x[1]-x[0],2)+pow(y[1]-y[0],2));
	n=sqrt(pow(x[1]-x[2],2)+pow(y[1]-y[2],2));
	k=sqrt(pow(x[2]-x[0],2)+pow(y[2]-y[0],2));
	if(m>=n&&m>=k)
	{
	area = n*k;
	}
	if(n>=m&&n>=k)
	{
	area = m*k;
	}
	if(k>=n&&k>=m)
	{
	area = n*m;
	}
	cout<<area<<endl;
	return 0;
}
