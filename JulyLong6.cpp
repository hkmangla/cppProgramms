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
	doit()
	{
	int n;
	map<int, int> mp;
	cin>>n;
	ll a[n];
	ll dp[n+2][n+2];
	for(int i =0 ;i< n;i++)
		{cin>>a[i];
			// dp[0][i] = 0;
			// dp[i][0] = 0;
		}
		int imp[n+2];
	for(int i=0;i<=n;i++){
		imp[i] = 0;
		for(int j=0;j<=n;j++)
			dp[i][j] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
		{
			if(a[j-1] == a[i-1])
			{
				dp[i][j] = 0;
				imp[j] = 0;
			}
			else{
				int v = imp[j]+1;
				dp[i][j] += (imp[j]+1);
				imp[j] += 1;	
				for(int l=j-1;dp[i][l] != 0;l--)
				{
					v = min(imp[l],v);
					dp[i][j] += v;
					// imp[l] += 1;
				}
			}
		// cout<<imp[j]<<" ";
		}
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		// cout<<endl;
		for(int j=i+1;j<=n;j++)
			{
				// cout<<dp[i][j]<<" ";
				ans += dp[i][j];
			}
	}
	cout<<ans<<endl;
	}
	return 0;
}