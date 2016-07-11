#include<bits/stdc++.h>
using namespace std;
// stack<int> food;
void merge(int aa[], int min, int mid,int max)
{
	int tmp[50000],i,j,k,m;
	j=min;
	m=mid+1;
	for(i=min;j<=mid&&m<=max;i++)
	{
		if(aa[j]<=aa[m])
		{
			tmp[i]=aa[j];
			j++;
		}
		else
		{
			tmp[i]=aa[m];
			m++;
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
}
void mergeSort(int aa[], int a, int b)
{
	int mid;
	if(a<b)
	{
		mid=(a+b)/2;
		mergeSort(aa,a,mid);
		mergeSort(aa,mid+1,b);
		merge(aa,a,mid,b);
	}
}

bool check(int a[],int n,int value, int k){
	int l=0,i,sum = 0;
	for(i=0;i<n;i++){
		if(sum < a[i])
		{
		sum = a[i] + 2*value;
			k--;
		}
		// l++;
		if(k==0)
			break;
	}
	if(sum >= a[n-1])
		return true;
	else
		return false;
}
int main(){
	int n,k; cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergeSort(a,0,n-1);
	int mid,end = 10000000,beg = 0;
	while(1){
		mid = (end + beg)/2;
		// cout<<check(a,n,1,k)<<endl;
		// cout<<check(a,n,2,k)<<endl;
		// cout<<check(a,n,3,k)<<endl;
		// break;
		if(check(a,n,mid,k) && (check(a,n,mid-1,k)==false))
			break;
		else if(check(a,n,mid,k) && check(a,n,mid-1,k))
			end = mid - 1;
		else
			beg = mid + 1;
	}
	cout<<mid<<endl;
}