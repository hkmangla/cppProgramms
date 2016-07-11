#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int digit(int n)
{
	int k = 0;
	for(int i=0;i<10;i++)
	{
		n/=10;
		k++;
		if(n==0)
		break;
	}
	return k;
}
int make(int a[],int n)
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		k=a[i]*pow(10,i)+k;
	}
	return k;
}
int makeans(int a,int n)
{
	int k=0,aa[10];
	for(int i =0;i<2;i++)
	{
		aa[i]=a%10;
	    
	}
}
void ans(int k)
{
		int a[10],n=k,l = digit(k);
		for(int i=0;i<l;i++)
		{
			a[i]=n%10;
			n=n/10;
		}
		//printf("%d\n",answer);
}
int main()
{
	int t,k;
	cout<<8 and 10; 
	cin>>t;
	while(t--)
	{
		cin>>k;
		ans(k);
	}
	return 0;
}
