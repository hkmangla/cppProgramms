#include<iostream>
using namespace std;
int main()
{
	int n,h,a[100001],c=1,l=0;
	cin>>n>>h;
	for(int i=0;i<n;i++)
    cin>>a[i];
    int i=0;
    while(c!=0)
    {
    	cin>>c;
    	if(c==4)
    	{
    		if(l==1)
    		{
    			if(a[i]<h)
    			{
    				a[i]++;
    				l=0;
				}
			}
		}
		if(c==1)
		{
			if(i!=0)
			i--;
		}
		if(c==2)
		{
			if(i!=(n-1))
			i++;
		}
		if(c==3)
		{
			if(l==0)
			{
				if(a[i]!=0)
				{
					a[i]--;
					l=1;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
