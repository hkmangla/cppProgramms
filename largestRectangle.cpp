#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pii pair<int, int>
#define LL_MIN -100000000000000000
vector< pii> tree(300000);

void build(int node, int start, int end, long long a[]){
	if(start > end ) return;
	if(start == end) {
		tree[node] = {a[start],start};
		return;
	}
	build(2*node, start , (start+end)/2, a);
	build(2*node+1,(start+end)/2 + 1,end, a);
	if(tree[node*2].f < tree[node*2+1].f)
	{
			tree[node] = {tree[node*2].f,tree[node*2].s};
	}
	else
		tree[node] = {tree[node*2+1].f,tree[node*2+1].s};
}

pii query(int a, int b, int i, int j, int node){
	if(a > b || a > j || b < i) return {INT_MAX,INT_MAX};
	if(a >= i && b <= j) return tree[node];
	pii q1 = query(a,(a+b)/2,i,j,node*2); 
	pii q2 = query((a+b)/2+1, b, i, j, node*2+1);
	if(q1.f < q2.f) return q1;
	else return q2;

}

long long maxAreaUtil(long long a[], int n, int l , int r){
	if(l > r) return LL_MIN;
	if(l==r) return a[l];
	pii midp = query(0,n-1,l,r,1); int mid = midp.s;
	return max(max(maxAreaUtil(a,n,l,mid-1), maxAreaUtil(a,n,mid+1,r)),(r-l+1)*a[mid]);
}

long long maxArea(long long a[], int n){
	build(1,0,n-1,a);
	return maxAreaUtil(a,n,0,n-1);
}
long long a[100001];
int main(int argc, char const *argv[])
{
	int n; 
	while(1){
		cin>>n;
		if(n == 0) return 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<maxArea(a,n)<<endl;

	}
	return 0;
}