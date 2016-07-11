//#include<iostream>
#include<stdio.h>
//using namespace std;
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
int bin(int a[],int item, int bottom , int top)
{int mid;
	do {
  mid = (bottom + top) / 2;
  if (item < a[mid])
   top = mid - 1;
  else if (item > a[mid])
   bottom = mid + 1;
 } while (item != a[mid] && bottom <= top);
 
 if (item == a[mid]) {
  //printf("Binary search successfull!!\n");
  //printf("\n %d found in position: %d\n", item, mid + 1);
 return mid+1;
 } else {
  //printf("\n  Search failed\n %d not found\n", item);
 return -1;
 }
}
int a[1000001]={0},b[100001];
int main()
{
	int n;
	int t;
	cin>>t;
	while(t--)
	{
	
	scanf("%d",&n);
int x; int k=0;
for(int i=0;i<n;i++){
scanf("%d",&a[i]);
b[i]=a[i];
}
mergesort(a,0,n-1);
for(int i=0;i<n;i++)
{
	int y = bin(a,b[i],1,n);
	
}
cout<<endl;
}
return 0;
}
