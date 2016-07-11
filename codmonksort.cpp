#include<iostream>
using namespace std;
int b[1000001];
int main()
{
	int t;cin>>t;
	FILE *fp;
	fp = fopen("o.txt","w");
	while(t--)
	{
		int l=0,n,a[100001];
		cin>>n;
		for(int i=0;i<n;i++)
		{
		cin>>a[i];
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					b[a[i]]++;
				}
			}
		}
		
		for(int i=0;i<n;i++)
		{
		cout<<b[a[i]]<<" ";
		fprintf(fp,"%d ",b[a[i]]);
		b[a[i]]=0;
		}
		cout<<endl;
		fprintf(fp,"\n");
	}
	return 0;
}
