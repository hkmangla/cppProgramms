#include "iostream"
#include "string"
using namespace std;
// const : Do not change the value of parameter into function
// &: pass adress of parameter into function and avoid copy of large data that's make it time efficient

string conc(const string& a, const string& b) {return a+b;}
int main(){
	string a,b;
	cin>>a>>b;
	cout<<conc(a,b)<<endl;
}