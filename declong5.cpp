#include<iostream>
using namespace std;
long long max(long long m,long long n)
{
	return ( m >= n)?m:n;
}
long long min(long long m,long long n)
{
	return ( m >= n)?n:m;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m,l,b,r,z,sb,sz,rb,rsb,rsz,ts,tsr,usb,sbc,tsc;
		cin>>n>>m>>z>>l>>r>>b;
		ts = n*m;
		sb = n*((m+1)/2);
		sz = sb - n;
		usb = sb;
		rsb = 0;
		if(z < sz)
		{
			usb = sb -(sz - z);
			rsb = sb - usb;
		}
		if(b < usb)
		{
			sbc = b;
			rb = 0;
		}
		if(b >= usb)
		{
			sbc = usb;
			rb = b - sbc;
			if(rb > rsb)
			rb = rsb; 
		}
		if((z+sbc) < ts)
		tsr = ts - z - sbc;
		if((z+sbc) >= ts)
		tsr = 0;
		if((l+r) >= tsr)
		tsr = 0;
		if((l+r) < tsr)
		{
		 tsr = tsr - (l+r);	
		}   
		if( rb != 0 && tsr != 0)
		{
			if(rb >= (tsr/2))
			tsr=(tsr+1)/2;
			else
			tsr = tsr - rb;
		}
		tsc = ts - tsr;
		cout<<tsc<<endl;
	}
}
