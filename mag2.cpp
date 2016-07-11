#include<iostream>
using namespace std;
int main()
{int t;cin>>t;
while(t--)
{
 long long int s=0,n,k,a[100001],l=0;
 cin>>n>>k;
 for(int i=0;i<n;i++)
 {
 	cin>>a[i];
 }
 for(int i=0;i<k;i++)
 s+=a[i];
 l=s;
 for(int i=k;i<n;i++)
 {
 	s=s-a[i-k]+a[i];
 	if(s>l)
 	l=s;
 }
 cout<<l<<endl;
}
	return 0;
}
