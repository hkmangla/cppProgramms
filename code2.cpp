#include "bits/stdc++.h"
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		long long x;
		if(n==1)
			{
				cin>>x;		cout<<x<<endl;
				continue;
			}
		priority_queue < long long , vector < long long > , greater < long long > > pq;
		for(int i= 0; i<n; i++)
		{
			cin>>x;	pq.push(x);
		}
		long long ans = 0;
		while(pq.size() != 1)
		{
			long long a = pq.top();pq.pop();
			long long b = pq.top();pq.pop();
			long long tmp = a+b;
			ans += tmp;
			pq.push(tmp);
		}
		cout << ans << endl;
	}
}