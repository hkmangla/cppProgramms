#include<iostream>
#include<math.h>
#define mod 1000000007
using namespace std;
int check(int m,int aa[],int a[])
{
	int sum=0;int ii=300;
	for(int i=0;i<m;i++)
	{
	//	cout<<"1 ";
		if(a[aa[i]]==1)
		{
			int kf=aa[i];
			sum++;
		//	if(m==14)
		//	cout<<kf<<endl;
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<m;k++)
				{
					if(ii!=k)
					{
						if(kf==aa[k])
						{
					//	if(m==14)
		            //	cout<<kf<<endl;
							if(k%2==0)
							{
								ii=k+1;kf=aa[ii];sum++;
								break; 
							}
							if(k%2==1)
							{
								ii=k-1;kf=aa[ii];sum++;
								break;
							}
						}
					}
				}
				if(a[kf]==1)
				{
					a[kf]=0;
		//								if(m==14)
		//	cout<<kf<<endl;
					break;
				}
			}
		}
	}
	return sum;
}
int main()
{int t;cin>>t;              
while(t--)
{
	int m;cin>>m;int a[100],b[10000]={0};
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	//	cout<<a[i]<<" "<<b[a[i]]<<"\n";
	}
	int size=m;
	    	for(int ii=0;ii<m-1;ii++)
					{
					//	int kc=0;
						for(int jj=ii+1;jj<m;jj++)
						{
							if(a[ii]==a[jj])
							{
							size--;
							b[a[ii]]++;
						//	kc++;
						}}
					//	if(kc>=2)
				//		{
				//			size=0;
				//			break;
				//		}
					}
	cout<<check(m,a,b)<<" "<<size;
}}
