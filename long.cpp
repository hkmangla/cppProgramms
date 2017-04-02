#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pii pair<ll,ll>
ll dp[100001];
ll n;
ll a[100001],b[100001],c[100001];

void getInput(){
    scanf("%lld",&n);
  	for(int i=0;i<n-1;i++) scanf("%lld", &a[i]);
  	for(int i=0;i<n-2;i++) scanf("%lld", &b[i]);
  	for(int i=0;i<n-3;i++) scanf("%lld", &c[i]);  
}

ll disl(int l, int m){
  dp[m] = 0;
  int sum = 0;
  for(int j = m-1;j>=l;j--){
      ll ans1,ans2,ans3;
          ans3 = ans2 = ans1 = LLONG_MAX;
          if(j+1 <= m){
            ans1 = a[j] + dp[j+1];
          }
          if(j+2 <= m){
          ans2 = b[j] + dp[j+2];
          }
          if(j+3 <= m){
            ans3 = c[j] + dp[j+3];
          }
          dp[j] = min(ans1, min(ans2,ans3));
          sum += dp[j];
  }
  return sum;    
}

ll disr(int r, int m){
  dp[m] = 0;
  int sum = 0;
  for(int j = m+1;j<=r;j++){
      ll ans1,ans2,ans3;
          ans3 = ans2 = ans1 = LLONG_MAX;
          if(j-1 >= m){
            ans1 = a[j-1] + dp[j-1];
          }
          if(j-2 >= m){
          ans2 = b[j-2] + dp[j-2];
          }
          if(j-3 >= m){
            ans3 = c[j-3] + dp[j-3];
          }
          dp[j] = min(ans1, min(ans2,ans3));
          sum += dp[j];
  }
  return sum;
}

ll bruteForce(int l, int r){
       ll sum = 0;
      for(int i=l;i<=r;i++){
        sum += disr(r,i);
    }
    return sum;
}

ll g(int l, int r, int m){
    return disl(l,m) + disl(l,m-1) + disr(r,m) + disr(r,m+1);
}

ll f(int l, int r, int m){
    vector<pii> xjyj;
    ll dp1[3][r-l+1];
  for(int i =0;i<3;i++){ 
    dp1[i][m+i-1] = 0;
    for(int j=m+i;j<=r;j++)
      {
        ll ans1,ans2,ans3;
          ans3 = ans2 = ans1 = LLONG_MAX;
          if(j-1 >= m+i-1){
            ans1 = a[j-1] + dp1[i][j-1];
          }
          if(j-2 >= m+i-1){
          ans2 = b[j-2] + dp1[i][j-2];
          }
          if(j-3 >= m+i-1){
            ans3 = c[j-3] + dp1[i][j-3];
          }
          dp1[i][j] = min(ans1, min(ans2,ans3));
      }
    }
    // for count d(m-1,j) and d(i,m-1) repetitions
    for(int i=m+1;i<=r;i++){
      xjyj.push_back({dp1[0][i] - dp1[1][i], dp1[0][i] - dp1[2][i]});
    }
    sort(xjyj.begin(), xjyj.end());
}
ll solve(int l, int r){
    if(r < l) return 0;
    if(r - l < 9) return bruteForce(l,r);
    int m = (l+r)/2;
    return solve(l,m-2) + solve(m+2,r) + f(l,r,m) + g(l,r,m);
}

int main(int argc, char const *argv[])
{
  int t; scanf("%d",&t);
  while(t--){
    getInput();

  	printf("%lld\n",bruteForce(0,n-1));
  }

  return 0;
}