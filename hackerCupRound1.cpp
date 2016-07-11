#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	FILE *fp,*fpp;
	fp = fopen("output5.txt","w");
	fpp = fopen("input.txt","r");
	int t,f=0;//cin>>t;
	fscanf(fpp,"%d",&t);
	while(t--)
	{
		int j=0,k=0,l=0,n,a[100001];
		//cin>>n;
		fscanf(fpp,"%d",&n);
		for(int i=0;i<n;i++)
		{
			//cin>>a[i];
			fscanf(fpp,"%d",&a[i]);
		}
		int ans=0;//a[n]=0;
		for(int i=0;i<n-1;i++)
		{
			k++;
		//	cout<<k<<endl;
			if(k==4)
			{
				k=0;
				continue;
			}
			else if(a[i]>=a[i+1]||((a[i+1]-a[i]-1)/10)>=(4-k))
			{
				ans+=(4-k);
				k=0;
			}
			else if(((a[i+1]-a[i]-1)/10)<(4-k))
			{
				ans+=(a[i+1]-a[i]-1)/10;
				k+=	(a[i+1]-a[i]-1)/10;
			}
		}
		k++;
		ans+=(4-k)%4;
		f++;
		cout<<"Case #"<<f<<": "<<ans<<endl;
		fprintf(fp,"Case #%d: %d\n",f,ans);
	}
	fclose(fp);
	return 0;
}
