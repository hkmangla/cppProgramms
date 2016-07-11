#include<iostream>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--)
	{
		int n,k;cin>>n>>k;
		int a[n+1][n+1],b[2][n+1];
		for(int i=0;i<n;i++)
		{
			b[0][i] = 0;
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
				b[0][i] += a[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			b[1][i] = 0;
			for(int j=0;j<n;j++)
			{
				b[1][i] += a[j][i];
			}
		}
		// for(int i=0;i<2;i++)
		// 	{
		// 		for(int j=0;j<n;j++)
		// 		cout<<b[i][j]<<endl;
		// }
		int ans = 0;
		while(k--){
			int min = 1000000000,x = 2,y;
			for(int i=0;i<2;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(min > b[i][j])
						{
							min = b[i][j];
							x = i;
							y = j;
						}
				}
			}
			for(int j=0;j<n;j++)
			{
				if(x==0)
				b[1][j] += 1; 
				if(x==1)
				b[0][j] += 1;
			}
			ans += min;
			// cout<<ans<<endl;
			b[x][y] += n;
		}
		cout<<ans<<endl;
	}
}