#include<bits/stdc++.h>
using namespace std;
long long n,sum;
long long mem[65][3027];
vector<int> digit;
void initial(){
	for(long long i=0;i<65;i++){
		for(long long j=0;j<3027;j++){
				mem[i][j] = -1;
		}
	}
}
long long count_dp(long long i,long long mask)
{
	long long res = mem[i][mask];
		// cout<<"Yes";
	if(res != -1)
		return res;
	res = 0;
	if(i == digit.size()){
		return 1;
	}
		for(int d=0;d<=9;d++){
			int newmask = mask;
			// cout<<newmask<<endl;
			if((mask >> d+1) == 0){
				newmask = (mask | (1 << d));
				res += count_dp(i+1,newmask);
			}
		}
	mem[i][mask] = res;
	return res;
}
long long solve(long long n){
	if(n==0) return 0;
	digit.resize(n);
	// initial();
	memset(mem, -1, sizeof(mem));
	return count_dp(0,0);
}
int main(int argc, char const *argv[])
{
	int t;cin>>t;
	while(t--)
	{	
	long long l,r;
	cin>>r>>l;
	long long ans = solve(l);
	cout<<r<<" "<<ans<<endl;
	}
	return 0;
}