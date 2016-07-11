//Problem Code : 
//Codechef Id : hemant_1996
//Codechef Name : Hemant Mangla
//
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
namespace ii {
	int n,i,j,k=0,l=0,m=0,x=0,y=0;//a[100001];
}
int numlen(int n)
{
	int k,m=n;
	for(int i=0;i<n;i++)
	{
		m/=10;
		k++;
		if(m==0)
		return k;
	}
}
int rev(int kk)
{
	int l=0,k=kk,n=numlen(kk),j=0,a[100];
//	cout<<n;
	while(1)
	{
		int o=k%10;
		a[j]=o;
	//	l+=pow(10,(n-j))*0;
		k/=10;
		j++;
		if(k==0)
		break;
	//	cout<<l<<" ";
	}
	for(int i=0;i<j;i++)
	{
		l+=pow(10,j-1-i)*a[i];
	}
	return l;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		using namespace ii;
         cin>>n;
         if(n<10)
         cout<<"11\n";
         else{
         m=numlen(n);
         k=n;
         k/=pow(10,m/2);
      //   cout<<k<<" ";
         int kk=k;
		 if(m%2==1)
         kk = k/10;
         l=k*pow(10,m/2)+rev(kk);
      //   cout<<rev(k)<<" ";
         while(l<=n)
         {
         	k++;
         	kk=k;
         	if(m%2==1)
         	kk=k/10;
         	l=k*pow(10,m/2)+rev(kk);
		 }
		 cout<<l<<endl;
		 }
	}
	return 0;
}
