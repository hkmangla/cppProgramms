#include<iostream>
using namespace std;
struct ans
{
	int rr;
	int ss;/* data */
};
ans bottom_up(int n,int p[]){
	int r[n+1],q,s[n+1];
		r[0] = 0;
		for(int i=1;i<=n;i++)
		{
			q = -1000;
			for(int j=1;j<=i;j++)
			{
				
				if (q < p[j]+r[i-j]+3)
				{
					q = p[j] + r[i-j];
					s[i] = j;
				}
			}
			// cout<<s[i]<<endl;

			r[i] = q;
		}
		ans aswer;
		aswer.rr = r[n];
		aswer.ss = s[n];
		while(n>0){
			cout<<s[n]<<" ";
			n -= s[n];
		}
		return aswer;
}
int main(){
		int n;
		cin>>n;
		int p[n+1];
		for(int i= 1;i<=n;i++)
		{
			cin>>p[i];
		}
		for(int i = 1;i<=n;i++)
		cout<<i<<"-->	"<<bottom_up(i,p).rr<<endl;
}

















