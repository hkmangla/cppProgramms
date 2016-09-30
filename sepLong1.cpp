#include "bits/stdc++.h"
using namespace std;
	 
	// my competitive tools

	#define rep(i,a,b)                for(int i=a;i<b;++i)
	#define per(i,a,b)                for(int i=a;i>=b;--i)
	#define each(it,a)                for(auto it = a.begin();it != a.end();++it)
	#define all(a)                    (a.begin(),a.end())
	#define fill(a)                   memset(a,0,sizeof(a))
	#define arrin(a,size)             for(int i=0;i<size;++i) cin >> a[i];
	#define print(x)                  printf("%lld\n",(long long)x);
	#define fastinput()               ios_base :: sync_with_stdio(false);
	#define rocknroll()               int t; cin >> t; while(t--) 
	#define input()                   freopen("input.txt","r",stdin)
	#define output()                  freopen("output.txt","w",stdout)
	#define inchar                    getchar_unlocked
	#define sz(a)                     a.size()
	#define pb                        push_back
	#define mp                        make_pair
	#define ull                       unsigned long long
	#define ll                        long long
	#define mod                       1000000007
	#define inf                       INT_MAX
	#define inff                      LLONG_MAX
	#define X                         first
	#define Y                         second

void generating_prime();
void precal();

bool prime[1000001];int store[1000001];int arr[100001];int marker[500];
  
int main()
{
	generating_prime(); precal();int l,r,o;int t; cin>>t;
	while(t--){

		for(int i=0;i<500;i++)
			marker[i] = 0;

	    int n,m; cin>>n>>m;

	    store[0] =  1;
	    store[1] = 1;

	    for(int i=0;i<n;i++)	cin >> arr[i];

	while(m--)	{
		cin>>o>>l>>r; l--;r--;
		if(o==0){   int i = l;
         while(i<=r)
            {  if(marker[i/500]>=50)  i = i + 500;
                else{ if(i%500 == 0 and (i+500) <r)  marker[i/500]++; arr[i] =( arr[i]/store[arr[i]] );i++;
            	}
            }
		}
		else
		{
			int ans = 0;
 
			int i=l;
 
			while( i%500 !=0 and i<=r)
			{
                   ans = max(ans,store[arr[i]]);            
                   i++;
			}
 
			while(i<=r)
			{
				if( marker[i/500] >= 50 )  {
              	 ans = max(ans,1);
              	 i = i+500;
              }

              else{
              	for(int j=0;j<500 and (i+j) <= r;j++)
              	{
                   ans = max(ans,store[arr[i+j]]);            
               	}  i+=500;
              } }
            cout<<ans<<" ";
		}
	}
}
	return 0;
}
 

void generating_prime()
{for(int i=0;i<=1000000;i++)
		prime[i] = true;
	prime[0] = prime[1] = false;for(int i = 2; i*i < 1000000;i++){for(int j = i; i*j < 1000000;j++){
				prime[i*j]= false;if(store[i*j]==0) store[i*j] = i;}}}

void precal()
{for(int i=0;i<=1000000;i++)
		if( prime[i] )
			store[i] = i;
}
 

 