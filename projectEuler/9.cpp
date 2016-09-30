#include<bits/stdc++.h>
using namespace std;
bool isPrime[10000001];
vector <int> v;
void sieve(long long  N) 
{
    for(int i = 0; i <= N;++i) 
    {
        isPrime[i] = true;
    }

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i * i <= N; ++i) 
    {
         if(isPrime[i] == true) 
         {
             for(int j = i * i; j <= N ;j += i)
                 isPrime[j] = false;
        }
    }

long long add = 0;
    for(int i=2;i<=N;i++)
    	{
    		if(isPrime[i])
    			{
    				v.push_back(i);
    				add+=i;
    			}
    }
    //cout << add << endl;
}

bool checkPalin(int n){
	std::vector<int> v;
	while(n!=0){
		v.push_back(n%10);
		n/=10;
	}
	for(int i = 0; i < v.size()/2; i++){
		if(v[i]!=v[v.size() -1-i])
			return false;
	}
	return true;
}
long long int gcd(long long int a, long long int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}
long long int lcm(long long int a, long long int b){
	return (a*b)/gcd(a,b);
}
bool checkPythagoras(int a,int b,int c){
    if(((a*a) + (b*b)) == (c*c))
        return true;
    else
        return false;
}
int main(){
    for(int i = 1;i<1000;i++){
        for(int j = i+1;j<1000;j++){
            if((1000-i-j) > j && checkPythagoras(i,j,1000-i-j))
                cout<<i<<" "<<j<<" "<<1000-i-j<<" "<<i*j*(1000-i-j)<<endl;
        }
    }
}