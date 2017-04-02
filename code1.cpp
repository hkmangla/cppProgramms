#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("testgen.in","r",stdin);
	freopen("testgen.out","w",stdout);
	int n; cin>>n;
	int prime[] = {2,3,5,7,11,13,17,19};
	int primeCount = 8;
	int best_count = 0, best_value = 1;
	for(int i=1;i<=n;i++){
		int count = 1;
		int value = i;
		for(int j=0;j<primeCount && prime[j] <= value; j++){
			int c_count = 0;
			while(value%prime[j] == 0){
				c_count ++;
				value /=prime[j];
			}
			count *= (c_count + 1);
		}
		if(best_count < count){
			best_count = count;
			best_value = i;
		}
	}
	cout << n - best_value + 1<<endl;
	return 0;
}