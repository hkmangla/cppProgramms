/**
 * In this code we have a very large array called arr, and very large set of operations
 * Operation #1: Increment the elements within range [i, j] with value val
 * Operation #2: Get max element within range [i, j]
 * Build tree: build_tree(1, 0, N-1)
 * Update tree: update_tree(1, 0, N-1, i, j, value)
 * Query tree: query_tree(1, 0, N-1, i, j)
 */

#include<iostream>
#include<algorithm>
using namespace std;

#include<string.h>
#include<math.h> 

#define N 100002
#define MAX 1000001 // Why? :D
#define inf 0x7fffffff
#define M 1000000007
#define ll long long int
ll arr[N];
ll tree[MAX];
ll lazy[MAX];

/**
 * Build and init tree
 */
void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
	
	tree[node] = tree[node*2] + tree[node*2+1]; // Init root value
	tree[node]%=M;
}

/**
 * Increment elements within range [i, j] with value value
 */
void query2(int node, int a, int b, int i, int j, int value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] *= lazy[node]; // Update it
        tree[node] %= M;
		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] *= value;
            tree[node]%=M;
		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	query2(node*2, a, (a+b)/2, i, j, value); // Updating left child
	query2(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = tree[node*2] + tree[node*2+1];
	tree[node]%=M; // Updating root with max value
} 
void query1(int node, int a, int b, int i, int j, int value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it
        tree[node] %= M;
		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;
            tree[node]%=M;
		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	query1(node*2, a, (a+b)/2, i, j, value); // Updating left child
	query1(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = tree[node*2] + tree[node*2+1];
	tree[node]%=M; // Updating root with max value
}
void query3(int node, int a, int b, int i, int j, int value) {
  
  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] == lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}
  
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] == value;
            tree[node]%=M;
		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	query3(node*2, a, (a+b)/2, i, j, value); // Updating left child
	query3(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = tree[node*2] + tree[node*2+1];
	tree[node]%=M; // Updating root with max value
}
/**
 * Query tree to get max element value within range [i, j]
 */
int query4(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return -inf; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it
        tree[node]%=M;
		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	ll q1 = query4(node*2, a, (a+b)/2, i, j); // Query left child
	ll q2 = query4(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	ll res = q1 + q2; // Return final result
	res%=M;
	return res;
}

int main() {
	ll Na,q;
	cin>>Na>>q;
	for(int i = 0; i < Na; i++) cin>>arr[i];

	build_tree(1, 0, Na-1);

	memset(lazy, 0, sizeof lazy);
	while(q--)
    {int qq,l,r,v;    
	cin>>qq>>l>>r;
	if(qq==1)
	{
		cin>>v;
	query1(1, 0, Na-1, l, r, v); // Increment range [0, 6] by 5
	}
	if(qq==2)
	{cin>>v;
	query2(1, 0, Na-1, l, r, v); // Incremenet range [7, 10] by
    }
    if(qq==3)
	{cin>>v;
	query3(1, 0, Na-1, l, r, v); // Incremenet range [7, 10] by
    }
    if(qq==4)
	cout << query4(1, 0, Na-1, l, r) << endl; // Get max element in range [0, N-1]
   }
    return 0;
}
