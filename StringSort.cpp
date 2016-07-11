#include<iostream>
#include<string.h>
#include<malloc.h>
#define MAX 10
using namespace std;
void Merge(char * arr[],int low ,int mid ,int high)
{
	int nL = mid-low+1; int nR = high-mid;
	char **L =(char **)malloc(sizeof(char*)*nL);
	char **R =(char **)malloc(sizeof(char*)*nR);
	for(int i = 0;i < nL;i++)
	{
		L[i]= (char *)malloc(sizeof(arr[low+i]));
		strcpy(L[i],arr[low+i]);
	}
	for(int i = 0;i < nR;i++)
	{
		R[i]= (char *)malloc(sizeof(arr[mid+1+i]));
		strcpy(R[i],arr[mid+1+i]);
	}
	int j=0,i=0,k=low;
	while(i<nL&&j<nR)
	{
		if(strcmp(L[i],R[j])<0)
		strcpy(arr[k++],L[i++]);
		else
		strcpy(arr[k++],R[j++]);
	}
	while(i<nL)
	strcpy(arr[k++],L[i++]);
	while(j<nR)
	strcpy(arr[k++],R[j++]);
}
void MergeSort(char* arr[],int low,int high)
{
	if(low<high)
	{
		int mid= (low+high)/2;
		MergeSort(arr,low,mid);
		MergeSort(arr,mid+1,high);
		Merge(arr,low,mid,high);
	}
}
int main()
{
	int n;
	cin>>n;
	char **a= (char **)malloc(sizeof(char*)*n);
	for(int i =0 ; i< n; i++)
	{
	a[i]=(char *)malloc(sizeof(char)*MAX);	
	cin>>a[i];
}
	MergeSort(a,0,n-1);
	for(int i =0; i < n;i ++)
	{
		cout<<a[i]<<endl;
	}
}
