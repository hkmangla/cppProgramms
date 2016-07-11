#include<iostream>
// #include<bits/stdc++>
using namespace std;

void insertionSort(int a[], int beg, int end){
	if(beg>end)
		return ;
	int i;
	insertionSort(a, beg, end-1);
	int value = a[end];
	for(i=end-1; i>=beg;i--)
	{
		if(a[i] > value)
			a[i+1] = a[i];
		else 
			break;
	}
	a[i+1] = value;
}

int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	insertionSort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;

}