#include<iostream>
using namespace std;
int main()
{
	int j,s,m;
	cin>>j>>s>>m;
	m = m - j;
	j = m/s;
	if(j%2==1)
	cout<<"Unlucky Chef\n";
	else
	cout<<"Lucky Chef\n";
	return 0;
}
