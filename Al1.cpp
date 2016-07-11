#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
	int n,f=1,t;
	FILE* fp = fopen("uo.txt","w");
	cin>>t;
	while(t--)
	{
		char a[100001],b[100001];
		cin>>a>>b;
		long long int la=0,lb=0;
		for(int i=0;a[i]!='\0';i++)
		{
			if(la == lb)
			{
				if(a[i]=='?'&&b[i]!='?')
					a[i]=b[i];
				if(b[i]=='?'&&a[i]!='?')
					b[i]=a[i];

				if(b[i]=='?'&&a[i]=='?')
					{
					b[i]='0';
					a[i]='0';
					}

			}
			if(la > lb)
			{
				if(a[i]=='?'&&b[i]!='?')
					a[i]='0';
				if(b[i]=='?'&&a[i]!='?')
					b[i]='9';

				if(b[i]=='?'&&a[i]=='?')
					{
					b[i]='9';
					a[i]='0';
					}

			}
			if(la < lb)
			{
				if(a[i]=='?'&&b[i]!='?')
					a[i]='9';
				if(b[i]=='?'&&a[i]!='?')
					b[i]='0';

				if(b[i]=='?'&&a[i]=='?')
					{
					b[i]='0';
					a[i]='9';
					}

			}
			la = ((la)*pow(10,i)) + a[i]-48;
			lb =((lb)*pow(10,i)) + b[i]-48;
			// cout<<la<<" "<<lb<<endl;
		}
		cout<<a<<" "<<b<<endl;
        
        fprintf(fp, "Case #%d: %s %s\n",f,a,b );
        f++;
	}
	return 0;
}






















