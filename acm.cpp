#include "bits/stdc++.h"
using namespace std;
bool visited[100001];
vector<int> graph[100001];
bool isCyclic(int s, int parent){
	visited[s] = true;
	for(int i=0;i<graph[s].size();i++){
			if(!visited[graph[s][i]]){
				return isCyclic(graph[s][i],s);
			}
			else if(graph[s][i] != parent) return true;
		}
	return false;
}

int main(int argc, char const *argv[])
{
	fre	open("input.txt","r",stdin);
	char s[4];
	while(scanf("%s",&s) != EOF){
		graph[s[0]-'A'].push_back(s[2]-'A');
		graph[s[2]-'A'].push_back(s[0]-'A');
	}
	memset(visited,-1,sizeof(visited));
	cout<<isCyclic(0,-1)<<endl;
	return 0;
}






