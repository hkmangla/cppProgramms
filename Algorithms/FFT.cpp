// Name     : Hemant Mangla
// username : hkmangla
// Country  : India
// College  : Deenbandhu Chhotu Ram University of Science and Technology Murthal
// emailId  : hemantmangla78@gmail.com
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,a,b) for(int i=a;i<b;i++)
const int mod = 3*(1 << 18) + 1; //mod should be (2^k)*m + 1 form to do FFT
int n = (1 << 18);


int add(int a,int b){
  int res = a + b;
  if(res >= mod) res -= mod;
  if(res < 0) res += mod;
  return res;
}
int mul(int a,int b){
  return a * (ll)b % mod;
}

int modPow(int a,int b){
  if(b == 0) return 1;
  int tmp = modPow(a,b/2);
  tmp = mul(tmp,tmp);
  if(b%2) return mul(tmp,a);
  else return tmp;
}

vector<int> getEvenPoly(vector<int> &poly){
  vector<int> res;
  for(int i=0;i<poly.size();i+=2) res.push_back(poly[i]);
  return res;
}
vector<int> getOddPoly(vector<int> &poly){
  vector<int> res;
  for(int i=1;i<poly.size();i+=2) res.push_back(poly[i]);
  return res;
}

int eval(vector<int> &poly,int x){
  int res = 0,p = 1;
  for(int it:poly){
    res = add(res,mul(it,p));
    p = mul(p,x);
  }
  return res;
}
vector<int> solve(vector<int> poly,vector<int> p){
  vector<int> ans;
  if(p.size() <= 2){
    rep(i,p.size()) ans.push_back(eval(poly,p[i]));
  }
  else{
    vector<int> pp;
    rep(i,(int)p.size()/2) pp.push_back(mul(p[i],p[i]));
    vector<int> L = solve(getEvenPoly(poly),pp); // gives even polynomial cofficients solution
    vector<int> R = solve(getOddPoly(poly),pp); // gives odd polynomuial cofficients solution
    rep(i,p.size()){
      int idx = ((i < p.size()/2) ? i : (i - p.size()/2));
      ans.push_back(add(L[idx],mul(p[i],R[idx])));  
    }
  }
  return ans;
}
int w = 1000,g=10,k=n;
int main(int argc, char const *argv[])
{
  int nn; cin>>nn;
  nn ++;
  vector<int> poly(nn);
  rep(i,nn) cin>>poly[i];
  vector<int> p;
  rep(i,k) p.push_back(modPow(w,i));
  vector<int> ans(mod);
  // Our mod is 3*(2^k) + 1 form. Since to do FFT our n should be power of 2 show we calculate 
  // it three times using n = (2^k)
  rep(j,3){
    vector<int> newPoly(nn);
    rep(i,nn) newPoly[i] = mul(poly[i],modPow(g,j*i)); // construct new polynomial cofficient according to generator 10
    vector<int> tmp_ans = solve(newPoly,p); // solve for newPoly
    rep(i,p.size()) ans[mul(p[i],modPow(g,j))] = tmp_ans[i];// reconstruct the value of generator 10 from generator 1000 values
  }
  ans[0] = poly[0];
  int q; cin>>q;
  while(q--){
    int x; cin>>x;
    cout<<ans[x]<<endl;
  }
  return 0;
}