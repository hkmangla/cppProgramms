#include<iostream>
#include<math.h>
#define PI 3.14159265
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		double r,R; int n;
		cin>>R>>n;
		r = ((R*sin(PI/n))/(1+sin(PI/n)));
		cout<<r<<endl;
	}
}
