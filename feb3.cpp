#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    if(n<7)
	    cout<<"-1\n";
	 //   continue;
	    else
	    {int y=n+1;
	        cout<<n<<endl;
	        for(int i=7;i<=n;i++)
	        {
	            cout<<"1 "<<i<<endl;
	        }
	        cout<<"5 1\n5 6\n6 4\n2 3\n3 4\n1 2\n2\n";
	    }
	}
	return 0;
}
 
