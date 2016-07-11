#include<iostream>
#define MAX 200001
using namespace std;
 int temp[200001],b[200001];

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l;

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k,a[100001],c[100001],d[100001];
		cin>>n>>m>>k;
		for(int i=0;i<n;i++)
		{
			cin>>c[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>d[i];
		}
		for(int i=0;i<n;i++)
		{
			a[i]=c[i]-d[i];
		}
		for(int i=0;i<m+k;i++)
		cin>>b[i];
		partition(a,0,n-1);
		partition(b,0,m+k-1);
		int l=m+k-1;
		int ll=n-1;
		for(int i=l;i>=0;i--)
		{
			if(b[i]<=a[ll])
			{
				a[ll]-=b[i];
				ll--;
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
