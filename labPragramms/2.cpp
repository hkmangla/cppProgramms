#include "iostream"
using namespace std;

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

int main(){
	Point P1,P2,P3;
	cout<<"Enter coordinates for P1: ";
	cin>>P1.x>>P1.y;
	cout<<"Enter coordinates for P2: ";
	cin>>P2.x>>P2.y;
	P3 = P1.addPoint(P2);
	cout<<"Coordinates of P1+P2 are: "<<P3.x<<" "<<P3.y<<endl;
}