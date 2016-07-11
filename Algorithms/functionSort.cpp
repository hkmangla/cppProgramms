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
	vector<pair<pair<double, double> ,double> > line;
	cin>>n;
	for(int i=0;i<n;i++){
		double x,y,z;
		cin>>x>>y>>z;
		line.push_back(make_pair(make_pair(x,y),z));
	}
	tr(line,i){
		int fl = gcd((int)i->first.first, (int)i->first.second);
		double l = fl;
		i->first.first/=l;
		i->first.second/=l;
		i->second/=l;
		// cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
	}
	sort(all(line));
	double x,y,z;
	tr(line,i){
		// cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
		if(i!=line.begin())
		{
		if(x == i->first.first && y == i->first.second && z == i->second)
		{
			i->first.first = -1000000000;
			i->first.second = -1000000000;
			i->second = -1000000000;
		}
		else{
			x = i->first.first;
			y = i->first.second;
			z = i->second;
		}
		}
		if(i==line.begin()){
			x = i->first.first;
			y = i->first.second;
			z = i->second;
		}
	}
	sort(all(line));
	int count = 0,sum = 0, maxSum = -1;
	tr(line,i){
		if((i->first.first + i->first.second + i->second) != -3000000000)
		{
			if(count!=0)
			{
			if(x == i->first.first && y == i->first.second)
			{
				sum ++;
				// cout<<"Sum: "<<sum<<endl;
			}
			else{
				x = i->first.first;
				y = i->first.second;
				sum = 1;
				// z = i->second;
			}
			}
			if(count==0){
				count = 1;
				sum = 1;
				x = i->first.first;
				y = i->first.second;
				// z = i->second;
		}
		}
		// cout<<"x: "<<x<<"y: "<<y<<endl;
		maxSum = max(sum,maxSum);
	}
	cout<<maxSum<<endl;
	}
	return 0;
}