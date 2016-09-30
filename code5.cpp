#include "bits/stdc++.h"
using namespace std;
int date[3];
int check(int m, int y){
	if(m == 1 || m== 3 || m== 5 || m== 7 || m==8 || m==10 || m==12)
		return 31;
	else if(m!=2)
		return 30;
	else{
		if(y%4==0){
			if(y%100==0){
				if(y%400 == 0)
					return 29;
				else
					return 28;
			}
			else
				return 29;
		}
		else
			return 28;
	}
}
bool checkdate(string s)
{
	string temp = "";
	int l=0;
	for(int i=0;i<(int)s.length();i++)
	{
		if(s[i] == '/'){
			date[l] = strtol(temp.c_str(),NULL,10);
			l++;
			if(temp == "")
				return false;
			// cout<<date[l-1]<<endl;
			temp = "";
		}
		else{
			if(s[i] < '0' || s[i] > '9')
				return false;
			temp += s[i];
		}
	}
	if(l>=3 || l < 2)
		return false;
	date[l] = strtol(temp.c_str(),NULL,10);
	l++;
	if(date[1] > 12)
		return false;
	else if(date[0] > check(date[1], date[2]))
		return false;
	else{
		return true;
	}
}
int totalLeap(int dated){
	int div4 = dated/4;
	int div100 = dated/100;
	int div400 = dated/400;
	return div4 - div400 + div100;
}
int totalDays(){
	int total = 0;
	total = (date[2] - 1)*365;
	// cout<<total<<endl;
	total += totalLeap(date[2]-1);
	for(int i=1;i<date[1];i++){
		total += check(i,date[2]);
		// cout<<total<<endl;
	}
	total += date[0];
	return total;
}
int yearDay(){
	int total = 0;
	for(int i=1;i<date[1];i++)
		total += check(i,date[2]);
	total += date[0];
	return total;
}
int checkDay(int totalDays){
	return (totalDays%7 == 0)?7:totalDays%7;
}
int main(int argc, char const *argv[])
{
	string day,dat; int dayl;
	// getline(cin,day)
	getline(cin,day);
	// cout<<day<<endl;
	getline(cin,dat);
	if(day == "Monday" )
	  dayl = 1;
	 else if(day == "Tuesday")
	  dayl= 2;
	  else if(day == "Wednesday")
	  dayl = 3;
	  else if(day == "Thursday")
	  	dayl = 4;
	  else if(day == "Friday")
	  dayl = 5;
	  else if(day=="Saturday")
	  	dayl = 6;
	  else if( day  == "Sunday")
	  	dayl = 7;
	  else{
	  	cout<<"Invalid Day"<<endl;
	  	return 0;
	  }
	  // if(dat == "")
	  bool o = checkdate(dat);
	  if(!o){
	  cout<<"Invalid Date"<<endl;
	  	return 0;
	  }

	  int totaldays = totalDays();
	  // cout<<(totaldays)<<endl;
	  // cout<<checkDay(totaldays+dayl-1)<<endl;
	  if(checkDay(totaldays+dayl-1) == 6 || checkDay(totaldays+dayl-1) == 7 )
	  		{
	  			cout<<"0"<<endl;
	  			return 0;
	  		}
	  if(totaldays%4 ==0)
	  	{
	  		cout<<"0"<<endl;
	  			return 0;
	 	}
	 if(yearDay() > 50){
	 	cout<<"50"<<endl;
	 }
	 else{
	 	cout<<yearDay()<<endl;
	 	return 0;
	 }

	return 0;
}