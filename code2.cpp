#include "bits/stdc++.h"
using namespace std;

int x[300];
int y[300];

struct data
{
	string lang;
	int value;
};
data countTime(){
	string lang,input;
	bool flag = true;
	int i = 0;
	string code[10000];
	while(getline(cin,input)){
		if(input.empty()) break;
		if(flag){
			lang = input;
			flag = false;
		}
		else{
		code[i] = input;
		i++;
		}
	}
	int count = 0;
	for(int j=0;j<i;j++){
		for(int k=0;k<code[j].length();k++){
			if(k == 0){
				if(j>0){
				count += max(abs(x[code[j][k] - ' ']-x[code[j-1][code[j-1].length()-1] - ' ']), abs(y[code[j][k] - ' '] - y[code[j-1][code[j-1].length()-1] - ' ']));
				}
			}
			else{
				count += max(abs(x[code[j][k] - ' ']-x[code[j][k-1] - ' ']), abs(y[code[j][k] - ' '] - y[code[j][k-1] - ' ']));
			}
		}
	}
	data tmp;
	tmp.lang = lang;
	tmp.value = count;
	return tmp;
}
int main(int argc, char const *argv[])
{
	freopen("template.in","r",stdin);
	freopen("template.out","w",stdout);
	int n,m; cin>>n>>m;
	string keyBoard[m];
	cin.ignore();
	for(int i=0;i<m;i++){
		getline(cin,keyBoard[i]);
	}
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++){
			x[keyBoard[i][j] - ' '] = i;
			y[keyBoard[i][j] - ' '] = j;
		}
	}
	cin.ignore();
	int minValue = 1000000000;
	string language;
	for(int i=0;i<3;i++){
		data ans = countTime();
		if(ans.value < minValue){
			minValue = ans.value;
			language = ans.lang;
		}
	}
	cout<<language<<endl;
	cout<<minValue<<endl;
	return 0;
}
