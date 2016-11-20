#include <iostream>
using namespace std;
class DB;
class DM{
public:
	double meter,centimeter;
	void getData(){
		cout<<"Enter Distance in meter: ";
		cin>>meter;
		cout<<"Enter Distance in centimeter: ";
		cin>>centimeter;
	}
	void display(){
		cout<<"Distance in meter is: "<<meter<<endl;
		cout<<"Distance in centimeter is: "<<centimeter<<endl;
	}
	friend DM add(DB,DM);
};
class DB{
public:
	double feet, inches;
	void getData(){
		cout<<"Enter Distance in feet: ";
		cin>>feet;
		cout<<"Enter Distance in inches: ";
		cin>>inches;
	}
	void display(){
		cout<<"Distance in feet is: "<<feet<<endl;
		cout<<"Distance in inches is: "<<inches<<endl;
	}
	friend DM add(DB,DM);
};
DM add(DB a, DM b){
	DM temp;
	temp.meter = b.meter + b.centimeter/100 + a.feet*0.3048+a.inches*0.0254;
	temp.centimeter = temp.meter * 100;
	return temp;
}
int main(int argc, char const *argv[]){
	DM a; a.getData();
	DB b; b.getData();
	DM c = add(b,a);
	c.display();
	return 0;
}