#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int>> p;
int main()
{
    // cout << "Hello World!" << endl;
    int n;cin>>n;
    int l;string s;
    for(int i=0;i<n;i++)
    {
    	cin>>s;
    	cin>>l;
    	p.push_back(make_pair(s,l));
    }
    // sort(p.begin(),p.end());
    sort( p.begin(), p.end(),
               []( const pair<string, int> &p1, const pair<string, int> &p2 )
               {
                   return ( p1.second > p2.second || 
                          ( !( p2.second > p1.second ) && p1.first < p2.first ) );
               } );
    for(int i=0;i<n;i++)
    {
    	cout<<p[i].first<<" "<<p[i].second<<endl;
    }
    return 0;
}
