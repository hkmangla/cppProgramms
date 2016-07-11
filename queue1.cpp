#include<bits/stdc++.h>
using namespace std;
int a[101];
queue<int> b;
// queue<int> c;
// queue<int>s;
int main(){
	int n,x,count = 0; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		b.push(x);
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
		int i = 0,l;
		while(!b.empty()){
			l = b.front()
			b.pop()
			if(l == a[i])
				i++;
			else
				b.push(l);
			count++;
		}
	cout<<count<<endl;

}