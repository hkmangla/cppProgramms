#include <iostream> 
using namespace std;
class date{
public:
	int dd,mm,yy;
	void getDate(){
		string s; cin>>s;
		dd = (s[0]-'0')*10 + s[1]-'0';
		mm = (s[3]-'0')*10 + s[4]-'0';
		yy = (s[6]-'0')*1000+(s[7]-'0')*100+(s[8]-'0')*10+(s[9]-'0');
	}
	void displayDate(){
		cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
	}
};
class patient{
public:
	string name,disease;
	date doa,dod;
	void getInfo(){
		cout<<"Enter name of Patient: "; cin>>name;
		cout<<"Enter date of admission in (dd/mm/yy) format: ";
		doa.getDate();
		cout<<"Enter disease of patient: "; cin>>disease;
		cout<<"Enter date of discharge in (dd/mm/yy) format: ";
		dod.getDate();
	}
	void displayInfo(){
		cout<<"Name of Patient: "; cout<<name<<endl;
		cout<<"Date of admission: "; doa.displayDate();
		cout<<"Disease of patient: "; cout<<disease<<endl;
		cout<<"Date of discharge: "; dod.displayDate();
	}
};
class hospital{
public:
	patient p[50];
	int n;
	void getData(){
		cout<<"Enter number of Patient: "; cin>>n;
		for(int i=0;i<n;i++){
			p[i].getInfo();
		}
	}
	void display(){
		for(int i=0;i<n;i++){
			cout<<"Patient "<<i+1<<":"<<endl;
			p[i].displayInfo();
		}
	}
};
class dage:public hospital{
public:
	int age[50];
	void getAge(){
		for(int i=0;i<n;i++){
			cout<<"Enter Age of "<<p[i].name<<": "; cin>>age[i];
		}
	}
	void displad(){
		int j = 0;
		for(int i=0;i<n;i++){
			if(age[i]<=12){
				j++;
				p[i].displayInfo();
			}
		}
		if(j==0) cout<<"There is No paedetric patient"<<endl;
		else cout<<"Out of "<<n<<" patients "<<j<<" are paedetric"<<endl;
	}
};
int main(int argc, char const *argv[]){
	dage a1;
	a1.getData();
	a1.display();
	a1.getAge();
	a1.displad();
	return 0;										
}