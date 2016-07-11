#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int ans = n - 1;
		m = m-1;
		ans = ans+(m*(2*n-1));
		cout<<ans<<endl;
	}
}