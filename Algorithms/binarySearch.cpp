#include<iostream>
using namespace std;

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
int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int value;
	cin>>value;
	if(binarySearch(a,value,0,n-1) != -1)
		cout<<"Yes\n";
	else
		cout<<"No\n";

}