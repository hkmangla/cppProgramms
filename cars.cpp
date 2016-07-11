#include<iostream>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		char a[501];
		cin>>a;
		int n = strlen(a);
		if(n%3!=0)
		cout<<"Not Ok\n";
		else
		{int l=0;
		for(int i=1;i<n/3;i++)
		{
			if(a[i]!=a[i-1])
			{
				cout<<"Not Ok\n";l=1;
				break;
			}

		}
        for(int i=n/3;i<2*n/3;i++)
		{
			if(a[i]!=a[i-1])
			{
				cout<<"Not Ok\n";l=1;
				break;
			}

		}
		}
	}
}
