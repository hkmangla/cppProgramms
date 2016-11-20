#include <bits/stdc++.h>
using namespace std;
class employee{
public:
	string name; double salary;
	void getData(){
		cout<<"Enter name and salary of the employee"<<endl;
		cin>>name>>salary;
	}
	void show1(){
		cout<<"Name of the employee: "<<name<<endl;
		cout<<"Salary of the employee: "<<salary<<endl;
	}
};
class manager: public employee{
public:
	string deptt;
	void get_deptt(){
		cout<<"Enter Deptt of manager: "; cin>>deptt;
	}
	void show2(){
		cout<<"Manager of Department: "<<deptt<<endl;
	}
};
class executive: public manager{
public:
	void display(){
		cout<<"Data of executive manager"<<endl;
		show1(); show2();
	}
};
int main(int argc, char const *argv[]){
	executive ex;
	ex.getData();
	cout<<"If employee is executive manager(Y/N): ";
	char y; cin>>y;
	if(y=='Y') {
		ex.get_deptt();
		ex.display();
	}
	else{
		ex.show1();
	}
	return 0;							   
}
