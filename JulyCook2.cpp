#include<bits/stdc++.h>
using namespace std;
bool check(float a,float b,float c, float d){
	return (a/b == c/d) || (b/a == c/d) || (a/b == d/c) || (b/a == d/c);
}
int digit(int n){
	int ans = 0;
	while(n!=0){
		ans += n%10;
		n/=10;
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	int c = 0;
	for(int i=n-1000;i<n;i++){
		if(i<0)
			continue;
		int ans = i + digit(i) + digit(digit(i));
		if(ans == n)
			c++;
	}
	cout<<c<<endl;
}