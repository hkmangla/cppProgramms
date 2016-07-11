#include<iostream>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--)
	{
	int n;cin>>n;
	int a[n];
	int l = 0; int sum = 0;
	for(int i = 0;i < n;i++)
		cin>>a[i];
	for(int i = 0;i < n;i++){
	 sum += a[i];
	 if(a[i] <= 2)
	 {
	 	l = 0;
		break;	 
	 }
	 if(a[i] == 5)
	 	l = 1;
	}
	// cout<<l<<endl;
	if(l == 0)
		cout<<"No\n";
	else{
		if(sum >= 4*n)
		cout<<"Yes\n";
		else
		cout<<"No\n";
	
	}	
	}
}