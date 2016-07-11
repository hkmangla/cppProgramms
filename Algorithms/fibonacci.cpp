#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float goldenRatio = (1 + sqrt(5))/2;
	int n;cin>>n;
	while(n--)
	{
		int i; cin>>i;
		int fib = (pow(goldenRatio,i)/sqrt(5) + 0.5);
		cout<<fib<<endl;
	}
}