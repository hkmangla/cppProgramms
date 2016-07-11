#include<iostream>
#include<string.h>
using namespace std;
int IsSubString(char a[],char b[])
{
	int j=0,n = strlen(a),m=strlen(b);
	for(int i=0;i<n;i++)
	{
		int k=1;
        for(j=0;j<m;j++)
		{
			if(a[i+j]!=b[j])
			{
			  k=0;
			  break;
			}
		}
		if(k==1)
		return 1;
	}
	return 0;
}
int main()
{
	int t=24;
	while(t--)
	{char a[12],b[6];
		cin>>a>>b;
		cout<<IsSubString(a,b)<<endl;
	}
}
