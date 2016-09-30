#include<bits/stdc++.h>
using namespace std;
long long int n,sum;
long long int mem[22][(1<<9)+4][(1<<9)+4][2];
vector<int> digit;
long long int count_dp(long long int i,long long int mask,long long int check, bool lo)
{
	long long int result = mem[i][mask][check][lo];
	// cout<<result<<endl;
	if(result != -1)
		return result;
	if(i == digit.size()){
			int flag = 1;
				for(int d=0;d<=9;d++){
					if( (check & (1 << d))){
					// cout<<"Enter "<<d<<endl;
					if(d%2 == 1){
						if((mask & (1 << d)) != 0){
							flag = 0;
							break;
						}
					}
					if(d%2 == 0){
						// cout<<"Enter Again "<<(mask & (1<<d))<<endl;
						if((mask & (1 << d)) == 0){
							flag = 0;
							break;
						}
					}
				}
			}
			if(flag)
				return 1;
			return 0;
	} 
	result = 0;
	for (long long int d = 0; d <= (lo?9:digit[i]); d++)
	{
		long long int newlo = (lo || d < digit[i])?1:0;
		long long int newmask;
		// cout<<"mask "<<d<<": "<<newmask<<endl;
		long long int  newcheck;
		if(d == 0 && check == 0){
				newcheck = check;
				newmask = mask;
		}
		if(d!=0 || check!=0)
		{
			newcheck = ( check | (1 << d));
			newmask = ( mask ^ (1 << d));
		}
		// cout<<"check "<<d<<": "<<newcheck<<endl;
		// cout<<"bresult "<<d<<": "<<mem[i+1][newmask][newcheck][newlo]<<endl;
		mem[i+1][newmask][newcheck][newlo] =  count_dp(i+1, newmask,newcheck, newlo);
		// cout<<"Aresult "<<d<<": "<<mem[i+1][newmask][newcheck][newlo]<<endl;
		result += mem[i+1][newmask][newcheck][newlo];
	}
	mem[i][mask][check][lo] = result;
	return result;
}
long long int solve(char n[]){
	// if(n==0) return 1;
	digit.clear();
	for(int i=0;i<strlen(n);i++){
		// cout<<"digit: "<<n%10<<endl;
		digit.push_back(n[i]-48);
		// n/=10;
		// cout<<digit[i]<<endl;
	}
	// reverse(digit.begin(), digit.end());
	memset(mem, -1, sizeof(mem));
	return count_dp(0,0,0,false);
}
int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while(t--){	
	// long long int l,r;
		char l[22],r[22];
	cin>>r>>l;
	// cout<<r<<" "<<l<<endl;
	// cout<<solve(l)<<endl;
	long long int ans = solve(l) - solve(r-1);
	cout<<ans<<endl;
	}
	return 0;
}