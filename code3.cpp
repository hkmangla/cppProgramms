#include "bits/stdc++.h"
using namespace std;
int a[20];
int n;
int main(int argc, char const *argv[])
{
// 	freopen("win.in","r",stdin);
// 	freopen("win.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int value = 0, count = 0;
	for(int i=0;i<n;i++){
		value += a[i];
		if(value <= 18000) count ++;
	}
	cout<<count<<endl;
	return 0;
}