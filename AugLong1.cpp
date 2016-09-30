#include<bits/stdc++.h>
using namespace std;
bool visited[100000];
int a[100000];
// 1 1 1 1
// 0 0 0 0
// 
int miniSolve(int n, int N){
	int result = 0,start = n;
	int final = start,l=0;
	int check[N];
	// visited[start] = true;
	while(!visited[start]){
		// cout<<start<<endl;
		visited[start] = true;
		start = a[start] + start + 1;
		result += 1;
		start%=N;
	}
	while(final!=start){
		final = final + a[final]  + 1;
		final%=N;
		result --;
	}
	return result;
}
int solve(int n){
	int ans = 0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			ans += miniSolve(i,n);
		}
	}
	for(int i =0;i<n;i++)
		visited[i] = false;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;

	while(t--){
		int n;cin>>n;
		// memset(visited, false, sizeof(visited));
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans = solve(n);
		cout<<ans<<endl;
	}
	return  0;
}