#include<iostream>
using namespace std;
template <class hemant>
hemant sum(hemant a, hemant b)
{
	return a+b;
}
template <typename hemant,int n>
hemant r(hemant d)
{return d*n;
}
namespace ff{
	double x,y,f;
}
int main()
{
	using namespace ff;
	//double x,y,f;
	double s,d,g;
	x=1;y=3; f=r<double,4>(7.8);
	s=2.7777;d=3.5;g=sum(s,d);
	cout<<f<<" "<<g; 
}
