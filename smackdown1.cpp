#include<iostream>
using namespace std;
int maxSubArraySum(int a[], int size)
{
    int start = 0,end=0,max_so_far = 0, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
        {
            start = i+1;
            max_ending_here = 0;
        }
        if (max_so_far < max_ending_here)
        {
            end = i;  
            max_so_far = max_ending_here;
        }
    }
    cout<<start<<' '<<end<<endl;
    int l = 100000000;
    for(int i=start;i<=end;i++)
    {
        if(l > a[i])
            l = a[i];
    }
    if (l > 0)
        l = 0;
    return max_so_far - l;
}
// int maxSubArraySum(int a[], int size)
// {
//     int pos = 0,max_so_far = 0,l = 0, max_ending_here = 0;
 
//     for (int i = 0; i < size; i++)
//     {
//         max_ending_here = max_ending_here + a[i];
//         pos += a[i];
//         if (max_ending_here < 0 && l == 0)
//     	 	{
//     	 	max_ending_here -= a[i];
//     	 	pos = 0;
//     	 	l = 1;
//             // # max_ending_here = 0;
//     	 	}
//     	if (max_ending_here < 0 && l == 1)
//     	 	{
//     	 	l = 0;
//             max_ending_here = pos;
//             max_ending_here -= a[i];
//             pos = 0;
//             if(max_ending_here < 0)
//             	max_ending_here = 0;
//     	 	}
//         if (max_so_far < max_ending_here)
//             max_so_far = max_ending_here;
//     }
//     return max_so_far;
// }
int main()
	{
		int t;cin>>t;
		while(t--){
		int n;cin>>n;
		int a[n+1];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int ans = maxSubArraySum(a,n);
		cout<<ans;
		}
	}




















