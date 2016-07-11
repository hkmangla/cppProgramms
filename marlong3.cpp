#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int d;cin>>d;
	while(d--)
	{
		char x,a[1000007];
		cin>>a;
		int n=strlen(a),ans=1,l=0,c[29];
		if(n==1)
		{
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<29;i++)
		c[i]=0;
		for(int i=0;i<n;i++)
		{
			int k = a[i]-97;
			c[k]++;
		}
		for(int i=0;i<27;i++)
		{
			if(c[i]%2==1)
			{
				l++;
				x=i+97;
			}
		}
		if(l>1)
		{
		cout<<"NO\n";
		ans=0;
		}
		int f=0,j;
		j=n/2;
		if(l<2)
		{
			if(l==0)
			{
				for(int i=0;i<n/2;i++)
				{
					if(a[i]!=a[i+n/2])
					{
					ans=0;
					cout<<"NO\n";
					break;
					}
				}
			}
			 if(l==1)
			{
				int xx=x,y=c[xx-97];
				if(y*n > 1000000)
				{
				int o=0,p=0,g=0;
				for(int i=0;i<n/2;i++)
				{
					if(j==n/2)
					{
					if(a[0]!=a[j])
					j++;
					}
					if(o==0&&p==0)
					{
					if(a[i+o]!=a[i+j+p])
					{
					if(a[i+o]==x)
					{
					o++;
					}
					if(a[i+j+p]==x)
					{
					p++;
					}
					g++;
					if(g==2)
					{
						ans=0;
					cout<<"NO\n";
					break;	
					}
					}
					}
					if(o!=0||p!=0)
					{
					if(a[i+o]!=a[i+j+p])
					{
					ans=0;
					cout<<"NO\n";
					break;	
					}
				    }
				a[i+o]=0;
				a[i+j+p]=0;
				}			
				}
				
			else
			{
				int k=-1,p=0,m=n-1;
				while(y--)
				{
				char b[1000006]; int r=0,j=0;
				for(int i=0;i<n;i++)
				{
					if(i>k&&a[i]==x&&j==0)
					{
					j++;
					k = i;
					continue;
					}
					b[r]=a[i];
					//cout<<b[r]<<" ";
					r++;
				
				}
				for(int i=0;i<m/2;i++)
				{
					if(b[i]!=b[i+m/2])
					{
					p++;
					//cout<<"NO\n";
					break;
					}
				}
				}
				if(p==c[xx-97])
				{
					cout<<"NO\n";
					ans=0;
				}
			}
			}
		}
		if(ans==1)
		cout<<"YES\n";
	}
	return 0;
}
