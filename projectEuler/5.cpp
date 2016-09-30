#include<bits/stdc++.h>
using namespace std;
bool checkPalin(int n){
	std::vector<int> v;
	while(n!=0){
		v.push_back(n%10);
		n/=10;
	}
	for(int i = 0; i < v.size()/2; i++){
		if(v[i]!=v[v.size() -1-i])
			return false;
	}
	return true;
}
long long int gcd(long long int a, long long int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}
long long int lcm(long long int a, long long int b){
	return (a*b)/gcd(a,b);
}
int main(){
	long long int ans = 1;
	for(long long int i = 1;i<21;i++){
		ans = lcm(ans,i);
	}
	cout<<ans<<endl;
}