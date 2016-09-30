#include<iostream>
using namespace std;
int n,y[22],sum,c=0;
int count(int i, int sum_so_far, int leftl, int lefth){
	// c += 1;
	// cout<<n<<endl;
	if(i == n+1){
		if(sum_so_far == sum && leftl <= lefth)
			return 1;
		else
			return 0;
	}
	c+=1;
	cout<<c<<endl;
	int result = 0;
	for(int d=0;d<10;d++)
	{
		int leftll = leftl;
		int lefthh = lefth;
		if(d < y[i] && i < leftll)
			leftll = i;
		if(d > y[i] && i < lefthh)
			lefthh = i;
		//cout<<d<<endl;
		result+= count(i+1,sum_so_far+d,leftll,lefthh);
	}
	return result;
}
int mem[22][100][2];
void initial(){
	for(int i=0;i<22;i++){
		for(int j=0;j<100;j++){
			for(int k=0;k<2;k++)
				mem[i][j][k]=-1;
		}
	}
}
int count_dp(int i,int sum_so_far, bool lo)
{
	if(i==n+1) return sum_so_far==sum;
	c +=1;
	cout<<c<<endl;
	int result = 0;
	for (int d = 0; d <= (lo?9:y[i]); d++)
	{
		if(sum_so_far+d > sum)
			break;
		int l = (lo || d<y[i])?1:0;
		if(mem[i+1][sum_so_far+d][lo || d<y[i]] == -1)
				mem[i+1][sum_so_far+d][l] = count_dp(i+1,sum_so_far+d,lo || d<y[i]);
		result+=mem[i+1][sum_so_far+d][l];
	}
	return result;
}
int main(int argc, char const *argv[])
{
	cin>>n;
	initial();
	// cout<<mem[0][0][0]<<endl;
	for(int i=1;i<=n;i++)
		cin>>y[i];
	cin>>sum;
	cout<<count_dp(1,0,false)<<" "<<c<<endl;
	return 0;
}