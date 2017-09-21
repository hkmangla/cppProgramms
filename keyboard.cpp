// Name     : Hemant Mangla
// username : hkmangla
// Country	: India
// College  : Deenbandhu Chhotu Ram University of Science and Technology Murthal
// emailId  : hemantmangla78@gmail.com

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,b) for(int i=a;i<b;i++)


//currentj means last value

class Keyboard{
	bool isCapsLock;
	char outputString[1003][1003];
	char opr;
	int last_col;
	int currentCursori,currentCursorj;
	int maxdownCursor;
	int lastposj[1003];
public:
	Keyboard(){
		isCapsLock = false;
		currentCursori = 0;
		last_col = -1;
		currentCursorj = -1;
		maxdownCursor = 0;
		memset(lastposj,-1,sizeof(lastposj));
	}
	~Keyboard(){}

	void insertChar(char c){
		lastposj[currentCursori] ++;
		for(int i=lastposj[currentCursori];i>(currentCursorj+1);i--)
			outputString[currentCursori][i] = outputString[currentCursori][i-1];
		outputString[currentCursori][currentCursorj+1] = change(c);
		currentCursorj++;
	}
	void applyCaps(){
		isCapsLock = !isCapsLock;
	}
	char change(char c){
		if(isCapsLock){
			if(c>='a' and c <= 'z') c -= 32;
		}
		else {
			if(c >= 'A' and c <= 'Z') c+= 32;
		}
		return c;
	}
	void enter(){
		maxdownCursor ++;
		// cout<<maxdownCursor<< " " <<currentCursori<<endl;
		// cout<<outputString[1]<<endl;
		for(int i = maxdownCursor; i>(currentCursori+1);i--){
			for(int j = 0;j<=lastposj[i-1];j++)
				outputString[i][j] = outputString[i-1][j];
			lastposj[i] = lastposj[i-1];
		}
		int l = 0;
		for(int i=currentCursorj+1;i<=lastposj[currentCursori];i++){
			l++;
			outputString[currentCursori+1][i-(currentCursorj+1)] = outputString[currentCursori][i];
		}
		lastposj[currentCursori] = currentCursorj;
		lastposj[currentCursori+1] = l-1;
		currentCursori ++;
		currentCursorj = -1; 
	}
	void leftArrow(){
		if(currentCursorj == -1){
			if(currentCursori == 0) return;
			else{
				currentCursori --;
				currentCursorj = lastposj[currentCursori];
			}
		}
		else{
			currentCursorj--;
		}
	}
	void rightArrow(){
		// cout<<currentCursorj<<endl;
		if(currentCursorj == lastposj[currentCursori]){
			if(currentCursori == maxdownCursor) return;
			else{
				currentCursori ++;
				currentCursorj = -1;
			}
		}
		else{
			currentCursorj ++;
		}
	}
	void downArrow(){
		if(last_col == -1) last_col = currentCursorj;
		if(currentCursori == maxdownCursor) return;
		else{
			currentCursori ++;
			currentCursorj = max(last_col,currentCursorj);	
			if(currentCursorj > lastposj[currentCursori])
				currentCursorj = lastposj[currentCursori];
		}
	}
	void upArrow(){
		if(last_col == -1) last_col = currentCursorj;
		if(currentCursori == 0) return;
		else{
			currentCursori --;
			currentCursorj = max(last_col,currentCursorj);	
			if(currentCursorj > lastposj[currentCursori])
				currentCursorj = lastposj[currentCursori];
		}
	}
	void backSpace(){
		if(currentCursorj == -1){
			if(currentCursori == 0) return;
			else{
				for(int i=0;i<=lastposj[currentCursori];i++){
					outputString[currentCursori-1][lastposj[currentCursori-1] + i+1] = outputString[currentCursori][i];		
				}
				currentCursorj = lastposj[currentCursori-1];
				lastposj[currentCursori-1] += (lastposj[currentCursori]+1);
				for(int i=currentCursori;i<maxdownCursor;i++){
					for(int j=0;j<=lastposj[currentCursori+1];j++)
						outputString[i][j] = outputString[i+1][j];
					lastposj[i] = lastposj[i+1];
				}
				maxdownCursor --;
				currentCursori --;
			}
		}
		else{
			for(int i=currentCursorj;i<lastposj[currentCursori];i++)
				outputString[currentCursori][i] = outputString[currentCursori][i+1];
			lastposj[currentCursori] --;
			currentCursorj --;
		}
	}
	void insert(string inp){
		// cout<<"............."<<endl;
		for(auto c:inp){
			if(c != '^' and c != '?') last_col = -1;
			printOutput();
			cout<<"Operation.... "<<c<<endl;
			switch(c){
				case '@' : applyCaps();break;
				case '#' : enter();break;
				case '<' : leftArrow();break;
				case '>' : rightArrow();break;
				case '/' : backSpace();break;
				case '?' : downArrow();break;
				case '^' : upArrow();break;
				default  : insertChar(c);
			}
		}
	}
	void printOutput(){
		// cout<<"i: "<<outputString[1]<<endl;
		for(int i=0;i<=maxdownCursor;i++){
			if(i == currentCursori and currentCursorj == -1) cout<<"|";
			for(int j=0;j<=lastposj[i];j++){
				cout<<outputString[i][j];
				if(i==currentCursori and j == currentCursorj) cout<<"|";
			}
			cout<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	freopen("output.txt","w",stdout);
	string inp; getline(cin,inp);
	Keyboard keyboard;
	keyboard.insert(inp);
	keyboard.printOutput();
	return 0;
}