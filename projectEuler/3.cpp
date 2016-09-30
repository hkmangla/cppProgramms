#include<iostream>
#include<math.h>
#include<vector>
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

int main(){
	long long int ans = 1,value,n = 600851475143;
	sieve(sqrt(n)+2);
	for(int i=0;i<v.size();i++){
		if(n%v[i] == 0)
			ans = v[i];
	}
	cout<<ans<<endl;
}