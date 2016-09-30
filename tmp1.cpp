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









vector<pair<int, int> > v[1000001];
vector<int> disance(1000001);
bool vis[1000001]; //mark the node if visited 
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
    for(int i = 0;i < 1000001;++i)
    {
    disance[i] = i;
    }
}

int main() {
     // initialize();  
    int nodes, edges, x, y, r;
    cin >> nodes;                       // Number of nodes
    cin >> edges;                       // Number of edges
    for(int i = 0;i < edges;++i) {
     cin >> x >> y >> r;     
    v[x].push_back(make_pair(y,r));                   // Edge from vertex x to vertex y
    }
    bfs(0);
    for(int i=1;i<=nodes;i++){
            if(vis[i])
                cout<<disance[i]<<" ";
            else
                cout<<"-1 ";
    }
    return 0;
}