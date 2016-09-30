#include <iostream>
using namespace std;

double power(double n, int p=2){
	if(p == 1) return n;
	double x = power(n,p/2);
	if(p%2) return n*x*x;
	else return x*x;
}
int main(int argc, char const *argv[])
{
	cout<<"Enter value of n and p"<<endl;
	double n; int p;
	cin>>n>>p;
	cout<<"Using power function without p argument i.e. power(n): "<<power(n)<<endl;
	cout<<"Using power function with p argument i.e. power(n,p): "<<power(n,p)<<endl;
	return 0;
}