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









vector<pair<int, int> > v[3001];
vector<int> disance(3001);
bool vis[3001]; //mark the node if visited 
void bfs(int s) {
    queue <int> q;
    q.push(s);
    disance[s] = 0;
    vis[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0;i < v[ p ].size() ; i++)
        {
            if(vis[ v[ p ][ i ].first ] == false)
            {
                disance[v[p][i].first] = (disance[p] + v[p][i].second);
                 q.push(v[ p ][ i ].first);
                 vis[ v[ p ][ i ].first ] = true;
            }
            if(disance[v[p][i].first] > (disance[p] + v[p][i].second))
            {
                disance[v[p][i].first] = (disance[p] + v[p][i].second);
                                 q.push(v[ p ][ i ].first);
            }
        }
    }
}
void initialize() {
    for(int i = 0;i < 3001;++i)
    {vis[i] = false;
    v[i].clear();
    disance[i] = 0;
    }
}

int main() {
    int t;cin>>t;
    while(t--){
        initialize();  
    int nodes, edges, x, y, r;
    cin >> nodes;                       // Number of nodes
    cin >> edges;                       // Number of edges
    for(int i = 0;i < edges;++i) {
     cin >> x >> y >> r;     
 // Undirected Graph 
    v[x].push_back(make_pair(y,r));                   // Edge from vertex x to vertex y
    v[y].push_back(make_pair(x,r));
    // for(int j=0;j<v[x].size();j++)  
    // hemant = v[x][j].second;
                 // Edge from vertex y to vertex x
    }
    int start;
    cin>>start;
                         // Initialize all nodes as not visited      
    bfs(start);
    for(int i=1;i<=nodes;i++){
        if(i != start){
            if(vis[i])
                cout<<disance[i]<<" ";
            else
                cout<<"-1 ";
        }
    }
    cout<<endl;
    }
    // cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}