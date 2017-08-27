#include "bits/stdc++.h"
using namespace std;
long long ft[1001];
int query(int i){
	int sum = 0;
	for(;i;i-=(i&(-i))) sum += ft[i];
	return sum;
}
int n;
void up(int k,int v){
	for(;k<=n;k+=(k&(-k))) ft[k]+=v;
}
int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5,6};
	n = 6;
	for(int i=0;i<n;i++) up(i+1,a[i]);
	int q; cin>>q;
	while(q--){
		int x,y; cin>>x>>y;
		cout<<query(y)-query(x-1)<<endl;
	}
	return 0;
}