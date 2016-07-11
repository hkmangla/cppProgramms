#include<iostream>
using namespace std;
int main(){
	int a,n,k;
	cin>>a>>n>>k;
	while(a && k){
		cout<<a%(n+1)<<" ";
		a/=(n+1);
		k--;
	}
	while(k--)
		cout<<"0 ";
		cout<<"\n";
}