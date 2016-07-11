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

int main()
{
	// doit()
	// {
	int n;
	int mod = 786433;
	cin>>n;
	ll a[n+1];
	for(int i=0;i<=n;i++)
		cin>>a[i];
	int query;cin>>query;
	while(query--){

	ll q;cin>>q;
	ll ans= 0,pows = 1;
	for(int i=0;i<=n;i++){
		ans += (a[i]*pows);
		ans%=mod;
		pows = (q*pows)%mod;
	}
	cout<<ans<<endl;
	}
// }
	return 0;
}