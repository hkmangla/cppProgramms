#include < bits/stdc++.h>
using namespace std;
 
unordered_map <long long , int> grundy,hold;
int ret_grundy(long long n)
{
  if(hold[n]==1)
    return grundy[n];
  if(n==0) return 0;
   int a1,a2,a3,a4,a5;
   a1 = ret_grundy(n/2);
   a2 = ret_grundy(n/3);
   a3 = ret_grundy(n/4);
   a4 = ret_grundy(n/5);
   a5 = ret_grundy(n/6);
   for(int i = 0;;i++)
    {
      if(i!=a1 and i!=a2 and i!= a3 and i!=a4 and i!=a5)
        { 
           grundy[n] = i; break;
        }
    }
  hold[n] = 1;
 return grundy[n];
}
 
int main()
{
  ios_base :: sync_with_stdio(false);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int t; cin >> t;
  while(t--)
  {
    int n; cin >> n;
    long long x;
    int ans = 0;
    for(int i=0;i<n;i++)
     {
       cin >> x;
       x = ret_grundy(x);
       ans = ans ^ x;
     }
     if(ans)
       printf("Henry\n");
     else
       printf("Derek\n");
    }
  return 0;
} 