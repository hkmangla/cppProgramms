#include<iostream>
using namespace std;
long long int speed[100000],ttime[100000],position[100000];
int main()
{
	int n,q;
	cin>>n>>q;
	while(q--)
	{
		int quri;
		cin>>quri;
		if(quri==1)
		{
			int t,c,s;
			cin>>t>>c>>s;
			position[c-1]+=(t-ttime[c-1])*speed[c-1];
			ttime[c-1]=t;
			speed[c-1]=s;
		}
		else
		{
			int t;
			long long int max=0;
			cin>>t;
			for(int i=0;i<n;i++)
			{
				position[i]+=(t-ttime[i])*speed[i];
				ttime[i]=t;
				if(max<position[i])
				max=position[i];
			}
			cout<<max<<endl;
		}
	}
	return 0;
}
