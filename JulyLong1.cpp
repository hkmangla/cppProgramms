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
	ll n;
	cin>>n;
	// vector< pair<char int > > village;
	queue<int> lv;
	queue<int> lvi;
	char light[n+1];
	cin>>light;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(light[i] == '1'){
			lv.push(a[i]);
			lvi.push(i);
		}
	}
	int lowx = 0,highx = lvi.front();
	int low  = 0, high = lv.front();
	lv.pop();
	lvi.pop();
	int x;
	long long int  sum = 0;
	for(int i=0;i<n;i++)
	{
		if(i<highx)
			sum = (high - a[0]);
		else
		{
			// cout<<sum<<endl;
			x = i;
			lowx = highx;
			low = high;
			break;		
		}
	}
	if(!lv.empty())
	{

	highx = lvi.front();
	high = lv.front();
	lv.pop();
	lvi.pop();
	}
	int xx = n-1;
	int sum1 = 1000000000;
	for(int i=x;i<n;i++)
	{
		if(i >= lowx && i < highx){
			sum1 = min(sum1,a[i] - low + high - a[i+1]);
			// cout<<i<<" "<<sum1<<endl;
		}
		else{
			if(lv.empty()){
				if(sum1 != 1000000000)
				sum += sum1;
				xx = i;
				break;
			}
			lowx = highx;
			low = high;		
			highx = lvi.front();
			high = lv.front();
			lv.pop();
			lvi.pop();
			sum += sum1;
			sum1 = 1000000000;
			i--;
			// sum += min(a[i] - low, high - a[i]);

		}
	}
		// cout<<xx<<endl;
		sum += (a[n-1] - a[xx]);
	cout<<sum<<endl;
	}
	return 0;
}