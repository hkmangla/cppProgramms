#include<bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
struct t_unpair
  {
  T1& a1;
  T2& a2;
  explicit t_unpair( T1& a1, T2& a2 ): a1(a1), a2(a2) { }
  t_unpair<T1,T2>& operator = (const pair<T1,T2>& p)
    {
    a1 = p.first;
    a2 = p.second;
    return *this;
    }
  };

// Our functor helper (creates it)
template <typename T1, typename T2>
t_unpair<T1,T2> unpair( T1& a1, T2& a2 )
  {
  return t_unpair<T1,T2>( a1, a2 );
 }

#define ll long long
int main(){
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int t; cin>>t;
  int tt = 0;
  while(t--){
    tt++;
    ll n,m;
    cin>>n>>m;
    ll a,b;
    ll w[m+1],z[m+1],d[m+1],s[m+1];
    cin>>w[0]>>a>>b;
    cout<<w[0]<<" ";
    for(int i=1;i<m;i++) {
      w[i] = ((a * w[i-1] + b) % n) + 1;
      cout<<w[i]<<" ";
    }
    cin>>d[0]>>a>>b;
    cout<<endl;
    for(int i=1;i<m;i++) d[i] = (a * d[i-1] + b) % 3;
    for(int i=0;i<m;i++) {
      z[i] = max( (ll)1, min(n,w[i]+d[i]-1)); 
      cout<<z[i]<<" ";
    }
    cin>>s[0]>>a>>b;
    cout<<endl<<s[0]<<" ";
    for(int i=1;i<m;i++) {
      s[i] = ((a * s[i-1] + b) % 1000000000) + 1;
      cout<<s[i]<<" "; 
    }
    cout<<endl;

  }
}