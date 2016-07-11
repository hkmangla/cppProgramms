#include<bits/stdc++.h>
using namespace std;
// Some of the member functions of Stack are: 
// push( ): Insert element at the top of stack. Its time complexity is O(1). 
// pop( ): removes element from top of stack. Its time complexity is O(1). 
// top( ): access the top element of stack. Its time complexity is O(1). 
// empty( ): checks if the stack is empty or not. Its time complexity is O(1). 
// size( ): returns the size of stack. Its time complexity is O(1)
stack<int> a; 
int main()
{
	int t =10;
	a.push(t);
	a.pop();
	cout<<a.empty();
}