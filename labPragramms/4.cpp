#include <iostream>
#include <fstream>
using namespace std;
class student{
	long long  rollNo, marks;
	char name[30];
public:
	void getData(){
		cout<<"Enter Roll No: ";
		cin>>rollNo;
		cout<<"Enter name of Student: ";
		cin>>name;
		cout<<"Enter marks: ";
		cin>>marks;
	}
};
int main(int argc, char const *argv[]){
	student Students[30];
	fstream fio;
	fio.open("Student.txt",ios::binary|ios::out);
	for(int i=0;i<4;i++){
		Students[i].getData();
		fio.write((char *)&Students[i], sizeof(Students[i]));
	}
	fio.close();
	return 0;
}