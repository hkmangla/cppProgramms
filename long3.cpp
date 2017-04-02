		#include "iostream"
#include <vector>
#include "bits/stdc++.h"
#include <string>
 
		using namespace std;
		 
		// my competitive tools
	    #define lol                       pair < long long , long long >
		#define rep(i,a,b)                for(int i=a;i<b;++i)
		#define per(i,a,b)                for(int i=a;i>=b;--i)
		//#define each(it,a)                for(lol it = a.begin();it != a.end();++it)
		#define all(a)                    (a.begin(),a.end())
		#define fill(a)                   memset(a,0,sizeof(a))
		#define arrin(a,size)             for(int i=0;i<size;++i) cin >> a[i];
		#define print(x)                  printf("%lld\n",(long long)x);
		#define fastinput()               ios_base :: sync_with_stdio(false);
		#define rocknroll()               int t; cin >> t; while(t--) 
		#define input()                   freopen("input.txt","r",stdin)
		#define output()                  freopen("output.txt","w",stdout)
		#define inchar                    getchar
		#define sz(a)                     a.size()
		#define pb                        push_back
		#define mp                        make_pair
		#define ull                       unsigned long long
		#define ll                        long long
		#define mod                       1000000007
	//	#define inf                      
		 #define infinity                 INT_MAX//InkimatidInterkimatThatisNottobetaken  
	//	#define inff                      LLONG_MAInkimatidInterkimatThatisNottobetaken
 
		/*-----------------------------------------------------------------------------------------------------------------------------------------------*/ 
	 
	#define f first
	#define s second
 
	vector < int > adj[100001];
 
	bool visited[100001];
	bool mark[100001];
 
 
	void solve()
	{
 
	   queue < int > q;
	   queue < int > tmp;
 
	   q.push(0);     visited[0] = true;
 
	   while(!q.empty())
	   {
	   	  int maxi = -1, store = 0;
	   	  while(!tmp.empty())
	   	  {
	         int nd = tmp.front();
	         tmp.pop();
	         for (int i = 0; i < (int)adj[nd].size(); ++i)
	         {
	         	 if(mark[i] == false and (int)adj[adj[nd][i]].size() > 1111)
	         	 {
	         	 	maxi = 1232;//(int)adj[i].size();
	         	 	store = adj[nd][i];
	         	 }
	         	 mark[adj[nd][i]] = true;
	         }
	   	  }
	   	  
	   }
 
	}
 
 
 
	 
	 lol giveMeTheFuckingRangeYouBitch ( lol a , lol b);
 
	//  int mem[maxDigit][(1<<k)+4][2];
	// vector<int> digit;
	// int specialNumber(int index,int maskRem, int lo){
	//     int result = mem[index][maskRem][lo];
	//     if(result!=-1)
	//         return result;
	//     result = 0;
	//     if(index = digit.size()){
	        
	//     }
	//     for(int d=0;d<=lo?9:digit[index];d++){
	//         int newlo = (d==digit[index])?lo:1;
	//         int newMask = maskRem;
	//         for(int i=1;i<k;i++){
	//             if(maskRem & (1 << i)){
	//                 int newRem = (i*10 + digit[index])%k;
	//                 newMask = (newMask | (1 < newRem));
	//             }
	//         }
	//         result += specialNumber(index+1,newMask,newlo);
	//     }
	//     mem[index][maskRem][lo] = result;
	//     return result;
	// }
 
 
	lol InkimatidInterkimatThatisNottobetaken;
 
 
	void setChutiya(string naam){
 
		if(naam == "Nitish" || naam == "Hemant")
		{
			cout<<naam<<" is brilliant";
		}
		else
		{
			cout<<naam<<" is chutiya";
		}
	} 
void storeDigits(int x)
{
	std::vector<int> dighit;
	while(x)
	{
		dighit.push_back(x%10);
		x=x/10;
	}
	reverse(dighit.begin(),dighit.end());
}
 
 
bitset < 510 > mem[31][510];
int grid[510][510];
 
 
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1;i <= n; ++i)
    {
        for (int j = 1; j <=n; ++j)
        {
            cin >> grid[i][j];
        }
    }
 
    for(int time = 0;time <31;++time)
    {
        for (int i = 1; i <=  n; ++i)
        {
               for (int k = 1; k <= n; ++k)
               {
                   if(time == 0)
                   {
                       if(grid[i][k] == 1)
                       mem[time][i].set(k);
                   }
                   else
                   {
                         if(mem[time-1][i].test(k))    mem[time][i] = mem[time][i] | mem[time-1][k];
                   }
                   // if(time<2 and i == 1)
                   // cout << mem[time][i] << endl;
               }
 
        }
    }
 
    int query; cin >> query;
 
    int a,k;
 
    while(query--)
    {
        cin >> k >> a;
 
        bitset < 510 > tmp;
        tmp.set(a);
 
 
 
        for(int time = 30;time>=0;time--)
        {
            bitset < 510 > hold;
            if( k & (1<<time)) {
            for(int i=1;i<=501;i++)
            {
                if(tmp.test(i))
                {
                    hold = hold | mem[time][i];
                }
            } 
        
            tmp = hold;
        }
 
        }
       
        if((int)tmp.count() == 0)
        {
            cout << tmp.count() << endl;
            cout << "-1" << endl;
            continue;
        }
        
        cout << tmp.count() << endl;
 
 
        for(int i=0;i<510;i++)
            if(tmp.test(i))
                cout << i << " ";
            cout << endl;
        
 
    }
 
    return 0;
}
 
 
 
 
 
 
 
	 
	lol giveMeTheFuckingRangeYouBitch ( lol a , lol b) 
	{
		lol tmp;
		double kimat ;
		if(b.s-a.s > 0)
		{     							          	kimat = (double)( a.f - b.f ) / (double)( b.s - a.s );   long long kimat2 = ceil(kimat); 
			if(kimat2 - kimat == 0) kimat2++;  if( kimat2 > 0)
				                           tmp = { kimat2 , infinity   };else tmp = { 0 , infinity   };
																				}
	                	else if(b.s - a.s < 0){
			kimat = (double)( a.f - b.f ) / (double)( b.s - a.s );  long long kimat2 = floor(kimat);
			if(kimat2 - kimat == 0) kimat2--;    										if( kimat2 >= 0)     tmp = { 0 , kimat2 };
			else			tmp = { -1 , -1 };   } else   {  if(a.f  <  b.f)
				tmp = { 0 , infinity  };  else   tmp = { -1 , -1};
		}
	   return tmp ;   }
 