// DYNAMIC PROGRAMMING PROBLEM in JAN16 CHALLANGE
#include<iostream>
using namespace std;
typedef long long int ll;
ll a[1001][2001];
int main()
{
	long long int n,m,d;
	cin>>n>>m>>d;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2*m;j++)
		{
			cin>>a[i][j];
		}
	}
	
	return 0;
}
