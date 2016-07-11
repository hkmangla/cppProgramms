#include<iostream>
using namespace std;
long long int digit_sum(long long int n)
{
	long long int i,k;
	for(int j=0;j<20;j++)
	{
	   if(n/10!=0)
	   {
            k=0;	
     	    for(i=0;i<20;i++)
         	{
	    	    k=k+n%10;
	        	n/=10;
	 	        if(n==0)
	        	break;
	        }
	        n=k;
	   }
    }
    return n;
 } 
int main()
{
	int t;
	unsigned long long int n,d,l,r,i,j,k,m;
	cin>>t;
	while(t--)
	{
		unsigned long long int y,h,ans = 0;
		cin>>n>>d>>l>>r;
		n = digit_sum(n);
		m = digit_sum(d);
		for(y=0;y<(l-1)%9;y++)
		{
			n = n + m;
		}
		n = digit_sum(n);;
	//	cout<<m<<endl;
		j = r-l+1;
		if(m==9||m==0)
		ans = j*n;
		if(m==3||m==6)
		{
			if(n==1||n==4||n==7)
			{
			   ans = 12*(j/3);
	    	  	long long int o = n;
		    	for(y=0;y<j%3;y++)
			    {
				   ans = ans + o;
			    	o = digit_sum(o+m);
		    	}
		    }
		   	if(n==2||n==5||n==8)
			{
			  ans = 15*(j/3);
		  	long long int o = n;
			for(y=0;y<j%3;y++)
			{
				ans = ans + o;
				o= digit_sum(o+m);
			}
		    }
		   	if(n==3||n==6||n==9)
			{
			  ans = 18*(j/3);
		  	long long int o = n;
			for(y=0;y<j%3;y++)
			{
				ans = ans + o;
				o = digit_sum(o+m);
			}
		    }
		}
		if(m%3!=0)
		{
			long long int o = n;
			ans = 45*(j/9);
			for(y=0;y<j%9;y++)
			{
				ans = ans + o;
				o= digit_sum(o+m);
			}
		}
		cout<<ans<<endl;
	 } 
	 return 0;
}
