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
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
template<class type>
type gcd(type a, type b) {return (b==0)?a:gcd(b,a%b);}

vector<int> v[10001];
int level[10001]; // to determine the level of each node
bool vis[10001];
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
    for(int i = 0;i < 10001;++i)
    {vis[i] = false;
    level[i] = -1;
    v[i].clear();
    }
}
int main()
{
	doit()
	{
	initialize();
	int n,m,k1,k2;
	cin>>n>>m>>k1>>k2;
	int a[n+1][m+1];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	int k = max(k1,k2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int node = m*i + j + 1;
			if(a[i][j] == 0){
				// cout<<"Yes"<<endl;
				for(int lll=1;lll<=k;lll++){
					for(int l=0;l<=lll;l++){
					if(i-lll+l >= 0 && j-l >= 0)
					{
						if(a[i-lll+l][j-l] == 0)
						v[node].push_back((m*(i-lll+l) + j - l + 1));
					}
					if(i+lll-l < n && j-l >= 0)
					{
						if(a[i+lll-l][j-l] == 0)
						v[node].push_back((m*(i+lll-l) + j - l + 1));
					}

					if(i-lll+l >= 0 && j+l < m)
					{
						if(a[i-lll+l][j+l] == 0)
						v[node].push_back((m*(i-lll+l) + j + l + 1));
					}

					if(i+lll-l < n && j+l < m)
					{
						if(a[i+lll-l][j+l] == 0)
						v[node].push_back((m*(i+lll-l) + j + l + 1));
					}
				}
				}
			}
		}
	}
	bfs(1);
	int level1[10001];
	for(int i = 1;i <= n*m; i++)
		level1[i] = level[i];
	initialize();
	k = min(k1,k2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int node = m*i + j + 1;
			if(a[i][j] == 0){
				// cout<<"Yes"<<endl;
				set<int> st;
				for(int lll=1;lll<=k;lll++){
					for(int l=0;l<=lll;l++){
					if(i-lll+l >= 0 && j-l >= 0)
					{
						if(a[i-lll+l][j-l] == 0)
							st.insert((m*(i-lll+l) + j - l + 1));
					}
					if(i+lll-l < n && j-l >= 0)
					{
						if(a[i+lll-l][j-l] == 0)
							st.insert((m*(i+lll-l) + j - l + 1));
					}

					if(i-lll+l >= 0 && j+l < m)
					{
						if(a[i-lll+l][j+l] == 0)
							st.insert((m*(i-lll+l) + j + l + 1));
					}

					if(i+lll-l < n && j+l < m)
					{
						if(a[i+lll-l][j+l] == 0)
							st.insert((m*(i+lll-l) + j + l + 1));
					}
				}
				}
				tr(st,it) v[node].push_back(*it);
			}
			// else{
			// 	v[node].push_back(0);
			// }			
		}
	}
	bfs(m);
	int ans = 1000000000;
	int ans1 = 1000000000;
	for(int i=1;i <= n*m;i++)
		{
			if(level[i] != -1 && level1[i] != -1)
				ans1 = max(level1[i], level[i]);
			ans = min(ans, ans1);
		}
	if(ans == 1000000000)
		cout<<"-1\n";
	if(ans != 1000000000)
	cout<<ans<<endl;
	}
	return 0;
}