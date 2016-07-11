#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n,i,l=0; char a[100000];
	cin>>a>>n;
	l=n;
	for(int i=strlen(a)-1;i>=0;i-- )
	{
		int k = a[i]-48;
		cout<<k<<" ";
		k+=l;
		l=k/10;
		k=k%10;
		a[i]=k+48;
		cout<<a[i]<<endl;
	}
	if(l!=0)
	cout<<l;
	for(int i=0;i<strlen(a);i++)
	cout<<a[i];
	cin>>l;
}
