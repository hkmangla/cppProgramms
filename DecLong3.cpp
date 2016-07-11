#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		char a[103],b[103]; int m,MinSizeA = 1000,MinSizeB=1000;
		cin>>n;
		while(n--)
		{
			int sizeA = 0,sizeB = 0;
			cin>>a;
			m = strlen(a);
			for(int i = 0; i < m; i++)
			{
				if(a[i] =='a')
				sizeA++;
				else
				sizeB++;
			}
			if(MinSizeA > sizeA)
			MinSizeA = sizeA;
			if(MinSizeB > sizeB)
			MinSizeB = sizeB; 
		}
		int l = (MinSizeA > MinSizeB) ? MinSizeB : MinSizeA;
		cout<<l<<endl;
	}
}
