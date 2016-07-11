#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		double h,a,x,y;
		// cin>>h>>a;
		scanf("%lf %lf",&h,&a);
		y = (pow(h,4) - 16*(a*a));
		if(pow(h,4) < 16*a*a)
		{
			printf("-1\n");
			continue;
		}
		x = (h*h + sqrt(y))/2;
		x = sqrt(x);
		y = (h*h - x*x);
		y = sqrt(y);
		// cout<<x<<endl;
		if(x <= y)
		 printf("%lf %lf %lf\n",x,y,h);
		else
		 printf("%lf %lf %lf\n",y,x,h);

	}
}