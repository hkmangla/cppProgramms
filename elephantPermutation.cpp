#include<iostream>
using namespace std;

int inversion(int aa[], int min, int mid,int max)
{
	int tmp[50000],i,j,k,m;
	int ans = 0;
	int value1 = mid - min + 1,value2 = max - mid;
	j=min;
	m=mid+1;
	for(i=min;j<=mid&&m<=max;i++)
	{
		if(aa[j]>aa[m])
		{
			tmp[i]=aa[j];
			j++;
			ans += value2;
		}
		else
		{
			tmp[i]=aa[m];
			m++;
			value2 --;
		}
	}
	if(j>mid)
	{
		for(k=m;k<=max;k++)
		{
			tmp[i]=aa[k];
			i++;
		}
	}
	else
	{
		for(k=j;k<=mid;k++)
		{
			tmp[i]=aa[k];
			i++;
		}
	}
	for(k=min;k<=max;k++)
	aa[k]=tmp[k];
	return ans;
}
int inversionNumber(int aa[], int a, int b)
{
	int mid;
	if(a<b)
	{
		mid=(a+b)/2;
		int l = inversionNumber(aa,a,mid);
		int m = inversionNumber(aa,mid+1,b);
		int ans = inversion(aa,a,mid,b);
		// cout<<a<<" "<<mid<<" "<<b<<" "<<ans<<endl;
		return ans + l + m;
	}
	else
		return 0;
}
int main(){
	int t;cin>>t;
	while(t--)
	{
		int n,inversn = 0,local_inversion = 0;cin>>n;
		int a[n+1];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
				local_inversion ++;
		}
		inversn = inversionNumber(a,0,n-1); 
		if(inversn == local_inversion)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		
	}
}