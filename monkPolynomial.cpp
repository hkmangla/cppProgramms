#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		long long int a,b,c,k;
		cin>>a>>b>>c>>k;
		k = k-c;
		if(k<=0)
			cout<<"0\n";
		else{
			int flr = floor(sqrt(k/a));
			flr -= 5;
			if(flr < 0)
				flr = 0;
			while((a*flr*flr + b*flr) < k)
				flr ++;
			cout<<flr<<endl;
		}
	}
}