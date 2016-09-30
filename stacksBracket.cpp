#include<bits/stdc++.h>
using namespace std;
int main(){
		int n; cin>>n;
		int a[n]; for(int i=0;i<n;i++) cin>>a[i];
		stack<int> bracket;
		int pos;
		int lenght = 0,maxDepth = 0,maxLenght = 0;
		for(int i=0;i<n;i++)
		{
			if(a[i] == 1)
				bracket.push(1);
			else{
				bracket.pop();
			}
			lenght ++;
			if(lenght > maxLenght)
			{
				//pos = i+1;
				maxLenght = lenght;
			}
			if(bracket.size() == 0)
			{
				lenght = 0;
			}
			maxDepth = max((int)bracket.size(),maxDepth);
		}
		for(int i=0;i<n;i++)
		{
			if(a[i] == 1)
				bracket.push(1);
			else{
				bracket.pop();
			}
			lenght ++;
			if(lenght == maxLenght)
			{
				//pos = i+1;
				pos = i+2-lenght;
				break;
			}
			if(bracket.size() == 0)
			{
				lenght = 0;
			}
		}
		int maxPos;
		stack<int> brackets;
		for(int i=0;i<n;i++)
		{
			if(a[i] == 1)
				brackets.push(i+1);
			else{
				brackets.pop();
			}
			if(brackets.size() == maxDepth)
			{
				maxPos = brackets.top();
				break;
			}
		}
		cout<<maxDepth<<" "<<maxPos<<" "<<maxLenght<<" "<<pos<<endl;
}