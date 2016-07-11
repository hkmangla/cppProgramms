#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[27]; int t;
	cin>>a;
	t = strlen(a);
	while(t>3)
	{
		int l=0;
		for(int i=0;i<t;i++)
		{
			int n=a[i]%27;
//			if(n>27)
//			{
//				n%=28;
//				n+=19;
//				}	
//			if(n>26)
//			{
//				n%=27;
//				n+=19;
//				}	
//				if(n>23)
//				l++;
			cout<<n<<" ";	
		}
		cout<<"\n\n"<<l<<"\n\n";
		cin>>a;
		t = strlen(a);
	}
}
