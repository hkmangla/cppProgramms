//Problem Code : 
//Codechef Id : hemant_1996
//Codechef Name : Hemant Mangla
//
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
namespace ii {
	int n,i,j,k=0,l=0,m=0,x=0,y=0,a[100001];
}
int main()
{
	int t,sub;
	cin>>sub;
	cin>>t;
	while(t--)
	{
		//using namespace ii;
	     int d[4],x[4],y[4]; double m[4],ang[4];
	     for(int i=0;i<3;i++)
	     cin>>x[i]>>y[i];
	     d[0]=pow(x[0]-x[1],2)+pow(y[0]-y[1],2);
	     d[1]=pow(x[2]-x[1],2)+pow(y[2]-y[1],2);
	     d[2]=pow(x[0]-x[2],2)+pow(y[0]-y[2],2);
	     if(d[0]==d[1]||d[0]==d[2]||d[1]==d[2])
	     cout<<"Isosceles ";
	     else
	     cout<<"Scalene ";
	     if(sub == 1)
	     {
	     	cout<<"triangle\n";
		 }
		 if(sub == 2)
		 {	
		 ang[0]=d[0]+d[1]-d[2];
		 ang[1]=d[2]+d[1]-d[0];
		 ang[2]=d[0]+d[2]-d[1];
		 int j=0;
		 for(int i = 0;i<3;i++)
		 {
		 	if(ang[i]<0)
		 	{
			 j=1;
			 break;
			 }
		 	if(ang[i]==0)
		 	j=2;
		 	
		 }
		 if(j==1)
		 cout<<"obtuse triangle\n";
		 if(j==0)
		 cout<<"acute triangle\n";
		 if(j==2)
		 cout<<"right triangle\n";
		 }
		 
	}
}
