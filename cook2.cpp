//Problem Code : 
//Codechef Id : hemant_1996
//Codechef Name : Hemant Mangla
//
#include<iostream>
using namespace std;
int boyerMoore(int arr[],int n) {
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
	int t;//int b[50000] = {0};
	cin>>t;
	while(t--)
	{
			int n,i,j,k=0,l=0,m=0,x=0,y=0,a[50001];
//using namespace ii;
		cin>>n;
		l=0;
		
		for(i=0;i<n;i++)
		cin>>a[i];
		k = boyerMoore(a,n) ;
	int f=0,h;
		for(i=0;i<n;i++)
		{
			if(a[i]==k)
			{
				f++;
			}
			}
	
		if((n+1)/2>=f)
		{
			cout<<(n+1)/2<<endl;
		}
		else
		{
			cout<<f<<endl;
		}				
	}
	return 0;
}
