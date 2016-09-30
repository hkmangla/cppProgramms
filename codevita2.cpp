#include<bits/stdc++.h>
using namespace std;
int f;
vector<int> graph[2000];
bool vis[2000]; //mark the node if visited 
void bfs(int s) {
    queue <int> q;
    q.push(s);
    vis[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(unsigned int i = 0;i<graph[ p ].size(); i++)
        {
            if(vis[ graph[ p ][ i ] ] == false)
            {
            	f += 1;
                 q.push(graph[ p ][ i ]);
                 vis[ graph[ p ][ i ] ] = true;
             }
        }
    }
}
void initialize() {
    for(int i = 0;i < 2000;++i)
     vis[i] = false;
}

int main(){
	char a[20][100];
	string file;
	cin>>file;
	// string st = "'";
	// file.insert(0,st);
	// file.insert(strlen(file),st);
	// cout<<file.c_str()<<endl;
	freopen(file.c_str(),"r",stdin);
	int n=15,m=60;
	for(int i=0;i<n;i++){
		cin.getline(a[i],sizeof(a[i]));
	}
	// for(int i=0;i<5;i++){
	// 	for(int j=0;j<6;j++){
	// 		cout<<a[i][j];
	// 	}
	// 	cout<<endl;
	// }
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j] == '#'){
				int x,y;
				x = i-1;y=j-1;
				if(x>=0 && y>=0)
				{
					if(a[x][y] =='#')
				graph[m*i+j].push_back(m*x+y);
				}
				x = i;y=j-1;
				if(x>=0 && y>=0)
				{
					if(a[x][y] =='#')
				graph[m*i+j].push_back(m*x+y);
				}
				x = i+1;y=j-1;
				if(x<n && y>=0)
				{
					if(a[x][y] =='#')
				graph[m*i+j].push_back(m*x+y);
				}
				x = i-1;y=j;
				if(x>=0 && y>=0)
				{
					if(a[x][y] =='#')
				graph[m*i+j].push_back(m*x+y);
				}
				x = i-1;y=j+1;
				if(x>=0 && y<m)
				{
					if(a[x][y] =='#')
				graph[m*i+j].push_back(m*x+y);
				}
				x = i;y=j+1;
				if(x>=0 && y<m)
				{
					if(a[x][y] =='#')
				graph[m*i+j].push_back(m*x+y);
				}
				x = i+1;y=j;
				if(x<n && y>=0)
				{
					if(a[x][y] =='#')
				graph[m*i+j].push_back(m*x+y);
				}
				x = i+1;y=j+1;
				if(x<n && y<m)
				{
					if(a[x][y] =='#')
				graph[m*i+j].push_back(m*x+y);
				}
			}
		}
	}
	// for(int j=0;j<5*6;j++){
	// 	cout<<j<<"-> ";
	// for(int i=0;i<graph[j].size();i++)
	// 	cout<<graph[j][i]<<" ";
	// 	cout<<endl;
	// }
	initialize();
	int components = 0;
	int ans[2000];
	int l=0;
	for(int i=0;i<n*m;i++){
		if(vis[i] == false && a[i/m][i%m]=='#'){
			// cout<<i<<endl;
			f = 0;
			bfs(i);
			ans[l] = f+1;
			l++;
			components++;
		}
	}
	sort(ans,ans+l);
	int k=0;
	// cout<<"Output:\n";
	for(int i=l-1;i>=0;i--)
	{
		k ++;
		cout<<"Island "<<k<<": "<<ans[i]<<endl;
	}
	cout<<"Number of continents: "<<components<<endl;
}