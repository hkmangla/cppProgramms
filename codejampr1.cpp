#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	FILE* fin = fopen("inpjam1.txt","r");
	FILE* fou = fopen("outjam1.txt","w");
	int t,x=1;//cin>>t;
	fscanf(fin,"%d",&t);
	while(t--){
		int n,max=0,y=0,z=0;fscanf(fin,"%d",&n);
		int a[10001];
		for (int i=0;i<n;i++)
		fscanf(fin,"%d",&a[i]);
		for (int i=0;i<n-1;i++)
		{
     		if((a[i]-a[i+1]>0))
     		{
     			y+=(a[i]-a[i+1]);
     			if((a[i]-a[i+1])>max)
     				max=(a[i]-a[i+1]);
     		}
		}
		for (int i=0;i<n-1;i++)
		{
			if(a[i]>max)
				z+=max;
			else
				z+=a[i];
		}
		fprintf(fou,"Case #%d: %d %d\n",x,y,z);
		x++;
	}
	return 0;
}