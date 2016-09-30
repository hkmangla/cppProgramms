#include<bits/stdc++.h>
using namespace std;

// long long n;
long long totaSum;
long long mat[2005][2005];
long long stripSum[2001][2001];

long long Tricky(long long k, long long n)
{
	// cout<<n<<" "<<k<<endl;
	 // long long ans = 0;
   if (k >= n) return totaSum;
   for (long long j=0; j<n; j++)
   {
       long long sum = 0;
       for (long long i=0; i<k; i++)
          sum += mat[i][j];
       stripSum[1][j] = sum;
       for (long long i=1; i<n-k+1; i++)
       {
            sum += (mat[i+k-1][j] - mat[i-1][j]);
            stripSum[i][j] = sum;
       }
   }
   // long long x =0 , y =0;
   long long ans = 0;
   for (long long i=0; i<n-k+1; i++)
   {
      long long sum = 0;
      for (long long j = 0; j<k; j++)
           sum += stripSum[i][j];
      // cout << sum << "  ";
      if(ans < sum)	ans = sum;
       // sum = 0;
      for (long long j=1; j<n-k+1; j++)
      {
         sum += (stripSum[i][j+k-1] - stripSum[i][j-1]);
         if(ans < sum) 	ans = sum;
         // cout<<sum<<" ";
      } 
      // cout<<endl;
   }
   // cout<<ans<<" "<<len<<endl;
   return ans;
}



int main(int argc, char const *argv[])
{
	long long N,l,n = 0;
	cin>>N>>l;
	// long long a[20001][20001];
	for(long long i=0;i<N;i++){
		long long x,y,z;
		cin>>x>>y>>z;
		// x--;y--;
		totaSum += z;
		mat[x][y] = z;
		n = max(n,y);
		n = max(n,x);
	}
	n ++;
	// for(long long i= 0;i<n;i++
	// cout<<n<<endl;
	long long ANS = 0, len;
	for(long long i=0;i<=l;i++){
	long long ans = Tricky(l-i,n);
	// cout<<l-i<<" "<<ans<<endl;
	if(ANS <= ans){
		ANS = ans;
		len = l-i;
	}
	else{
		break;
	}		
	}
	cout<<ANS<<" "<<len<<endl;
	return 0;
}