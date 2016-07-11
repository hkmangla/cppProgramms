#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
// int b[1000001];
int primeFactors(long long int n)
{
    // Print the number of 2s that divide n
    // long long int b[100],k=0;
    if (n%4 == 0)
    {
        // b[k] = 2;
        // k++;
        // n = n/2;
        return 2;
    }
    while(n%2==0)
        n=n/2;
    long long int m = n;
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (long long int i = 3; i <= min(sqrt(m),1000000.00); i=i+1)
    {
        // While i divides n, print i and divide n
        if (m%(i*i) == 0)
        {
            // b[k] = (i*i;
            // k++;
            // //printf("%d ", i);
            // n = n/i;
            return i;
        }
        if(roundf(sqrt(n)) == sqrt(n))
            return roundf(sqrt(n));
            // float x = sqrt(n);
        // long long int y=x;
        // // cout<<y-x<<endl;  
        // if((x-y)<0.0001)
        //     return sqrt(n);
        if(n%i == 0)
             n = n/i;
    }
 // 
    // This condition is to handle the case whien n is a prime number
    // // greater than 2
    if (n > 2)
    {
        float x = sqrt(n);
        long long int y=x;  
        if((x-y)==0)
            return roundf(sqrt(n));
    }
    // // mergesort(b,0,k-1);
    // for(int i=1;i<k;i++)
    // {
    //     if(b[i] == b[i-1])
    //         return b[i];
    // }
    return 0;
        // printf ("%d ", n);
}
long long int gcd(long long int a, long long int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main(){
    int t;cin>>t;
    while(t--){
        // for(int i=0;i<1000001;i++)
            // b[i]=0;
        int flag=1,n;cin>>n;
        long long int a[n+1];
        for(int i=0;i<n;i++)
            {
                cin>>a[i];
            }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long int y = gcd(a[i],a[j]);
                if(y > 1){
                    cout<<y<<endl;
                    flag = 0;
                    break;
                }

            }
            if(flag == 0)
                break;
        }
        if(flag){
            for(int i=0;i<n;i++){
                long long int p = primeFactors(a[i]);
                if(p>1)
                {
                    cout<<p<<endl;
                    break;
                }
                    
            }
        }
    }
}













