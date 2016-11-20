#include "iostream"
using namespace std;
int main(){
	char op;
	do{
		float number1, number2;
		cout<<"Please enter a number: ";
		cin>>number1;
		cout<<"Please enter another number: ";
		cin>>number2;
		cout<<"Please enter a valid operator: ";
		cin>>op;
		switch(op){
			case'+':
				cout<<"The result is: "<<number1+number2<<endl;
				break;
			case'-':
				cout<<"The result is: "<<number1-number2<<endl;
				break;
			case'*':
				cout<<"The result is: "<<number1*number2<<endl;
				break;
			case'/':
				cout<<"The result is: "<<number1/number2<<endl;
				break;
			default: cout<<"You have entered an invalid operator."<<endl;
		}
		cout<<"Do you want to do another calculation?(y or n): ";
		cin>>op;
	}while(op == 'y');
	return 0;
}