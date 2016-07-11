#include<iostream>
#include<math.h>
using namespace std;
long long int tree[1000001];
long long int lazy[1000001];
void build_seg_tree(int node, int a,int b)
{
	if(a>b)return;
	if(a==b){
		tree[node]=arr[a];
		return;
	}
	build_seg_tree(node*2,a,(a+b)/2);
	build_seg_tree(node*2+1,1+(a+b)/2,b);
	tree[node]= max(tree[node*2],tree[node*2+1]);
}

