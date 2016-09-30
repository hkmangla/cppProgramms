#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n; cin>>n;
	int a[n+1]; 
	
	map<int, int> array;
	// memset(array, 0, sizeof(array));
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(array.find(a[i])!= array.end())
		array[a[i]] ++;
		else
			array[a[i]] = 1;
	}
	std::vector<int> newArray;
	set<int> elem;
	long long ans = 0;
	for(int i=0;i<n;i++){
		if(elem.find(a[i]) != elem.end()){
			if(array[a[i]] == 1)
				newArray.push_back(a[i]);
		}
		else{
			newArray.push_back(a[i]);
			elem.insert(a[i]);
		}
		array[a[i]] --;
	}
	map<int,int> d;
	for(int i=0;i<newArray.size();i++){
		if(d.find(newArray[i])==d.end())
			d[newArray[i]] = i;
	}
	elem.clear();
	for(int i=0;i<newArray.size();i++){
		// cout<<newArray[i]<<" ";
		if(elem.find(newArray[i])==elem.end()){
			ans += newArray.size()-i-1;
			elem.insert(newArray[i]);
		}
		else{
			
			ans -= d[newArray[i]];
		}
	}

	cout<<ans<<endl;






	return 0;
}