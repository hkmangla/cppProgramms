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
int main(){
	int ans = 0;
	for(int i= 100;i<1000;i++){
		for (int j = 100; j < 1000; j++)
		{
			int h = i*j;
			if(checkPalin(h)){
				ans = max(ans,h);
			}
		}
	}
	cout<<ans<<endl;
}