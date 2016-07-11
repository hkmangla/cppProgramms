#include<iostream>
using namespace std;

bool isWinning(int pos){
	if(pos<=5)
		return true;
	int a = 2;
	for(int i=0;i<5;i++)
	{
		if(!isWinning(pos/a))
			return true;
		a++;
	}
}
int main()
{
	int n;cin>>n;
	while(n--){
		int t,l=0;cin>>t;
		for(int i=0;i<t;i++)
		{
			if(isWinning(i+1) && l==0)
			{
			cout<<i+1<<" "<<isWinning(i+1)<<endl;
			l= 1;
			}
			if(!isWinning(i+1) && l==1)
			{
			cout<<i+1<<" "<<isWinning(i+1)<<endl;
			l= 0;
			}

		}
	}
}