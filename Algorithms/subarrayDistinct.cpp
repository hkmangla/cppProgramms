#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n; cin>>n;
	int a[n+1]; 
	set <int> elements;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		elements.insert(a[i]);
	}	
	set <int> anotherElem;
	int end = n+1;
	multiset <int> array;
	int disSize = elements.size();
	for(int i = 0; i<n;i++){
		anotherElem.insert(a[i]);
		array.insert(a[i]);
		if(anotherElem.size() == elements.size())
		{
			end = i;
			break;
		}
	}
	// cout<<end<<endl;
	long long ans = 0;
	if(end == n+1){
		cout<<"0"<<endl;
		return 0;
	}
	for(int i=0;i<=n-disSize;i++){
		ans += (n-end);
		// cout<<ans<<endl;
		// cout<<"arra :"<<array.size()<<endl;
		if(array.find(a[i])!=array.end())
  			 array.erase(array.equal_range(a[i]).first);
		// cout<<"arra :"<<array.size()<<endl;
		while(end < n){
		if(array.find(a[i])!=array.end())
		{
			break;
		}
		end ++;
		array.insert(a[end]);
		}
		
	}
	cout<<ans<<endl;
	return 0;
}