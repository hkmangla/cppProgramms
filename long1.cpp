#include "bits/stdc++.h"
using namespace std;
long long dp[201];
#define ll long long
#define mod 1000000007

int main(int argc, char const *argv[])
{
    int t; scanf("%d",&t);
    while(t--){
        ll m,n,W,P,x,y;
        cin>>m>>n>>W>>P>>x>>y;
        ll dp[m][n];
        memset(dp,0,sizeof(dp));
        dp[0][0] = x;
        dp[m-1][n-1] = y;
        int last[m][n];
        while(W--){   
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                last[i][j] = dp[i][j];
                dp[i][j] = 0;
                }
             }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    for(int ii=0;ii<3;ii++){
                        for(int jj=0;jj<3;jj++) {
                            if(i+ii-1 < 0 or i+ii-1 >= m or j+jj-1 < 0 or j+jj-1 >= n) continue;
                            dp[i+ii-1][j+jj-1]+=last[i][j];
                            dp[i+ii-1][j+jj-1] %= P;
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
    }
}