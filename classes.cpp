#include<iostream>
using namespace std;
class hemant{
	//public:
	int x,y;
	public:
	hemant(int ,int);
	int mul();
	
};
hemant::hemant(int c,int d):x(c)
{
    y=d;
}
int hemant::mul()
{
	return x*y;
}
int main()
{
	hemant a(6,7);
	//a.x=6;
	cout<<a.mul();
}
