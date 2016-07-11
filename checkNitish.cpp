#include "bits/stdc++.h"
using namespace std;
 
#define pb push_back
 
bool visited[10001];
int a[10001],b[10001];
int n;
bool check(int x)
{
   if(a[0]==x){}
   	else
   	{
   		if(a[0]+b[0]==x){visited[0]=true;}
   		else if(a[0]+b[1]==x){visited[1]=true;}
   		else if(a[0]+b[0]+b[1] == x) { visited[0]=visited[1]=true;}
   	}
     
    for(int i=1;i<n-1;i++)
    {
    	if(visited[i-1] ==false)
    	{   
    		if(b[i-1]>x) return false;
    		if(b[i-1]>=x and a[i]>0) return false;
 
 
             if(b[i-1]+a[i]==x)
             {
                 visited[i-1] = true;
                 continue;
             }
             else if(b[i-1]+b[i]+a[i] == x and visited[i]==false)
             {
             	visited[i-1]=visited[i]=true;
             	continue;
             }
             else if(b[i-1]+b[i+1]+a[i] == x )
             {
             	visited[i-1]=visited[i+1]=true;
             	continue;
             }
             else if(b[i-1]+b[i]+b[i+1]+a[i]==x and visited[i]==false)
             {
             	visited[i]=visited[i-1]=visited[i+1]=true;
             	continue;
             }
             else
             	{ //cout << "returning false " << i << endl;
             	  //cout << b[i-1] << " " << b[i] << " " << b[i+1] << "--> " << a[i] << endl;    
                return false;  }
    	}
    	else
    	{
            if(a[i]==x) {continue;}
            else if(a[i]+b[i] == x and visited[i] == false)
            {
            	visited[i] = true;
            	continue;
            }
            else if(a[i]+b[i+1]==x)
            {
            	visited[i+1]=true;
            	continue;
            }
            else if(a[i]+b[i]+b[i+1] ==x and visited[i]==false)
            {
            	visited[i]=visited[i+1]=true;
            	continue;
            }
            else
           	{ //cout << "returning false " << i << endl; 
              //cout << b[i-1] << " " << b[i] << " " << b[i+1] << "--> " << a[i] << endl;
             return false;  }
    	}
    }
 
    int sum =0;
    if(visited[n-2]==false) sum+=b[n-2];
    if(visited[n-1]==false) sum+=b[n-1];
    sum+=a[n-1];
    if(sum!=x)
    	{ //cout << "returning false end sum" <<  endl; 
       return false;  }
    
    	return true;
 
}
 
int main(int argc, char const *argv[])
{
	int t; cin >> t;
	while(t--)
	{   
		//memset(visited,0,sizeof(visited));
		cin >> n;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> b[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
        
        vector <int> v;
       if(n>=2) { v.pb(a[0]);  v.pb(b[0]+a[0]); v.pb(a[0]+b[1]); v.pb(a[0]+b[0]+b[1]);}
       else if(n==1) {
       	   printf("%d\n",a[0]+b[0]);
       	   continue;
       }
        
        sort(v.begin(),v.end());
         
	/*	for (int i = 1; i < n-1; ++i)
		{
             mp[b[i]]++;
             mp[b[i]+a[i-1]]++;
             mp[b[i]+a[i]]++;
             mp[b[i]+a[i+1]]++;
             mp[b[i]+a[i-1]+a[i]]++;
             mp[b[i]+a[i]+a[i+1]]++;
             mp[b[i]+a[i-1]+a[i+1]]++;
             mp[b[i]+a[i]+a[i-1]+a[i+1]]++;
		}
		mp[b[n-1]]++; mp[b[n-1]+a[n-1]]++;mp[b[n-1]+a[n-2]];mp[b[n-1]+a[n-1]+a[n-2]];*/
 
 
 
       /* for(auto it = mp.begin();it!=mp.end();++it)
        {
        	if(it->second >= n)
        		v.push_back(it->first);
        }*/
 
        int flag = 0;
        for(int i = v.size()-1; i >= 0; i--)
        {
        	memset(visited,0,sizeof(visited));
        //	cout << v[i] << endl;
        	if(check(v[i]))
        	{
        		flag = 1;
        		printf("%d\n",v[i]);
        		break;
        	}
        }
 
        if(!flag)
        	printf("-1\n");
 
	}
	return 0;
}