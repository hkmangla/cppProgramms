
#include<bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef long long int LL;
 
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
 
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define TRACE
 
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr<<name<<" : "<<arg1<<endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
  const char* comma=strchr(names+1,',');
  cerr.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...)
#endif
int DIG[10];
int A[300];
int *ANS=A+150;
int digits(int v)
{
  int ret=0;
  while(v) 
    DIG[ret++]=v%10,v/=10;
  return ret;
}
int main()
{
  int T;si(T) ;
 while(T--) 
 {
   int k,i,j;si(k);
   int L=digits(k);
   int st=0,en=1,cnt=1;
   for(i=1;i<=L;i++)
   {
     for(j=0;j<DIG[L-i];j++) ANS[st--]=cnt+i+j;
      cnt+=i;
      for(j=0;j<i;j++) ANS[st--]=--cnt;
      cnt+=i+DIG[L-i];
      for(j=9;j>=0;j--) ANS[en++]=cnt+j;
      cnt+=10;
     // trace(st,en) ;
             }
   dout(en-(st+11));
   for(i=st+1;i<en-10;i++)
     printf("%d ",ANS[i]);
   printf("\n");
 }
 return 0;
}
 