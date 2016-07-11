//Problem Code : 
//Codechef Id : hemant_1996
//Codechef Name : Hemant Mangla
//
#include<iostream>
using namespace std;
namespace ii {
	int n,i,j,k=0,l=0,m=0,x=0,y=0,a[100001];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		using namespace ii;
		cin>>n>>m>>k;
		l = n-m;
		if(l<0)
		l=-l;
		if(l>k)
		cout<<l-k<<endl;
		if(l<=k)
		cout<<"0\n";
		
	}
}
