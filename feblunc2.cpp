#include<iostream>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,k,jj=0; char a[1001][1001];
		cin>>n>>k;
		for(int i=0;i<n;i++)
		cin>>a[i];
		for(int i = 0;i<n;i++)
		{
			int kk=0,ll=0,l=0;
			for(int j=0;j<n;j++)
			{
				if(a[i][j]=='X')
				{
					kk++;
					ll++;
				}
				if(a[i][j]=='.')
				{
					if(l==0)
					kk++;
					if(l==1)
					{
						kk=ll;
						kk++;
					}
					ll = 0;
					l=1;
				}
				if(a[i][j]=='O')
				{
				kk = 0;
				ll=0;
				}
				if(kk>=k)
				{
					jj = 1;
					break;
				}
		    	}
     			if(kk>=k)
				{
					break;
			}
		}
		for(int j = 0;j<n;j++)
		{
			int kk=0,ll=0,l=0;
			for(int i=0;i<n;i++)
			{
				if(a[i][j]=='X')
				{
					kk++;
					ll++;
				}
				if(a[i][j]=='.')
				{
					if(l==0)
					kk++;
					if(l==1)
					{
						kk=ll;
						kk++;
					}
					ll = 0;
					l=1;
				}
				if(a[i][j]=='O')
				{
				kk = 0;
				ll=0;
				}
				if(kk>=k)
				{
					jj=1;
					break;
				}
		    	}
     			if(kk>=k)
				{
					break;
			}
		}
		for(int ii = 0;ii<n;ii++)
		{
			int kk=0,ll=0,l=0,i=ii,j=n-1;
			while(i<=(n-1))
			{
				if(a[i][j]=='X')
				{
					kk++;
					ll++;
				}
				if(a[i][j]=='.')
				{
					if(l==0)
					kk++;
					if(l==1)
					{
						kk=ll;
						kk++;
					}
					ll = 0;
					l=1;
				}
				if(a[i][j]=='O')
				{
				kk = 0;
				ll=0;
				}
				if(kk>=k)
				{
					jj=1;
					break;
				}
				i++;
				j--;
		   	}
     		if(kk>=k)
			{
				break;
			}
		}
		for(int ii = 0;ii<n;ii++)
		{
			int kk=0,ll=0,l=0,i=ii,j=n-1;
			while(i>=0)
			{
				if(a[i][j]=='X')
				{
					kk++;
					ll++;
				}
				if(a[i][j]=='.')
				{
					if(l==0)
					kk++;
					if(l==1)
					{
						kk=ll;
						kk++;
					}
					ll = 0;
					l=1;
				}
				if(a[i][j]=='O')
				{
				kk = 0;
				ll=0;
				}
				if(kk>=k)
				{
					jj=1;
					break;
				}
				i--;
				j--;
		   	}
     		if(kk>=k)
			{
				break;
			}
		}
		for(int ii = 0;ii<n;ii++)
		{
			int kk=0,ll=0,l=0,j=ii,i=0;
			while(j>=0)
			{
				if(a[i][j]=='X')
				{
					kk++;
					ll++;
				}
				if(a[i][j]=='.')
				{
					if(l==0)
					kk++;
					if(l==1)
					{
						kk=ll;
						kk++;
					}
					ll = 0;
					l=1;
				}
				if(a[i][j]=='O')
				{
				kk = 0;
				ll=0;
				}
				if(kk>=k)
				{
					jj =1;
					break;
				}
				i++;
				j--;
		   	}
     		if(kk>=k)
			{
				break;
			}
		}
		for(int ii = 0;ii<n;ii++)
		{
			int kk=0,ll=0,l=0,i=ii,j=0;
			while(i<=(n-1))
			{
				if(a[i][j]=='X')
				{
					kk++;
					ll++;
				}
				if(a[i][j]=='.')
				{
					if(l==0)
					kk++;
					if(l==1)
					{
						kk=ll;
						kk++;
					}
					ll = 0;
					l=1;
				}
				if(a[i][j]=='O')
				{
				kk = 0;
				ll=0;
				}
				if(kk>=k)
				{
					jj=1;
					break;
				}
				i++;
				j++;
		   	}
     		if(kk>=k)
			{
				break;
			}
		}
		if(jj==1)
		cout<<"YES\n";
		if(jj==0)
		cout<<"NO\n";		
	}
	return 0;
}
