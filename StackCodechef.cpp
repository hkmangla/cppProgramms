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
	// ll n;?
	int n;
	cin>>n;
	int a[n];
	vector<int> s;
	for(int i=0;i<n;i++)
	{	
		cin>>a[i];
		vector<int>::iterator low;
		low = lower_bound(all(s),a[i]+1);
		// cout<<low-s.begin()<<endl;
		// break;
		if(low!=s.end())
			s[low-s.begin()] = a[i];
		else
			s.push_back(a[i]);
			// tr(s,it)cout<<*it<<" ";
			// cout<<endl;
	}
	cout<<s.size()<<" ";
	tr(s,i)cout<<*i<<" ";
	cout<<endl;
	}
	return 0;
}