#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n,m,x;
		scanf("%d%d",&n,&m);
		set<int> a;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			a.insert(x);
		}
		while(m--){
			cin>>x;
			if(a.count(x))
				printf("YES\n");
			else
			{
				printf("NO\n");
			}
			a.insert(x);
		}
	}
}