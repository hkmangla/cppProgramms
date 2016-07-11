#include<iostream>
#include<stdio.h>
using namespace std;
 
int maxSubArraySum(int a[], int size)
{
    int max_so_far = 0, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
int main()
	{
		int t;cin>>t;
		FILE* fp = fopen("u.txt","w");
		while(t--){
		int n;cin>>n;
		int a[n+1],b[n+1],ans,aa=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		ans = maxSubArraySum(a,n);
		for(int i=0;i<n;i++)
		{
				for(int j=0;j<n;j++)
				{
					if(j==i)
						b[j]=0;
					else
						b[j]=a[j];
				}
			aa = maxSubArraySum(b,n);
			if(aa > ans)
				ans = aa;
		}
		cout<<ans<<endl;
		fprintf(fp, "%d\n",ans );
		}
	}



















