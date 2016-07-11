#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		char a[1000001],b[1000001]; int n,c1=0,c0=0,count = 0,count1 = 0, count0 = 0;
		cin>>a>>b;
		n = strlen(a);
		for(int i=0;i<n;i++){
			if(a[i] != b[i])
			{
				count ++;
			if(a[i] == '1')
				c1 ++;
			if(a[i] == '0')
				c0 ++;
			}
			if(a[i] == '1')
				count1 ++;
			if(a[i] == '0')
				count0 ++;
		}
		if(count1 == 0)
			cout<<"Unlucky Chef\n";
		else if(count0 == 0)
			cout<<"Unlucky Chef\n";
		else
			cout<<"Lucky Chef\n"<<max(c0,c1)<<endl;

	}
}
