#include "bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define x first
#define y second

struct Comparator
{
    bool operator() (const pii a, const pii b) const
    {
    	if(a.y == b.y) return a.x < b.x;
    	else return a.y < b.y;
    }
};

int dist(pii a, pii b){
	return pow(a.x - b.x,2) + pow(a.y-b.y,2);
}
// class LineSweep
// {
// 	vector<pii> Points;
// 	int n;
// public:
// 	LineSweep(int _n, vector<pii> v){
// 		for(int i=0;i<n;i++){
// 			Points.push_back(v[i]);
// 		}
// 		n = _n;
// 		};
// 	int pairWiseshortestDistance(){
// 		sort(Points.begin(), Points.end());
// 		int h = INT_MAX;
// 		set<pii, Comparator> activeSet;
// 		activeSet.insert(Points[0]);
		
// 		int l = 0;
// 		for(int i=1;i<n;i++){
// 			while(l < i and Points[i].x - Points[l].x > h){
// 				activeSet.erase(Points[l]);
// 				l++;
// 			}
// 			for(typeof(activeSet.begin()) it = activeSet.lower_bound({Points[i].x - h, Points[i].y - h});
// 					it != activeSet.end() and Points[i].y + h>=it->y;it++){
// 				h = min(h,dist(Points[i],*it));
// 			}
// 			activeSet.insert(Points[i]);
// 		}
// 		return h;
// 	}
// 	// ~LineSweep();
	
// };

int pairWiseshortestDistance(vector<pii>& Points, int n){
	sort(Points.begin(), Points.end());
	int h = 1000000000;
	set<pii, Comparator> activeSet;
	activeSet.insert(Points[0]);
	int l = 0;
	for(int i=1;i<n;i++){
		while(l < i and Points[i].x - Points[l].x > h){
			activeSet.erase(Points[l]);
			l++;
		}
		for(typeof(activeSet.begin()) it = activeSet.lower_bound({Points[i].x - h, Points[i].y - h});
				it != activeSet.end() and Points[i].y + h >= it->y;it++){
			h = min(h,dist(Points[i],*it));
		}
		activeSet.insert(Points[i]);
	}
	return h;
}
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
	int h = INT_MAX;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			h = min((int)h, (int)(pow(points[i].x - points[j].x, 2)
			 + pow(points[i].y - points[j].y, 2)));
		}
	}
	// LineSweep a(n,points);
	cout<<pairWiseshortestDistance(points, n)<<endl;
	cout<<h<<endl;
	return 0;
}