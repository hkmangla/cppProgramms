#include <iostream>			  
using namespace std;	
class tollbooth{
private:
	int null,pcar,wpcar; float tax;
public:
	tollbooth(){
		tax = null = pcar = wpcar = 0;
	}
	void paycar(int a){
		pcar += a;
		for(null;null<=pcar;null++) tax=a*0.50;
	}
	void withoutpay(int b){
		wpcar += b;
	}
	void showData(){
		cout<<"Total number of paycars are: "<<pcar<<endl;
		cout<<"Total tax is: "<<tax<<endl;
		cout<<"Total no. of not payed car are; "<<wpcar<<endl;
	}
};
int main(int argc, char const *argv[]){
	tollbooth tb;
	char press,input;
	int a,b;
	do{
		cout<<"Press 1 for car pay tax"<<endl;
		cout<<"Press 2 for car not pay tax"<<endl;
		cin>>press;
		switch(press){
			case'1': {
				cout<<"Enter number of cars pay tax: "; cin>>a;
				tb.paycar(a);
				break;
			}
			case'2': {
				cout<<"Enter number of cars not pay tax: "; cin>>b;
				tb.withoutpay(b);
				break;
			}
		}
		cout<<"Press y to continue: "; cin>>input;
	}while(input=='y');
	tb.showData();
	
	return 0;
}