#include "bits/stdc++.h"
using namespace std;

class UnionFind{
	private: vector<int> szSet,p,rank;
			 int nDisSet;
	public:
		UnionFind(int N){
			rank.assign(N,0); 
			p.assign(N,0);
			szSet.assign(N,1);
			nDisSet  = N;
			for(int i=0;i<N;i++) p[i]=i;
		}	
		int findSet(int i){
			if(p[i] == i) return i;
			return p[i] = findSet(p[i]);
		}
		bool isSameSet(int i,int j){
			return findSet(i) == findSet(j);
		}
		void unionSet(int i,int j){
			if(!isSameSet(i,j)){
				szSet --;
				int x = findSet(i),y = findSet(j);
				if(rank[x] > rank[y]){
					p[y] = x;
					szSet[x] += szSet[y];
				} 
				else {
					szSet[y] += szSet[x];
					p[x] = y;
					if(rank[x] == rank[y]) rank[y]++;
				}
			}
		}
		int numDisjointSets(){
			return nDisSet;
		}
		int sizeOfSet(int i){
			int x = findSet(i);
			return szSet[x];
		}
};

int main(int argc, char const *argv[])
{
	UnionFind x(5);
	x.unionSet(0,1);
	x.unionSet(2,3);
	x.unionSet(0,3);
	cout<<x.findSet(0)<<endl;
	return 0;
}