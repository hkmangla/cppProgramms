#include<iostream>
using namespace std;
int maxx(int a,int b)
{
	if(a<0)
	a=-a;
	if(b<0)
	b=-b;
	return (a>=b)?a:b;
}
int min(int a,int b)
{
	return (a<=b)?a:b;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,i,j,k,proof=0; char aa[1001][1001]; bool a[1001][1001];
		cin>>n>>m;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>aa[i][j];
				if(aa[i][j]=='*')
				{
				a[i][j]=true;
				proof=1;
			   }
				else
				a[i][j]=false;
			}
		 }
		 if(proof==0)
		 {
		 	cout<<"0\n";
		 	continue;
		 }
		 int tx,ty; 
		for(i=0;i<n;i++)
		{ 
			for(j=0;j<m;j++)
			{
				if(a[i][j]==true)
				{
					tx=i;ty=j;
					break;
				}
			}
		 }
		int lx,ly; 
		for(i=0;i<m;i++)
		{ 
			for(j=0;j<n;j++)
			{
				if(a[j][i]==true)
				{
					lx=j;ly=i;
					break;
				}
			}
		 } 
		int bx,by; 
		for(i=n-1;i>=0;i--)
		{ 
			for(j=m-1;j>=0;j--)
			{
				if(a[i][j]==true)
				{
					bx=i;by=j;
					break;
				}
			}
		 }
		int rx,ry; 
		for(i=m-1;i>=0;i--)
		{ 
			for(j=n-1;j>=0;j--)
			{
				if(a[j][i]==true)
				{
					rx=j;ry=i;
					break;
				}
			}
		 }
		 int x=(tx+bx)/2;
		 int y=(ly+ry)/2;
		 int mxx=10000,my,mx,mxxx=10000;
		 for(i=0;i<n;i++)
		 {
		 	for(j=0;j<m;j++)
		 	{
		 		if(a[i][j]==true)
		 		{
		 			int mxy=maxx(i-x,j-y);
		 			int xx=i-x,yy=j-y;
		 			if(xx<0)
		 			xx=-xx;
		 			if(yy<0)
		 			yy=-yy;
		 			int mxay=xx+yy;
		 		    if(mxx>=mxy)
		 		    {
		 		    	if(mxxx>mxay)
		 		    	{
					        mxxx=mxay;
		 		        	mxx=mxy;
		 		        	mx=i;
		 		            my=j;
		 		        }
					}
				 }
			 }
		 }
		 lx=maxx(lx-mx,ly-my);
		 rx=maxx(rx-mx,ry-my);
		 tx=maxx(tx-mx,ty-my);
		 bx=maxx(bx-mx,by-my);
		 int ans=0;
		 ans=maxx(maxx(maxx(lx,rx),bx),tx)+1;
		 cout<<ans<<endl;
	}
	return 0;
}
