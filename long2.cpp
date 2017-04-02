#include "bits/stdc++.h"
using namespace std;
int n;
bitset<501> dp[501][40];

int main(int argc, char const *argv[])
{	
	scanf("%d",&n);
	int x;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&x);
			dp[i][0][j] = x;
		}
	}
	for(int t=1;t<33;t++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dp[i][t-1][j]){
					dp[i][t] = dp[i][t] | dp[j][t-1];
				}
			}
		}
	}
	int q; scanf("%d",&q);
	while(q--){
		int id,k; scanf("%d",&k);scanf("%d",&id);
		id --;
		bitset<501> ans;
		ans[id] = 1;
		for(int t=31;t>=0;t--){
			if(k & (1 << t)){	
				bitset<501> new_ans;
				for(int j=0;j<n;j++){
					if(ans[j]){
						new_ans = new_ans | dp[j][t];
					}
				}
			ans = new_ans;
			}
		}
		printf("%d\n", ans.count());
		for(int i=0;i<n;i++) if(ans[i]) printf("%d ",i+1);
		if(ans.count() == 0) printf("-1");
		printf("\n");
	}
	return 0;
}
