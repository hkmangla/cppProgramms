#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	int n,k,query;
	string input;
	set<int> voteBox;
	cin>>n>>k;
	while(k--){
		cin>>input;
		if(input == "CLOSEALL")
		{
			voteBox.clear();
			cout<<voteBox.size()<<endl;
		}
		else
		{
			cin>>query;
			if(voteBox.find(query)!=voteBox.end())
			{
				voteBox.erase(query);
			}
			else
				voteBox.insert(query);
			cout<<voteBox.size()<<endl;
		}
	}
	return 0;
}