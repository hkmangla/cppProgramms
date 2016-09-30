#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<int> digit;
long long mem[20][2][2422][(1<<9)+4];
long long digitDp(int index, int )
long long solve(long long n){
	if(n==0)
	{
		digit.push_back(n);
	}
	else{
		while(n!=0){
			digit.push_back(n%10);
			n/=10;
		}
	}
	return digitDp(0,1,0,0);
}
int main(){
	long long int l,q,k;
	long long int t;cin>>t;
	while(t--){
	cin>>l>>q>>k;
	// cout<<(1<<9)<<endl;
	long long ans == solve(l) - solve(q-1);
	cout<<ans<<endl;
}
}