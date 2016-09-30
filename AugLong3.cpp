#include<bits/stdc++.h>
using namespace std;
vector <int> v[100001];
// int level[1000]; // to determine the level of each node
bool vis[100001]; //mark the node if visited 
void bfs(int s) {
    queue <int> q;
    q.push(s);
    level[ s ] = 0 ;  //setting the level of sources node as 0.
    vis[ s ] = true;
    std::vector<int> path;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        if(p == v){
            
            break;
        }
        for(int i = 0;i < v[ p ].size() ; i++)
        {
            if(vis[ v[ p ][ i ] ] == false)
            {
        //setting the level of each node with an increment in the level of parent node
                level[ v[ p ][ i ] ] = level[ p ]+1;                 
                 q.push(v[ p ][ i ]);
                 vis[ v[ p ][ i ] ] = true;
             }
        }
    }
}
void initialize() {
    for(int i = 0;i < 100001;++i)
    {vis[i] = false;
    v[i].clear();
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    int a[n+1];
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<n;i++){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
    }
    int query; cin>> query;
    if(query == 1){

    }
}