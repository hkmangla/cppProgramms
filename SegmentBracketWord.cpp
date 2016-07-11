#include<iostream>
using namespace std;
//char arr[30002];
char tree[100001];
int lazy[100001];
int final;
/**
 * Build and init tree
 */
void build_tree(int node,int last, int a, int b,char arr[]) {
  	if(a > b) return; // Out of range
  	
  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		     if(a==last)
		     final = node;
		return;
	}
	
	build_tree(node*2,last, a, (a+b)/2,arr); // Init left child
	build_tree(node*2+1,last, 1+(a+b)/2, b,arr); // Init right child
	
	if(tree[node*2] == tree[node*2+1])
	tree[node] = tree[node*2]; // Init root value
	
	if(tree[node*2] != tree[node*2+1])
	{
	if(tree[node*2]=='('&&tree[node*2+1]==')')	
	tree[node] = '0';
	if(tree[node*2]==')'&&tree[node*2+1]=='(')	
	tree[node] = '1';
	 if(tree[node*2]!='0'&&tree[node*2+1]=='0')
	tree[node] = tree[node*2];
	 if(tree[node*2+1]!='0'&&tree[node*2]=='0')
	tree[node] = tree[node*2+1];
	}
}
void update(int node,int a,int b,int range)
{
	if(range>b||range<a)return;
	int mid = (a+b)/2;
	if(a==b&&a==range)
	{
		if(tree[node]=='(')
		tree[node]=')';
		if(tree[node]==')')
		tree[node]='(';
	}
	if(range<=mid)
	update(node*2,a,mid,range);
	if(range>mid)
	update(node*2,mid+1,b,range);
}
int main()
{
	int t=10,f=1;
	while(t--)
	{
		int n;cin>>n;
		char a[30001];
		cin>>a;
		build_tree(1,n-1,0,n-1,a);
		for(int i=1;i<17;i++)
		cout<<tree[i]<<" ";
		cout<<final<<endl;
		int m;cin>>m;
		while(m--)
		{
			int q;cin>>q;
			if(q>0)
			update(1,0,n-1,q);
			for(int i=1;i<17;i++)
		     cout<<tree[i]<<" ";
		}
	}
}
