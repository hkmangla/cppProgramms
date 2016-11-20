#include <bits/stdc++.h>             
using namespace std;
class rational{
	int NUMERATOR,DENOMINATOR;
public:
	rational(){
		NUMERATOR = 0; DENOMINATOR = 1;
	}
	rational(int _NUMERATOR, int _DENOMINATOR){
		NUMERATOR = _NUMERATOR;
		DENOMINATOR = _DENOMINATOR;
	}
	void reduce(){
		int hcf = __gcd(NUMERATOR,DENOMINATOR);
		NUMERATOR /= hcf;
		DENOMINATOR /= hcf;
	}
	rational operator+(rational r){
		rational ans;
		ans.DENOMINATOR = DENOMINATOR*r.DENOMINATOR;
		ans.NUMERATOR = NUMERATOR*r.DENOMINATOR + r.NUMERATOR*DENOMINATOR;
		ans.reduce();
		return ans;
	}
	friend istream& operator>>(istream& s, rational &r);
	friend ostream& operator<<(ostream& s,rational r); 
};
istream& operator>>(istream& s, rational &r){
	int a,b; char c; s>>a>>c>>b;
	rational rr(a,b);	r = rr;
	return s; 
}
ostream& operator<<(ostream& s,rational r){
	s<<r.NUMERATOR<<'/'<<r.DENOMINATOR;
	return s;		
}
int main(int argc, char const *argv[]){
	rational r1,r2,r3;
	cout<<"Enter First rational number: "; cin>>r1;
	cout<<"Enter second rational number: "; cin>>r2;
	r3 = r1+r2;
	cout<<"Sum of "<<r1<<" and "<<r2<<" is "<<r3<<endl<<endl;
	return 0;
}