#include "bits/stdc++.h"
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector <int> input;
		for(int i=0;i<n;i++){
			int x; cin>>x;
			input.push_back(x);
		}
		int ans = 0, answer = 1000000000;
		sort(input.begin(), input.end());
		while(1){
			int flag = 0;
		for(int i = 1; i < n; i++){
			while(abs((input[i]/2)-input[0]-1) < (input[i] - input[0])){
				input[i]/=2;
				ans ++;
				flag = 1;
			}
		}
		int newAns = ans;
		sort(input.begin(), input.end());
		for(int i=0;i<n;i++)
		{
			newAns += input[n-1] - input[i];
		}
		answer = min(answer, newAns);
		if(flag==0) break;
		}
		// cout<<ans<<endl;
		for(int i=0;i<n;i++)
		{
			ans += input[n-1] - input[i];
		}
		ans = min(answer, ans);
		cout<<ans<<endl;
	}

	return 0;
}