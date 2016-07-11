#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int ans=0,n,m;
		cin>>n>>m;
		char a[n+1][m+1];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<m;i++)
			{
				int count = 0;
				for(int j=0;j<n;j++)
				{
					if(a[j][i]=='1')
						count ++;
				}
				ans += (count*(count-1)/2);
			}
		cout<<ans<<endl;
	}
}