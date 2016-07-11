#include <iostream>
using namespace std;

int main()
{
    int n,q,a[100001],b[100001];
    cin>>n>>q;
    for(int i=3;i<=n+2;i++)
    cin>>a[i];
    for(int i=3;i<=n+2;i++)
    cin>>b[i];
    a[0]=0;a[1]=0;a[2]=0;
    b[0]=0;b[1]=0;b[2]=0;
    for(int i=5;i<=n+2;i++)
    {
    	a[i]+=a[i-2];
        b[i]+=b[i-2];   
		cout<<a[i]<<" "<<b[i]<<endl;	
    }
    while(q--)
    {
    	int query,l,r;
    	cin>>query>>l>>r;
    	l+=2;r+=2;
    	if(query==1)
    	{
    		if((l-r)%2==0)
    		cout<<a[r-1]-a[l-2]+b[r]-b[l-1]<<endl;
    		else
    		cout<<a[r]-a[l-2]+b[r-1]-b[l-1]<<endl;
    	}
    	if(query==2)
    	{
    		if((l-r)%2==0)
    		cout<<b[r-1]-b[l-2]+a[r]-a[l-1]<<endl;
    		else
    		cout<<b[r]-b[l-2]+a[r-1]-a[l-1]<<endl;
    	}
    	
    }
    return 0;
}

