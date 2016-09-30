#include "bits/stdc++.h"
using namespace std;
 
int a[1001][1001];
std::vector<int> graph[1001];
bool visited[1001];
void intial(){
    for(int i=0;i<1001;i++)
    {
        visited[i] = false;
        graph[i].clear();
    }
    memset(a, 0, sizeof(a));
}
int main(int argc, char const *argv[])
{
    int t; cin>>t;
    while(t--){
        intial();
        int node, edge;
        cin>>node>>edge;
        for(int i=0;i<edge;i++){
            int x,y;
            cin>>x>>y;
            if(!a[x][y] && x!=y){
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
            a[x][y] = 1;
            a[y][x] =1 ;
        }
        int minmum = 1000000,minNode;
        for(int i=1;i<=node;i++){
            if(minmum > graph[i].size()){
                minmum = graph[i].size();
                minNode = i;
            }
        }
        vector <int> table1;
        table1.push_back(minNode);
        set<int> workingNode;
        for(int i=0;i<graph[minNode].size();i++){
            workingNode.insert(graph[minNode][i]);
        }
        set<int>:: iterator it;
        while(!workingNode.empty()){
            it = workingNode.begin();
            table1.push_back(*it);
            workingNode.erase(*it);
            for(set<int>::iterator iit = workingNode.begin();iit!=workingNode.end();++iit){
                if(!a[*it][*iit]) workingNode.erase(*iit);
            }
        }
        // cout<<"table1 : "<<endl;
        // cout<<table1.size()<<endl;
        for(int i=0;i<table1.size();i++)
        {
            // cout<<table1[i]<<" ";
            visited[table1[i]] = true;
        }
        // cout<<endl;
        int anotherNode = -1;
        for(int i=1;i<=node;i++){
            if(!visited[i]){
                anotherNode = i;
                break;
            }
        }
        if(anotherNode == -1){
            cout<<"YES"<<endl; continue;
        }
        // int minmum
        minmum = 10000000;
        for(int i = 1;i<=node;i++){
            if(!visited[i]){
              int count = 0;
                for(int j=0;j<graph[i].size();j++){
                    if(!visited[graph[i][j]]) count++;
                }
                minmum = min(minmum, count);
            }
        }
        if(minmum >= (node - 1 - table1.size())){
            cout<<"YES"<<endl; continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
} 