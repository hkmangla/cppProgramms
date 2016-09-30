#include<bits/stdc++.h>
using namespace std;
long long n,sum;
long long mem[12][100][2];
vector<int> digit;
void initial(){
	for(long long i=0;i<12;i++){
		for(long long j=0;j<100;j++){
			for(long long k=0;k<2;k++)
				mem[i][j][k]=-1;
		}
	}
}
long long count_dp(long long i,long long sum_so_far, bool lo)
{
	if(i==digit.size()) return sum_so_far;
	long long result = 0;
	for (long long d = 0; d <= (lo?9:digit[i]); d++)
	{
		long long l = (lo || d<digit[i])?1:0;
		if(mem[i+1][sum_so_far+d][lo || d<digit[i]] == -1)
				mem[i+1][sum_so_far+d][l] = count_dp(i+1,sum_so_far+d,lo || d < digit[i]);
		result+=mem[i+1][sum_so_far+d][l];
	}
	return result;
}
long long solve(long long n){
	if(n==0) return 0;
	digit.clear();
	while(n!=0){
		digit.push_back(n%10);
		n/=10;
	}
	// cout<<"Thd";
	reverse(digit.begin(), digit.end());
	initial();
	return count_dp(0,0,false);
}
int main(int argc, char const *argv[])
{
	long long l,r;
	cin>>r>>l;
	while(l!=-1&&r!=-1){	
	long long ans = solve(l) - solve(r-1);
	cout<<ans<<endl;
	cin>>r>>l;
	}
	return 0;
}