#include<iostream>
#include<string.h>
#include<malloc.h>
using namespace std;
int l[1000][1000];
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
char **lcs(char* x, char* y,int n,int m)
{
	int k = llcs(x,y,n,m);
	cout<<k<<" ";
	char **c = (char **)malloc(sizeof(char*)*n);
	c[0] = (char *)malloc(sizeof(char)*(k+1));
	c[0][k] ='\0';
	k=1;
//	cout<<"c[0]="<<c[0]<<endl;
	int i = n,j = m;
	while(i > 0  && j > 0)
	{
		if(x[i-1]==y[j-1])
		{
			c[0][k-1]=x[i-1];
			i--;j--;k++;
		}
		else if(l[i-1][j]>l[i][j-1])
		i--;
		else if(l[i-1][j]==l[i][j-1])
		{
			
		}
		else
		j--;
    }
    return c;
}
int main()
{
	 char a[100],b[100];int t;
	 cin>>t;
	 while(t--)
	 {
	 	init();
    	cin>>a; cin>>b;
    	int m = strlen(a);
    	int n = strlen(b);
	    char **c = (char **)malloc(sizeof(char*)*n);
		c[0] = (char *)malloc(sizeof(char)*(llcs(a,b,n,m)+1));
		c=lcs(a,b,m,n);
		strrev(c[0]);
	    cout<<c[0]<<"\n";
     }
}
