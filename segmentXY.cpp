#include "bits/stdc++.h"
using namespace std;

int tree[400000];

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

void update(int a, int b, int x,int k, int node){
	if(x < a || x > b) return ;
	tree[node] += k;
	if(a !=b ){
		int mid = (a+b)/2;
		update(a,mid,x,k,node*2);
		update(mid+1,b,x,k,node*2+1);
	}

}


class str{
public:
	int type,value,ut,l,r,idx;
	str(int t, int values,int ut_ ,int ls, int rs,int idxx ) ;

	bool operator<(const str &n){
		if(value != n.value) return value > n.value;
		else return ut > n.ut;
	}
	void display(){
		cout<<type<<" "<<value<<" "<<ut<<" "<<l<<" "<<r<<" "<<idx<<endl;
	}

};
str::str(int t, int values, int ut_,int ls, int rs,int idxx )
{
	type = t; value = values; ut = ut_; l = ls; r = rs; idx = idxx;
}

void solve(int n, int x1, int y1, int x2, int y2){

}
int ans[100001];
int main(int argc, char const *argv[])
{
	int n; cin>>n;
	int max_x=0,max_y = 0;
	vector< pair<int,int>> check;
	vector< str > ver;
	vector< str> hor;
	for(int i=0;i<n;i++){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		check.push_back({x1,y1});
		check.push_back({x2,y2});
		max_x = max(x1,max_x);
		max_x = max(x2,max_x);
		max_y = max(y1,max_y);
		max_y = max(y2,max_y);
		if(x1 == x2){
			str temp(1,x1,0, min(y1,y2), max(y1,y2), i);
			ver.push_back(temp);
			str temp3(0,max(y1,y2),1, -1,-1, x1);
			hor.push_back(temp3);
			str temp2(0,min(y1,y2),-1, -1,-1, x1);
			hor.push_back(temp2);
			
		}
		else{
			str temp(0,max(x1,x2),1,-1, -1, y1);
			ver.push_back(temp);
			str temp2(0,min(x1,x2),-1,-1, -1, y1);
			ver.push_back(temp2);
			str temp3(1,y1,0, min(x1,x2), max(x1,x2), i);
			hor.push_back(temp3);
		}
	}
	sort(check.begin(),check.end());
	set< pair<int,int> > dcheck;
	for(int i=1;i<check.size();i++){
		if(check[i].first == check[i-1].first && check[i].second == check[i-1].second)
			dcheck.insert(check[i]);
	}
	build(1, max(max_x,  max_y), 1);
	sort(ver.begin(), ver.end());
	long long answer = 0;
	for(int i=0;i<ver.size();i++){
		// ver[i].display();
			if(ver[i].type){
			ans[ver[i].idx] = query(1,max(max_x,max_y),ver[i].l, ver[i].r, 1);
			for(set<pair<int,int>>::iterator it=dcheck.begin();it!=dcheck.end();it++)
			{
				if(it->first == ver[i].value){
					if(it->second == ver[i].l) ans[ver[i].idx] --;
					if(it->second == ver[i].r) ans[ver[i].idx] --;
				}
			}
			answer += ans[ver[i].idx];
		}
		else{
			update(1,max(max_x,max_y),ver[i].idx, ver[i].ut,1);
		}
	}
	build(1, max(max_x,  max_y), 1);
	sort(hor.begin(),hor.end());
	for(int i=0;i<hor.size();i++){
		if(hor[i].type){
			ans[hor[i].idx] = query(1,max(max_x,max_y),hor[i].l, hor[i].r, 1);
			for(set<pair<int,int>>::iterator it=dcheck.begin();it!=dcheck.end();it++)
			{
				if(it->second == hor[i].value){
					if(it->first == hor[i].l) ans[hor[i].idx] --;
					if(it->first == hor[i].r) ans[hor[i].idx] --;
				}
			}
		}
		else{
			update(1,max(max_x,max_y),hor[i].idx, hor[i].ut,1);
		}
	}
	
	cout<<answer<<endl;
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}