#include<iostream>
using namespace std;
int b[1000001];
void inversion(int aa[], int min, int mid,int max)
{
	int tmp[1000001],i,j,k,m;
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
			// cout<<aa[j-1]<<endl;
			b[aa[j-1]] += value2;
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
	// return ans;
}
void inversionNumber(int aa[], int a, int b)
{
	int mid;
	if(a<b)
	{
		mid=(a+b)/2;
		inversionNumber(aa,a,mid);
		inversionNumber(aa,mid+1,b);
		inversion(aa,a,mid,b);
		// cout<<a<<" "<<mid<<" "<<b<<" "<<ans<<endl;
		// return ans + l + m;
	}
	// else
		// return 0;
}
int main(){
	int t;cin>>t;while(t--){
	int n; cin>>n;
	int a[n],d[n];
	for(int i=0;i<n;i++)
		{
			cin>>a[i];
			d[i] = a[i];
		}
	inversionNumber(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<b[d[i]]<<" ";
		b[d[i]] = 0;
	}
	cout<<endl;
	}
}