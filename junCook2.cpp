#include<iostream>
using namespace std;

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

int main(){
	int t;cin>>t;
	while(t--)
	{	
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergeSort(a,0,n-1);
	int x=0,side1 = -1,side2 = -1;
	for(int i=n-1;i>0;i--){
		if(a[i] == a[i-1])
		{

			side1 = a[i];
			x = i-1;
			break;

		}
	}
	for(int i = x-1;i>0;i--){
		if(a[i] == a[i-1])
		{

			side2 = a[i];
			break;
			x = i-1;
		}
	}
		if(side1 != -1 && side2 != -1)
			cout<<side1*side2<<endl;
		else
			cout<<"-1\n";

	}
}