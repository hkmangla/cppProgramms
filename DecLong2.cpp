#include<iostream>
using namespace std;
void merge(float arr[],int min,int mid,int max)
{
  float tmp[30];
  int i,j,k,m; 
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}
void part(float arr[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(arr,min,mid);
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}
int binarySearch(float arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return -1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		float n,a,b,c; float cb[100000],m[100000],backup[100000];
		cin>>n;
		for(int i = 0; i < n; i ++)
		{
			cin>>a>>b>>c;
			if(b!=0)
			{
			cb[i] = c/b;
			m[i] = a/b; 
			backup[i] = a/b;
		    }
		}
		part(m,0,n-1);
		float min = 0,cv[100000];
         int j = 0;	
		for(int i = 0; i < n; i ++)
		{
			if(i == 0)
			{
			float l = m[i];
			int y = binarySearch(backup, 0 ,n-1, l);
			cv[j] = cb[i];
			j++;
		}
			if(i !=0&&m[i] == m[i-1])
			{
			float l = m[i];
			int y = binarySearch(backup, 0 ,n-1, l);
			cv[j] = cb[y];
			j++;
		    }
		    if(m[i]!= m[i-1])
		    {
		     part(cv,0 ,j );
             int ca = 1;
			 for(int kk = 1; kk<=j; kk++)
			 {
			 	if(cv[kk] != cv[kk-1] )
			 	{
			 		ca++;
				 }
				 }	
				 j = 0;
				 if(ca> min)
				 min = ca;
			}
		   
		}
		 cout<<min<<endl;
	}
	return 0;
}
