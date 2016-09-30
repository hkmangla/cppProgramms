#include "bits/stdc++.h"
using namespace std;

double power(double n, int p=2){
	if(p == 1) return n;
	double x = power(n,p/2);
	if(p%2) return n*x*x;
	else return x*x;
}

struct Point{
	int x;
	int y;
public: 
	Point addPoint(const Point& b){ 
		Point c;
		c.x = x + b.x;
		c.y = y + b.y;
		return c;
	}
};

double doCalculation(const string& userInput){
	string temp = "";
	int value1,value2;
	char optr;
	// cout<<userInput<<endl;
	for(int i = 0; i < (int)userInput.length(); i++ ){
			if(userInput[i] < '0' || userInput[i] > '9')
			{
				optr = userInput[i];
				value1 = strtol(temp.c_str(), NULL, 10);
				temp = "";
			}
			else{
				temp += userInput[i];
				if(i == (int)userInput.length()-1)
					value2 = strtol(temp.c_str(), NULL, 10);	
			} 
	}
	switch(optr){
		case '/': return (double)value1/(double)value2;
		case '*': return value1*value2;
		case '+': return value1+value2;
		case '-': return value1-value2;
		default :{
			cout<<endl<<endl<<"You are using "<<optr<<" which is invalid operator"<<endl<<endl;
			return -1.03;
		} 
	}
	return 1;
}
void lab1(){
	cout<<"Enter value of n and p"<<endl;
	double n; int p;
	cin>>n>>p;
	cout<<"Using power function without p argument i.e. power(n): "<<power(n)<<endl;
	cout<<"Using power function with p argument i.e. power(n,p): "<<power(n,p)<<endl;
}

void lab2(){
	Point P1,P2,P3;
	cout<<"Enter coordinates for P1: ";
	cin>>P1.x>>P1.y;
	cout<<"Enter coordinates for P2: ";
	cin>>P2.x>>P2.y;
	P3 = P1.addPoint(P2);
	cout<<"Coordinates of P1+P2 are: "<<P3.x<<" "<<P3.y<<endl;
}
void lab3(){
	char option;
	do{
		string userInput;
		cout<<"Enter <First Number><operator><Second Number>:  ";
		cin>>userInput;	

		double p = doCalculation(userInput);
		if(p!=-1.03) cout<<endl<<endl<<"Result of "<<userInput<<" is "<<p<<endl<<endl;

		cout<<"Do another (Y/N): "; cin>>option;
	}while(option!='N');
}

int main(int argc, char const *argv[])
{
	lab1();
	return 0;
}