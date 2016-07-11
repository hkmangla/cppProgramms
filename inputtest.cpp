#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{
	//ios::sync_with_stdio(false);
	int t,i,j,m;
	scanint(t);
	scanint(i);
	j=0;
	while(t--)
	{
		scanint(m);
		if(m%i==0)
		j++;
	}
	printf("%d\n",j);
	return 0;
}
