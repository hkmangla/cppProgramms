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
int main(){
	long long int m = 0;
	int a[100][200];
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++)
        cin>>a[i][j];
    }
    int ANS = 0;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            int ans1=1,ans2=1,ans3=1;
            int x = i,y = j,check = 0;
            for(int ii=0;ii<4;ii++)
            {
                // cout<<a[x+ii][y]<<endl;
                if(x+ii < 20){
                    ans1*=a[x+ii][y];
                    // cout<<ans1<<" ";
                    check ++;
                }
            }
            check = 0;
            for(int ii=0;ii<4;ii++)
            {
                if(y+ii < 20){
                    ans2*=a[x][y+ii];
                    check ++;
                }
            }
            check = 0;
            for(int ii=0;ii<4;ii++)
            {
                if(x+ii < 20 && y +ii < 20){
                    ans3*=a[x+ii][y+ii];
                    check ++;
                }
            }
            int ans4 = 1;
            for(int ii=0;ii<4;ii++)
            {
                if(x+ii <20 && y-ii >= 0){
                    ans4*=a[x+ii][y-ii];
                    check ++;
                }
            }
            ANS = max(ANS,ans4);
            ANS = max(ANS,max(ans1,max(ans2,ans3)));
        }
        // break;
    }
    cout<<ANS<<endl;
}