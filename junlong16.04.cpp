#include<iostream>
#include<stdio.h>
using namespace std;
long long fact[100001];
int mod = 1000000007;
long long power(long long x, long long y){
	if(y == 0)
		return 1;
	long long temp = power(x,y/2);
	if(y%2 == 0)
		return (((temp%mod)*temp)%mod);

	if(y%2 == 1)
		return ((((x*temp)%mod)*temp)%mod);
}
void Sfact(){
			fact[0] = 1;
			fact[1] = 1;
			for(int i = 2; i < 100001;i++){
				fact[i] = (i*fact[i-1])%mod;
			}
}
int main(){
		Sfact();
		int t;scanf("%d",&t);
		while(t--){
			long long l,ans=0,count=0,c,n,k,a;
			scanf("%lld",&n);scanf("%lld",&k);
			for(int i=0;i<n;i++)
			{
				scanf("%lld",&a);
				if(a == 0)
				count++;

			}
			n = n - count;
			if(k%2 == 1)
				c = 1;
			else
				c = 0;
			if(count != 0)
				c = 0;
			if(count == 0)
			{
					for(int i=0;i<=k/2;i++){
					l = (fact[n]*(power((fact[n-c]*fact[c])%mod,(mod-2))))%mod;
					ans = (ans + l)%mod;
					c += 2;
					if(c > n)
						break;
					}
			}
			if(count != 0)
				{
					for(int i=0;i<=k;i++){
					l = (fact[n]*(power((fact[n-c]*fact[c])%mod,(mod-2))))%mod;
					ans = (ans + l)%mod;
					c += 1;
					if(c > n)
						break;
					}
			}

			printf("%lld\n",ans);
		}

}








