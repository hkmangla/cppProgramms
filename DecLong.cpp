#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b,c[100000],m[100000],backup[100000];
		cin>>n;
		for(int i = 0; i < n; i ++)
		{
			cin>>a>>b>>c[i];
			m[i] = a/b; 
			backup[i] = a/b;
		}
		mergesort(m,0,n-1);
		for(int i = 0; i < n; i ++)
		{
			int l = binarysearch(m, 0, n-1, backup[i]);
			m[l] = 0;
			newc[l] = c[i];
		}
		for(i = 1;i < n; i++)
		{
			if(backup[i] == backup[i-1])
			{
				
			}
		}
	}
	retutn 0;
}
