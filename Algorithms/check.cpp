#include<iostream>
using namespace std;
int gcf(int a, int b)
{
	if(b==0)
	return a;
	else
	return gcf(b, a%b);
}
int main()
{
	int t,n,i,a[20000];
	cin>>t;
	while(t--)
	{
		for(i=0;i<20000;i++)
		a[i]=0;
		cin>>n;
		for(int j=3001;j<=n;j++)
		{
	    	for(i=1;i<=j;i++)
		    {
			   int l=j/gcf(i,j);
		       if(l==j)
			   a[l]++;
		    }
			cout<<a[j]<<",";
	    }
    }
}
