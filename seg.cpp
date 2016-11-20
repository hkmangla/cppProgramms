#include "bits/stdc++.h"
using namespace std;
#define gc getchar
int tree[90000];

void build(int a, int b, int node){
	if(a > b) return;
	if(a==b) {
		tree[node] = 0;
		return;
	}
	int mid = (a+b)/2;
	build(a,mid,node*2);
	build(mid+1,b,node*2+1);
	tree[node] = tree[node*2] + tree[node*2 + 1];
}

int query(int a, int b, int i, int j, int node){
	if(a > b || a > j || b < i) return 0;
	if(a>=i && b<=j) {
		return tree[node];
	}
	int q1 = query(a,(a+b)/2, i, j, node*2);
	int q2 = query((a+b)/2+1, b, i, j, node*2+1);

	return q1+q2;
}

void update(int a, int b, int x, int node){
	if(x < a || x > b) return ;
	tree[node] += 1;
	if(a !=b ){
		int mid = (a+b)/2;
		update(a,mid,x,node*2);
		update(mid+1,b,x,node*2+1);
	}

}
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
class str{
public:
	int type,value,l,r,idx;
	str(int t, int values, int ls, int rs,int idxx ) ;

	bool operator<(const str &n){
		if(value != n.value) return value > n.value;
		else return type > n.type;
	}

};
str::str(int t, int values, int ls, int rs,int idxx )
	{
		type = t; value = values; l = ls; r = rs; idx = idxx;
	}
//Main function for the program 
int main(int argc, char const *argv[])
{

	vector < str > data;
	int n; n = read_int();
	int x;
	for(int i=0;i<n;i++) {
		x = read_int();
		str temp(0,x, -1, -1, i);
		data.push_back(temp);
	}
	build(0,n-1,1);
	int q; q= read_int();
	int q_index = 0;
	while(q--){
		int i,j,k;
		i = read_int();
		j = read_int();
		k = read_int();
		str temp(1,k,i,j,q_index);
		data.push_back(temp);
		q_index ++;
	}
	sort(data.begin(),data.end());
	int ans[q_index+1];
	for(int i = 0;i<data.size();i++){
		if(data[i].type){
			ans[data[i].idx] = query(0,n-1,data[i].l-1,data[i].r-1, 1);
		}
		else{
			update(0,n-1,data[i].idx, 1);
		}
	}
	for(int i=0;i<q_index;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}