#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		long long int n,j,ans; char a[255];
		cin>>n;
		j = n-1;
		n = -1;
		a[0] = 48;
		while(j){
			n++;
			ans = (j%5)*2;
			j = j/5;
			a[n] = ans+48;
		}
		// n = strlen(a);
		// cout<<n<<endl;
		if(n==-1)
			n = 0;
		for(int i=n;i>=0;i--){
		cout<<a[i];
			a[i] = 0;
		}
		cout<<endl;

	}
	return 0;
}