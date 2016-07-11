#include<bits/stdc++.h>
using namespace std;



typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
#define ll long long int
#define doit() int t; cin>>t;while(t--)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())









vector <int> adj[10];
bool visited[10];
stack<int> dfs_stk;
void dfs_recursion(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i)    {
     if(visited[adj[s][i]] == false)
         dfs_recursion(adj[s][i]);
    }
}
void dfs_stacks(int s){
        dfs_stk.push(s);
        visited[s] = true;
        while(!dfs_stk.empty()){
            int v = dfs_stk.top();
            dfs_stk.pop();
            for(int i = 0;i < adj[v].size();++i)    {
               if(visited[adj[v][i]] == false)
               {
                dfs_stk.push(adj[v][i]);
                visited[adj[v][i]] = true;
               }
            } 
        }
}
void initialize() {
    for(int i = 0;i < 10;++i)
     visited[i] = false;
}

int main() {
    int nodes, edges, x, y, connectedComponents = 0;
    cin >> nodes;                       // Number of nodes
    cin >> edges;                       // Number of edges
    for(int i = 0;i < edges;++i) {
     cin >> x >> y;     
 // Undirected Graph 
     adj[x].push_back(y);                   // Edge from vertex x to vertex y
     adj[y].push_back(x);                   // Edge from vertex y to vertex x
    }

    initialize();                           // Initialize all nodes as not visited

    for(int i = 1;i <= nodes;++i) {
     if(visited[i] == false)     {
         dfs_recursion(i);
         connectedComponents++;
     }
    }
    cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}