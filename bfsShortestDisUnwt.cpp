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









vector <int> v[1000];
// bool visited[10];
// vector <int> v[10] ;   // vector for maintaining adjacency list explained above.
int level[1000]; // to determine the level of each node
bool vis[1000]; //mark the node if visited 
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
        //setting the level of each node with an increment in the level of parent node
                level[ v[ p ][ i ] ] = level[ p ]+1;                 
                 q.push(v[ p ][ i ]);
                 vis[ v[ p ][ i ] ] = true;
             }
        }
    }
}
void initialize() {
    for(int i = 0;i < 1000;++i)
    {vis[i] = false;
    v[i].clear();
    }
}

int main() {
    int t;cin>>t;
    while(t--){
        initialize();  
    int nodes, edges, x, y, connectedComponents = 0;
    cin >> nodes;                       // Number of nodes
    cin >> edges;                       // Number of edges
    for(int i = 0;i < edges;++i) {
     cin >> x >> y;     
 // Undirected Graph 
     v[x].push_back(y);                   // Edge from vertex x to vertex y
     v[y].push_back(x);                   // Edge from vertex y to vertex x
    }
    int start;
    cin>>start;
                         // Initialize all nodes as not visited      
    bfs(start);
    for(int i=1;i<=nodes;i++){
        if(i != start){
            if(vis[i])
                cout<<level[i]<<" ";
            else
                cout<<"-1 ";
        }
    }
        cout<<endl;
    }
    // cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}