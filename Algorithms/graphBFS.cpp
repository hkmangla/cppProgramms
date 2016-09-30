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









vector <int> v[10];
// bool visited[10];
// vector <int> v[10] ;   // vector for maintaining adjacency list explained above.
int level[10]; // to determine the level of each node
bool vis[10]; //mark the node if visited 
void bfs(int s) {
    queue <int> q;
    q.push(s);
    level[ s ] = 0 ;  //setting the level of sources node as 0.
    vis[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0;i < v[ p ].size() ; i++)
        {
            if(vis[ v[ p ][ i ] ] == false)
            {
                level[ v[ p ][ i ] ] = level[ p ]+1;                 
                 q.push(v[ p ][ i ]);
                 vis[ v[ p ][ i ] ] = true;
             }
        }
    }
}
void initialize() {
    for(int i = 0;i < 10;++i)
     vis[i] = false;
}

int main() {
    int nodes, edges, x, y, connectedComponents = 0;
    cin >> nodes;                       // Number of nodes
    cin >> edges;                       // Number of edges
    for(int i = 0;i < edges;++i) {
     cin >> x >> y;     
 // Undirected Graph 
     v[x].push_back(y);                   // Edge from vertex x to vertex y
     v[y].push_back(x);                   // Edge from vertex y to vertex x
    }

    initialize();                           // Initialize all nodes as not visited

    for(int i = 1;i <= nodes;++i) {
     if(vis[i] == false)     {
         bfs(i);
     }
    }
    // cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}