#include<bits/stdc++.h>
using namespace std;
bool check(float a,float b,float c, float d){
	return (a/b == c/d) || (b/a == c/d) || (a/b == d/c) || (b/a == d/c);
}
int gcd(int a, int b)
{
	if(a==0) return b;
	else return gcd(b%a,a);
}
int main(){
	float a,b,c,d;
	cin>>a>>b>>c>>d;
	int aa[4];
	aa[0] = a;
	aa[1] = b;
	aa[2] = c;
	aa[3] = d;
	sort(aa,aa+4);
	bool result = false;
	b = gcd(aa[0],aa[1]);
	aa[0] /= b;
	aa[1] /= b;
	// cout<<aa[2]<<endl;
	a = gcd(aa[2],aa[3]);
	aa[2] /= a;
	aa[3] /= a;
	// for(int i=0;i<4;i++)
		// cout<<aa[i]<<endl;
	if(aa[1] == aa[3] && aa[2] == aa[0])
		result = true;
	// result = result || check(a,b,c,d);
	// result = result || check(a,c,b,d);
	// result = result || check(a,d,b,d);
	// result = result || check(c,b,a,d);
	// // result = result || check(a,b,c,d);
	if(result)
		cout<<"Possible\n";
	else
		cout<<"Impossible\n";
	
}