#include "bits/stdc++.h"
using namespace std;

long long segtree[300001];
long long a[100001];


void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        segtree[node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        segtree[node] = min(segtree[2*node],segtree[2*node+1]);
    }
}
long long query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 999999999999999999;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return segtree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    long long p1 = query(2*node, start, mid, l, r);
    long long p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1,p2);
}

// 7 7
// 3 1
// 2 1
// 6 3
// 4 3
// 5 3
// 7 6
// 7 1 1
// 7 2 3
// 6 1 20
// 5 2 10
// 4 2 3
// 3 2 2
// 2 2 4

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	for(int i=0;i<3*n+14;i++)
	 segtree[i] =99999;
	// build(1,0,n-1);
	int q; cin >> q;
	int c,l,r,v;
     
	while(q--)
	{
		cin >> c >> l >> r;
		if(c==0)
		{
			update(1,0,n-1,l,r);
		}		
		else
		{
			cout << query(1,0,n-1,l,r) << endl;
		}
	}
	return 0;
}