#include "bits/stdc++.h"
using namespace std;

struct node{
	node* left;
	node* right;
	int val;
	node(){};
	node(node* _left,node* _right,int _val){
		left = _left; right = _right;
		val = _val;
	}
};

int arr[10001];
void build(node* nd,int a, int b){
	if(a > b) return;
	if(a == b){
		nd->val = arr[a];
		return;
	}
	node* nd1 = new node(NULL,NULL,0);
	node* nd2 = new node(NULL,NULL,0);
	nd->left = nd1;
	nd->right = nd2;
	build(nd1,a,(a+b)/2);
	build(nd2,(a+b)/2 + 1, b);
	nd->val = nd1->val + nd2->val;
}

void up(node* nd, int idx,int newVal,int a, int b){
	if(a>b or idx < a or idx > b) return;
	if(a==b){
		nd->val = newVal;
		return;
	}
	up(nd->left,idx,newVal, a,(a+b)/2);
	up(nd->right,idx,newVal, (a+b)/2+1,b);
	nd->val = nd->left->val + nd->right->val;
}

int qry(node* nd,int l,int r,int a,int b){
	if(l>r or a > b or r<a or l>b) return 0;
	if(l<=a and b<=r) return nd->val;
	int q1 = qry(nd->left,l,r,a,(a+b)/2);
	int q2 = qry(nd->right,l,r,(a+b)/2 + 1,b);
	return q1+q2;
}
void pri(node* it){
	cout<<it->val<<" ";
	if(it->left != NULL) pri(it->left);
	if(it->right != NULL) pri(it->right);
}

int main(int argc, char const *argv[])
{
	node* root = new node(NULL,NULL,0);
	int n; cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	build(root,0,n-1);
	int q;cin>>q;
	while(q--){
		int qt,x,y; cin>>qt>>x>>y;
		if(qt){
			up(root,x,y,0,n-1);
		}
		else cout<<qry(root,x,y,0,n-1)<<endl;
	}
	return 0;
}