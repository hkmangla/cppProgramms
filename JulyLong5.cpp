#include<iostream>
using namespace std;
int main()
{
	int l;cin>>l;
	while(l--){
		
	int n;cin>>n;
	int b[n+3],a[n],c[n+3];
	// int sumA = 0, sumB = 0,maxA = -1;
	for(int i=0;i<n;i++){
		cin>>c[i];
		// sumB += c[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		// maxA = max(maxA,a[i]);
		// sumA += a[i];
	}
	c[n] = 0;
	int flag = 0,flag1=0,flag2=0,flag3=0,flag4=0;
	int value1 = a[0],value2 = a[0] + c[0], value3 = a[0] + c[1], value4 = a[0] + c[0] + c[1];
	for(int i=0;i<=n;i++)
		b[i] = c[i];
	for(int i=1;i<=n;i++){
		if(i == n)
		{
			flag1 = value1;
			break;
		}
		if(a[i] == value1)
			continue;
		if(a[i] + b[i-1] == value1)
		{
			b[i-1] = 0;
			continue;
		}	
		if(a[i] + b[i-1] + b[i] == value1)
		{
			b[i-1] = 0;
			b[i] = 0;
			continue;
		}
		if(a[i] + b[i-1] + b[i+1] == value1)
		{
			b[i-1] = 0;
			b[i+1] = 0;
			continue;
		}
		if(a[i] + b[i-1] + b[i] + b[i+1] == value1)
		{	
			b[i] = 0;
			b[i+1] = 0;
			b[i-1] = 0;
			continue;
		}
		if(a[i] + b[i] == value1)
		{
			b[i] = 0;
			continue;
		}
		if(a[i] + b[i+1] == value1)
		{
			b[i+1] = 0;
			continue;
		}
		if(a[i] + b[i+1] + b[i] == value1)
		{
			b[i+1] = 0;
			b[i] = 0;
			continue;
		}
		break;
	 }
	for(int i=0;i<n;i++){
	 	if(b[i]!=0)
	 	{
	 		flag1 = 0;
	 		break;
	 	}
	 }
	flag = max(flag,flag1);
	for(int i=0;i<=n;i++)
		b[i] = c[i];
	b[0] = 0;
	for(int i=1;i<=n;i++){
		if(i == n)
		{
			flag2 = value2;
			break;
		}
		if(a[i] == value2)
			continue;
		if(a[i] + b[i-1] == value2)
		{
			b[i-1] = 0;
			continue;
		}	
		if(a[i] + b[i-1] + b[i] == value2)
		{
			b[i-1] = 0;
			b[i] = 0;
			continue;
		}
		if(a[i] + b[i-1] + b[i+1] == value2)
		{
			b[i-1] = 0;
			b[i+1] = 0;
			continue;
		}
		if(a[i] + b[i-1] + b[i] + b[i+1] == value2)
		{	
			b[i] = 0;
			b[i+1] = 0;
			b[i-1] = 0;
			continue;
		}
		if(a[i] + b[i] == value2)
		{
			b[i] = 0;
			continue;
		}
		if(a[i] + b[i+1] == value2)
		{
			b[i+1] = 0;
			continue;
		}
		if(a[i] + b[i+1] + b[i] == value2)
		{
			b[i+1] = 0;
			b[i] = 0;
			continue;
		}
		break;
	 }
	 for(int i=0;i<n;i++){
	 	if(b[i]!=0)
	 	{
	 		flag2 = 0;
	 		break;
	 	}
	 }
	flag = max(flag,flag2);
	for(int i=0;i<=n;i++)
		b[i] = c[i];
	b[1] = 0;
	for(int i=1;i<=n;i++){
		if(i == n)
		{
			flag3 = value3;
			break;
		}
		if(a[i] == value3)
			continue;
		if(a[i] + b[i-1] == value3)
		{
			b[i-1] = 0;
			continue;
		}
		if(a[i] + b[i-1] + b[i] == value3)
		{
			b[i-1] = 0;
			b[i] = 0;
			continue;
		}
		if(a[i] + b[i-1] + b[i+1] == value3)
		{
			b[i-1] = 0;
			b[i+1] = 0;
			continue;
		}
		if(a[i] + b[i-1] + b[i] + b[i+1] == value3)
		{	
			b[i] = 0;
			b[i+1] = 0;
			b[i-1] = 0;
			continue;
		}
		if(a[i] + b[i] == value3)
		{
			b[i] = 0;
			continue;
		}
		if(a[i] + b[i+1] == value3)
		{
			b[i+1] = 0;
			continue;
		}
		if(a[i] + b[i+1] + b[i] == value3)
		{
			b[i+1] = 0;
			b[i] = 0;
			continue;
		}	
		break;
	}
	 for(int i=0;i<n;i++){
	 	if(b[i]!=0)
	 	{
	 		flag3 = 0;
	 		break;
	 	}
	 }
	flag = max(flag,flag3);
	for(int i=0;i<=n;i++)
		b[i] = c[i];
	b[0] = 0;
	b[1] = 0;
	for(int i=1;i<=n;i++){
		if(i == n)
		{
			flag4 = value4;
			break;
		}
		if(a[i] == value4)
			continue;
		if(a[i] + b[i-1] == value4)
		{
			b[i-1] = 0;
			continue;
		}	
		if(a[i] + b[i-1] + b[i] == value4)
		{
			b[i-1] = 0;
			b[i] = 0;
			continue;
		}
		if(a[i] + b[i-1] + b[i+1] == value4)
		{
			b[i-1] = 0;
			b[i+1] = 0;
			continue;
		}
		if(a[i] + b[i-1] + b[i] + b[i+1] == value4)
		{	b[i] = 0;
			b[i+1] = 0;
			b[i-1] = 0;
			continue;
		}
		if(a[i] + b[i] == value4)
		{
			b[i] = 0;
			continue;
		}
		if(a[i] + b[i+1] == value4)
		{
			b[i+1] = 0;
			continue;
		}
		if(a[i] + b[i+1] + b[i] == value4)
		{
			b[i+1] = 0;
			b[i] = 0;
			continue;
		}
		break;
	}
	for(int i=0;i<n;i++){
	 	if(b[i]!=0)
	 	{
	 		flag4 = 0;
	 		break;
	 	}
	 }
    flag = max(flag,flag4);
	if(flag != 0)
		cout<<flag<<endl;
	if(flag == 0 )
		cout<<"-1\n";
	}
	return 0;
}