#include<bits/stdc++.h>
using namespace std;
stack<int> food;
int main(){
	int t;cin>>t;
	while(t--){
		int q;cin>>q;
		if(q==1)
		{
			if(food.empty())
				cout<<"No Food\n";
			else
			{
				cout<<food.top()<<endl;
				food.pop();
			}
		}
		else{
			int price;cin>>price;
			food.push(price);
		}
	}
}