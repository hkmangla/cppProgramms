#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second

vector<pii> tree(300000);
vector<pii> lazy(300000);
void buildUtil(int arr[], int a, int b, int node){
	if(a>b) return;
	if(a==b){
		tree[node] = {arr[a]*arr[a],arr[a]};
		return;
	}
	buildUtil(arr, a,(a+b)/2, node*2);
	buildUtil(arr,(a+b)/2+1,b, node*2+1);
	tree[node] = {tree[node*2].f + tree[node*2+1].f,tree[node*2].s + tree[node*2+1].s};
}

void updateUtil(int a, int b, int i, int j, int diff, int node){
	
	if(lazy[node].f != 0){
		tree[node].f += ((b-a+1)*(lazy[node].f*lazy[node].f) + tree[node].s*2*lazy[node].f);
		tree[node].s += (b-a+1)*lazy[node].f;
		if(a!=b){
			lazy[node*2].f += lazy[node].f;
			lazy[node*2+1].f += lazy[node].f;
		}
		lazy[node].f = 0;
	}

	if(a > j || b < i || a > b) return;
	if(a >= i && b <= j) {
		tree[node].f += ((b-a+1)*(diff*diff) + tree[node].s*2*diff);
		tree[node].s += (b-a+1)*diff;

		if(a!=b){
			lazy[node*2].f += diff;
			lazy[node*2+1].f += diff;
		}
		return;
	}
	updateUtil(a,(a+b)/2, i,j,diff,node*2);
	updateUtil((a+b)/2+1,b,i,j,diff,node*2+1);
	tree[node] = {tree[node*2].f + tree[node*2+1].f, tree[node*2].s + tree[node*2+1].s};
}

int queryUtil(int a, int b, int i, int j, int node){
	if(lazy[node].f != 0){
		
		tree[node].f += ((b-a+1)*(lazy[node].f*lazy[node].f) + tree[node].s*2*lazy[node].f);
		tree[node].s += (b-a+1)*lazy[node].f;

		if(a!=b){
			lazy[node*2].f += lazy[node].f;
			lazy[node*2+1].f += lazy[node].f;
		}
		lazy[node].f = 0;
	}
	if(a > b || a > j || b < i) return 0;
	if(a >= i && b <= j) return tree[node].f;
	int q1 = queryUtil(a,(a+b)/2,i,j,node*2);
	int q2 = queryUtil((a+b)/2+1,b,i,j,node*2+1);
	return q1+q2;
}

void build(int a[], int n){ buildUtil(a,0,n-1,1);}

void update(int n, int i,int j, int diff){	updateUtil(0,n-1,i,j,diff,1); }

int query(int n, int i, int j){	return queryUtil(0,n-1,i,j,1); }

int main(int argc, char const *argv[])
{
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int m; cin>>m;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		build(a,n);
		while(m--){
			int q; cin>>q;
			int i,j; cin>>i>>j;
			i--; j--;
			if(q == 2) cout<<query(n,i,j)<<endl;
			else if (q == 1){
				int diff; cin>>diff;
				update(n,i,j,diff);
			}
			else{
				int x; cin>>x;
			} 
		}
		tree.clear();
		lazy.clear();
	}
	return 0;
}