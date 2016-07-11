#include<iostream>
#include<set>
using namespace std;
int main(){
	long long int l,q,k;
	long long int t;cin>>t;
	while(t--){
	cin>>l>>q>>k;
	int ans = 0;
	for(int i=l;i<=q;i = i + 1)
	{
		set<int> s;
		for(int j = 1;j<10;j++)
		{
			if(i%j == 0)
				s.insert(j);
		}
		int n = i;
		int count = 0;
		set<int> digit;
		while(n){
			digit.insert(n%10);			
			n/=10;
		}
		for(set<int>::iterator it = digit.begin(); it!=digit.end();++it){
			// cout<<*it<<endl;
			if(*it == 2){
		if(s.find(*it) != s.end())
				count++;
			}
		}
		// if(count == 2)
		// cout<<i<<" "<<count<<endl;
		if(count == 1){
					// cout<<i<<" "<<count<<endl;
			ans ++;
		}
		
	}
	cout<<ans<<endl;
}
}