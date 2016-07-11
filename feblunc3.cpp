#include<iostream>
using namespace std;
int n,b[500001],a[500001];
int bo(int arr[],int n) {
    int current_candidate = arr[0], counter = 0, i;
    for (i = 0; i < n; ++i) {
        if (current_candidate == arr[i]) {
            ++counter;
    //        printf("candidate: %i, counter: %i\n",current_candidate,counter);
        } else if (counter == 0) {
            current_candidate = arr[i];
            ++counter;
  //          printf("candidate: %i, counter: %i\n",current_candidate,counter);
        } else {
            --counter;
//            printf("candidate: %i, counter: %i\n",current_candidate,counter);
        }
    }
    
    return current_candidate;
}
int main()
{
	long long int ans=0;
	cin>>n;
	for(int i = 0;i<n;i++)
	cin>>a[i];
	for(int i = 0;i<n;i++)
	{
		int k = 0;
		for(int j=i;j<n;j++)
		{
			b[k]=a[j];
			int ll,l=0,g=j-i+1;
			ll = bo(b,g);
			for(int u=0;u<g;u++)
			{
				if(b[u]==ll)
				l++;
			//	cout<<b[u]<<" ";
			}
			if(l>(g/2))
			ans++;
			k++;
			//	cout<<endl;
		}
	
	}
	cout<<ans<<endl;
//	int y;cin>>y;
	return 0;
}
