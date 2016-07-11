#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    while(t--)
        {
        for(int n=1;n<100;n++)
        {
        if(((180*(n-2)/n))%90==45)
		cout<<n<<endl;
		}
		cin>>t;
    }
    return 0;
}

