#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int prime[100000];
void addprime()
{
	int x,i,j,k=3;
	prime[0]=2;
prime[1]=3;
prime[2]=5;
	for(i=6;i<=100000;i++)
	{
		x=0;
		if(i%6==1||i%6==5)
		{
		for(j=2;prime[j]<sqrt(i)+1;j++)
		{
			if(i%prime[j]==0)
			{
				x=1;
				break;
			}
		}
		if(x==0)
		{
			prime[k]=i;
			k++;
		}
	}
	}
}
bool checkprime(int n)
{
	if(n==1||n==0)
	return false;
	for(int i=2;prime[i]<sqrt(n)+1;i++)
	{
		
		if(n%prime[i] == 0)
		return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	int t,a,b;
	addprime();

	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		for(int i = a;i<=b;i++)
		{
			if(i==2)
			cout<<"2\n";
			if(i==3)
			cout<<"3\n";
			if(i%6==5||i%6==1)
			{
			if(checkprime(i))
			{
			   printf("%d\n",i);
		    }
		}
		}
		cout<<endl;
	}
	return 0;
}
