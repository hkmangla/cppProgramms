#include<iostream>
using namespace std;
int ab[500001]; long long int ac[500001];
void merge(int aa[], int min, int mid,int max)
{
int tmp[500001],i,j,k,m;
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
void mergesort(int aa[], int a, int b)
{
int mid;
if(a<b)
{
mid=(a+b)/2;
mergesort(aa,a,mid);
mergesort(aa,mid+1,b);
merge(aa,a,mid,b);
}
}
int main()
{
	long long int n;
	cin>>n;
	long long int ll=0;
	for(int i=0;i<n;i++)
	cin>>ab[i];
	mergesort(ab,0,n-1);
	for(int i=0;i<n;i++)
	{
		ac[i]=ab[i]*(n-i);
		if(ll<ac[i])
		ll = ac[i];
	}
	cout<<ll<<endl;
	return 0;
}
