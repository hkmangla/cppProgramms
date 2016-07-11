#include "bits/stdc++.h"
using namespace std;
int dp[501][501];
void mem(){
	for(int i=0;i<501;i++)
		for(int j=0;j<501;j++)
			dp[i][j]=-1;
}


int isSubsetPossible(int a[],int Sum,int index)
{
	if(Sum == 0) return 1;
	if(index < 0) return 0;
	if(dp[Sum][index] == -1)
	{
		if(Sum >= a[index])
			dp[Sum][index] = isSubsetPossible(a,Sum-a[index],index-1) or isSubsetPossible(a,Sum,index-1);
		else
			dp[Sum][index] = isSubsetPossible(a,Sum,index-1);
	}
	return dp[Sum][index];
}

int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--)
	{
		int n,l=1,k=0,a[501],sum1= 0,sum2 = 0,b[501];
		char x;
		cin >> n ;
		cin>>a[0];
		sum1+=a[0];
		for (int i = 1; i <= n; i++)
		{
			if(i%2 == 0)
			{
			cin>>x;
			cin >> a[l];
			sum1+=a[l];
			l++;
			}	
			if(i%2 == 1)
			{
				cin>>x;
			cin >> b[k];
			sum2+=b[k];
			k++;
			}	
		}
		// for(int i=0;i<k;i++)
		// 	cout<<b[i]<<endl;
		// for(int i=0;i<l;i++)
		// 	cout<<a[i]<<endl;
        int summ1 = sum1,summ2 = sum2;
		sum1 = sum1/2;
		int ans1,y=sum1;x=sum1;
		while(1){
		mem();
		if(isSubsetPossible(a,x,l-1) == 1)
		{
			ans1 = x;
			break;
		}
		mem();
		if(isSubsetPossible(a,y,l-1) == 1)
		{
			ans1 = y;
			break;
		}
		x +=1; y-=1;
		}
		sum2/=2;
		y=sum2;x=sum2;
		int ans2;
		while(1){
			
		mem();
		if(isSubsetPossible(b,x,k-1) == 1)
		{
			ans2 = x;
			break;
		}
		mem();
		if(isSubsetPossible(b,y,k-1) == 1)
		{
			ans2 = y;
			break;
		}
		x +=1; y-=1;
		}
		ans1 = summ1 - ans1*2;
		ans2 = summ2 - ans2*2;
		ans1 = abs(ans1);
		ans2 = abs(ans2);
		cout<<ans1+ans2<<endl;
	}
	return 0;
}

















