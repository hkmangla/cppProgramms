#include<bits/stdc++.h>
using namespace std;
//Class is a blue print of a data type;
//eg BOX is blue print of data type having box length ,breadth, hieght it does not include any function;
//Class have three type of members
// private members of a class are accessible only from within other members of the same class (or from their "friends").
// protected members are accessible from other members of the same class (or from their "friends"), but also from members of their derived classes.
// Finally, public members are accessible from anywhere where the object is visible.

class BOX{
public:
	int length;
	int breadth;
	int hieght;
};

//Class Rectangle having function set_values() and area() and two private member width and breadth;
class Rectangle{
	int width,breadth;
public:
	void set_values(int,int); //Prototype of function in class
	int area(){return width*breadth;}
}; 
// Declaring function 
void Rectangle::set_values(int x,int y){
	width = x;
	breadth=y;
}

//set_values function can easily be avoid by using constructor 
//Constructor is nothing but is a function member of class having none of return type even not void and same name as class
//Let's make Triangle using constructor
class Triangle{
	int base,prep,hyp;
public:
	Triangle(int,int,int); //Constructor
	int area(){return base*prep*hyp;}
};

Triangle::Triangle(int x, int y, int z){
	base = x;
	prep = y;
	hyp = z;
}

int main(){
		BOX box1;
		cin>>box1.length>>box1.breadth>>box1.hieght;
		cout<<box1.length<<" "<<box1.breadth<<" "<<box1.hieght<<endl;
		cout<<"Volume of box1 is: "<<box1.length * box1.breadth * box1.hieght<<endl;
		Rectangle rect;
		rect.set_values(4,5);
		cout<<rect.area()<<endl;
		Triangle tri(3,4,5);
		cout<<tri.area()<<endl;
}