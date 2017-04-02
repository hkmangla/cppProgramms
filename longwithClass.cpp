#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define x first
#define y second

class LineSweep
{
	int n;
	vector<pii> Points;
public:
	LineSweep(int _n, vector<pii> v){
		for(int i=0;i<n;i++){
			Points.push_back(v[i]);
		}
		n = _n;
		};
	int pairWiseShortestDistance(){
		sort(Points.begin(), Points.end());
		int shortestDistance = INT_MAX;
		for(int i=1;i<n;i++){
			for(int j=i-1;j>=0;j--){
				if()
			}
		}
	}
	~LineSweep();
	
};
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<pii> points;
	int x,y; 
	for(int i=0;i<n;i++){
		cin>>x>>y;
		points.push_back({x,y});
	}
	return 0;
}