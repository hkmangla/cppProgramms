#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int l[2001][2001];
int max(int a, int b)
{
	return (a > b) ? a : b;
}
void init()
{
	for(int i= 0;i<1000;i++)
	{
		for(int j =0 ; j< 100;j++)
		l[i][j]=0;
	}
}
int llcs(char *x, char *y,int n, int m)
{
	int i,j;
	for(i= 0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
			l[i][j]=0;
			else if(x[i-1]==y[j-1])
			{
			    l[i][j]=l[i-1][j-1]+1;
			}
			else
			{
			   l[i][j]= max(l[i-1][j],l[i][j-1]);
	     	}
    	}
	}
    return l[n][m];
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		char a[2002],b[2002];
		cin>>a>>b;
		int l=llcs(a,b,strlen(a),strlen(b));
		//cout<<l;
		int n=strlen(a),m=strlen(b);
		if(n>=m)
		cout<<n-m+n-l<<endl;
		if(n<m)
		cout<<m-n+m-l<<endl;
	}
}
