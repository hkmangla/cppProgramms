#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
using namespace std;
std::vector<long long> hold1;
std::vector<long long> hold2;
// std::vector<long long> nvalues;
long long maxSubArraySum(long long a[], int size)
{
	hold1.clear();
	hold2.clear();
	long long maxx = 10000000001,push = 0,phold = 0,nsum = 0,first = 0;int start,l = 0,ll = 1;
    for(int i=0;i<size;i++)
    {
    	if(a[i] > 0)
    	{
    		start = i;
    		break;
    	}
    		
    }
    for(int i=start;i<size;i++)
    {
    	if(a[i] < 0)
    	{
    		if(a[i] < maxx)
    			maxx = a[i];
    		nsum += a[i];
    		if(ll == 0)
    		{	
    		phold = push;	
    		hold1.push_back(push);
    		push = 0;
    		ll = 1;
    		first = 1;
    		}
    		continue;
    	}
    	if(a[i] >= 0)
    	{
    		if(ll == 1 && first == 1 )
    		{	
    		nsum -= maxx;
    		hold2.push_back(phold+nsum+l);
    		l = phold+nsum+l+maxx;
    		if(l < 0)
    			l = 0;
    		maxx = 10000000001;
    		nsum = 0;
    		}
    		ll = 0;
    		push += a[i];
    	}
    }
    if(push != 0)
    hold1.push_back(push);
    hold2.push_back(0);
    // for(int i=0;i < hold1.size();i++)
    	// cout<<hold1[i]<<endl;
    // for(int i=0;i < hold2.size();i++)
    	// cout<<hold2[i]<<endl;
    // cout<<hold1.size()<<" "<<hold2.size()<<endl;
    long long ans = 0;
    for(int i=0;i < hold1.size() - 1;i++)
    	{
    		ans = max(hold2[i]+hold1[i+1],ans);
    	}
    ans = max(hold1[0],ans);
    // ans = max(hold2[hold2.size()-1],ans);
    return ans;
}
int main()
	{
		FILE* fp = fopen("ue.txt","w");
		int t;cin>>t;
		while(t--){
		int n,c = 0;cin>>n;
		long long a[n+1],b[n+1],maxx = -10000000001;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i] < 0)
				c++;
			if(a[i] > maxx)
				maxx = a[i];
		}
		if (c == n){
			cout<<maxx<<endl;
			fprintf(fp, "%lld\n",maxx);
			continue;
		}
		for(int i=0;i<n;i++)
		{
			b[i] = a[n-1-i];
		}
		long long ans = maxSubArraySum(a,n);
		long long ans2 = maxSubArraySum(b,n);
		ans = max(ans,ans2);
		cout<<ans<<endl;
		fprintf(fp, "%lld\n",ans );
		}
		return 0;
	}




















