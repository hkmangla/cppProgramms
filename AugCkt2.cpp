#include "bits/stdc++.h"
using namespace std; 
long long solve(int a[], int n, int k){
    multiset<int> elem[n]; long long dp[n],ans = 0;
    for(int i=0;i<n;i++){
        if(a[i] < k) elem[i].insert(a[i]);
        for(int j =0;j<=i;j++){
            if(a[i] > a[j]){
                int search = k - a[i];
                int pos = (lower_bound(elem[j].begin(), elem[j].end(), search));
                ans += pos;
            }
        }
        // ans += dp[i];
        // cout<<a[i]<<" --> "<<dp[i]<<endl;
    }
    return ans ;
}

/* Driver program to test above function */
int main()
{
    int n, k; cin>>n>>k;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    printf("%lld\n", solve( arr, n, k ));
    return 0;
  }