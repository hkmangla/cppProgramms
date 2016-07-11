#include<bits/stdc++.h>
using namespace std;
// Some member function of Queues are:
// push( ): inserts an element in queue at one end(rear ). Its time complexity is O(1). 
// pop( ): deletes an element from another end if queue(front). Its time complexity is O(1). 
// front( ): access the element on the front end of queue. Its time complexity is O(1). 
// empty( ): checks if the queue is empty or not. Its time complexity is O(1). 
// size( ): returns the size of queue. Its time complexity is O(1).
queue<int> a;
int main(){
	int t = 10;
	a.push(t);
	a.push(t+6);
	cout<<a.back()<<endl;
	cout<<a.front()<<endl;
	cout<<a.size()<<endl;
	cout<<a.empty()<<endl;
	a.pop();
	cout<<a.front()<<endl;
}