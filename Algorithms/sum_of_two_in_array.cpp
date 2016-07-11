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

int binarySearch(int a[],int item, int bottom , int top)
{
	int mid;
	do {
 		mid = (bottom + top) / 2;
  		if (item < a[mid])
   			top = mid - 1;
  		else if (item > a[mid])
  			bottom = mid + 1;
 		} while (item != a[mid] && bottom <= top);
 
 		if (item == a[mid]) {
 			return mid+1;
 		} 
 		else 
 			return -1;
 }
bool isSumOf2(int a[],int beg, int end, int value){
	mergeSort(a,beg,end);
	for(int i=beg;i<=end;i++)
	{
		int item = value - a[i];
		int searchPos = binarySearch(a,item,i+1,end);
		if(searchPos != -1)
			return true;
	}
	return false;
}
int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int query; cin>>query;
	while(query --){
		int sum; cin>>sum;
		if(isSumOf2(a,0,n-1,sum))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}

}