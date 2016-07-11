#include<bits/stdc++.h>
using namespace std;
// append(): 	Inserts additional characters at the end of the string (can also be done using ‘+’ or ‘+=’ operator). Its time complexity is O(N) where N is the size of the new string.
// assign(): 	Assigns new string by replacing the previous value (can also be done using ‘=’ operator).
// at():    	Returns the character at a particular position (can also be done using ‘[ ]’ operator). Its time complexity is O(1).
// begin(): 	Returns an iterator pointing to the first character. Its time complexity is O(1).
// clear(): 	Erases all the contents of the string and assign an empty string (“”) of length zero. Its time complexity is O(1).
// compare(): 	Compares the value of the string with the string passed in the parameter and returns an integer accordingly. Its time complexity is O(N + M) where N is the size of the first string and M is the size of the second string.
// copy(): 		Copies the substring of the string in the string passed as parameter and returns the number of characters copied. Its time complexity is O(N) where N is the size of the copied string.
// c_str(): 	Convert the string into C-style string (null terminated string) and returns the pointer to the C-style string. Its time complexity is O(1).
// empty(): 	Returns a boolean value, true if the string is empty and false if the string is not empty. Its time complexity is O(1).
// end(): 		Returns an iterator pointing to a position which is next to the last character. Its time complexity is O(1).
// erase(): 	Deletes a substring of the string. Its time complexity is O(N) where N is the size of the new string.
// find(): 		Searches the string and returns the first occurrence of the parameter in the string. Its time complexity is O(N) where N is the size of the string.
// insert(): 	Inserts additional characters into the string at a particular position. Its time complexity is O(N) where N is the size of the new string.
// length(): 	Returns the length of the string. Its time complexity is O(1).
// replace(): 	Replaces the particular portion of the string. Its time complexity is O(N) where N is size of the new string.
// resize(): 	Resize the string to the new length which can be less than or greater than the current length. Its time complexity is O(N) where N is the size of the new string.
// size(): 		Returns the length of the string. Its time complexity is O(1).
// substr(): 	Returns a string which is the copy of the substring. Its time complexity is O(N) where N is the size of the substring.

int main(){
	string s1("Hello");
	cout<<s1<<endl;
	s1.append("world");
	cout<<s1<<endl;
	s1.assign("Hello again");
	cout<<s1<<endl;
	cout<<s1.at(3)<<endl;
	// cout<<s1.begin()<<endl;
	s1.clear();
	cout<<s1<<endl;
	cout<<s1.compare("hello")<<endl;
	// cout<<s1.copy("hello")<<endl;


}