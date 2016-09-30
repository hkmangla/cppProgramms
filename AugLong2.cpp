#include <iostream>
#include <vector>
using namespace std;
// vector<int> cost;
int main(){
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		int minr1[n+1],minl2[n+1],minl1[n+1],minr2[n+1];
		int cost[n];
		for(int i = 0;i < n; i++){
			cin>>cost[i];
			minr1[i] = 0;minl1[i] = 0;minl2[i] = 0;minr2[i] = 0;
		}
		int start, end;
		cin>>start>>end;
		start--; end--;
		int sumLeft = 0,sumRight = 0;
		for(int i=start;i<end;i++){
			sumLeft += cost[i];
			if(i == start) minl2[i] = min(0,sumLeft);
			else minl2[i] = min(minl2[i-1], sumLeft);
			// cout<<minl2[i]<<" ";
		}
		// cout<<endl;
		for(int i = end;i< start+n;i++){
			sumRight += cost[i%n];
			if(i == end) minl1[i%n] = min(sumRight,0);
			else minl1[i%n] = min(sumRight,minl1[(i-1)%n]);
			// cout<<minl1[i%n]<<" ";
		}
		// cout<<endl;
		int tmpSum = 0;
		for(int i = end-1;i>=start;i--){
			tmpSum += cost[i];
			if(i == end-1) minr2[i] = min(0,tmpSum);
			else minr2[i] = min(minr2[i+1], tmpSum);
			// cout<<minr2[i]<<" ";
		}
		// cout<<endl;
		tmpSum = 0;
		for(int i = start+n-1; i>=end; i--){
			tmpSum += cost[i%n];
			if(i == start+n-1) minr1[i%n] = min(0,tmpSum);
			else minr1[i%n] = min(minr1[(i+1)%n], tmpSum);
			// cout<<minr1[i%n]<<" ";
		}
		int minl = min(minl2[end-1], minr2[start]), minr = min(minl1[(start-1+n)%n],minr1[end]);
		for(int i = start;i<end-1;i++){
			minl = min(minl,minl2[i]+minr2[i+1]);
		}
		for(int i = end; i< start+n-1;i++){
			minr = min(minr,minl1[i%n]+minr1[(i+1)%n]);
		}
		// cout<<minr<<" "<<minl<<endl;
		cout<<min(2*minr + sumLeft, 2*minl + sumRight)<<endl;
	}
}