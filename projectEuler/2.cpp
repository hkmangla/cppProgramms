#include<iostream>
using namespace std;
int main(){
	long long int ans=2,value1 = 1,value2 = 2;
	while(value1 <= 4000000){
		int temp = value2;
		value2+= value1;
		value1 = temp;
		if(value2%2==0)
			ans+= value2;
	}
	cout<<ans<<endl;
}