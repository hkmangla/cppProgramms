#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("input.txt","w",stdout);
	int t; t = rand(); t = abs(t);
	t = t%20;
	cout<<t<<endl;
	while(t--){

		int l = rand();
	l = abs(l);
	l = l%50;
	l += 2;
	cout<<l<<endl;
	for(int i=0;i<l;i++){
		int x = rand();
		x = abs(x);
		x = x % 50;
		cout<<x<<" ";
	}
	cout<<endl;
	int n = rand();
	n = abs(n);
	n = n%100;
	cout<<n<<endl;
	int nn = rand();
	nn = abs(nn);
	nn = nn%1000;
	cout<<nn<<endl;

	}
	return 0;
}