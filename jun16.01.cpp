#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int dp(int a[],int n,int i)
{
	if(i < 0)
		return 0;
	else{
		int l = dp(a,n,i-1)+a[i];
		if(l < 0)
			l = -l;
		int k = dp(a,n,i-1)-a[i];
		if(k < 0)
			k = -k;
		return min(l,k);
	}
}
int main(){
	int t;cin>>t;
	while(t--){
		int n,a[1500];
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		cout<<dp(a,n,n-1)<<endl;
	}
}














