#include "bits/stdc++.h"
using namespace std;
long long gcd ( long long a, long long b )
{
    long long c;
    while ( a != 0 )
    {
        c = a;
        a = b%a;
        b = c;
    }
    return b;
}

/**
* Find the least common multiple of 2 numbers
* See http://en.wikipedia.org/wiki/Least_common_multiple
*
* @param[in] a First number
* @param[in] b Second number
* @return least common multiple
*/
long long lcm(long long a, long long b)
{
    return (b / gcd(a, b) ) * a;
}

/**
* Find the greatest common divisor of an array of numbers
* See http://en.wikipedia.org/wiki/Greatest_common_divisor
*
* @param[in] n pointer to an array of number
* @param[in] size Size of the array
* @return greatest common divisor
*/
long long gcd_arr(long long * n, long long size)
{
    long long last_gcd, i;
    if(size < 2) return 0;

    last_gcd = gcd(n[0], n[1]);

    for(i=2; i < size; i++)
    {
        last_gcd = gcd(last_gcd, n[i]);
    }

    return last_gcd;
}

/**
* Find the least common multiple of an array of numbers
* See http://en.wikipedia.org/wiki/Least_common_multiple
*
* @param[in] n pointer to an array of number
* @param[in] size Size of the array
* @return least common multiple
*/
long long lcm_arr(long long * n, long long size)
{
    long long last_lcm, i;

    if(size < 2) return 0;

    last_lcm = lcm(n[0], n[1]);

    for(i=2; i < size; i++)
    {
        last_lcm = lcm(last_lcm, n[i]);
    }

    return last_lcm;
}
int main(){

	long long t; 
		char inp[200];
	cin>>t;cin.getline(inp,200);
	map < string, long long> points;
	points["Darrell"] = 0;
	points["Sally"] = 0;
	long long l = 0;
	string first = "Sally";
	string second = "Darrell";
	while (t){
		string maaa = "";
		string ques;
		getline(cin,ques);
		t--;
		if(t == 0)
		{
			cout<<"Invalid Input"<<endl;
			break;
		}
		// cout<<ques<<endl;
		string ans;
		getline(cin,ans);
		// cout<<ans<<endl;
		if (l==0){
			string aa = "";
			for(long long i=0;i<(long long)ques.length();i++)
				{
					if(ques[i]==' ')
						break;
					aa += ques[i];
				}
			first = aa;
			aa = "";
			for(long long i=2;i<(long long)ans.length();i++)
				{
					if(ans[i]==' ')
						break;
					aa += ans[i];
				}
			second = aa;
			l += 1;
		}
		if (ans[0] != 'A'){
			cout<<"Invalid Input"<<endl;
			break;
		}
		if((long long)ques.length() < 7){
			cout<<"Invalid Input"<<endl;
			break;
		}
		if((long long)ques.length() == 7 && ques[6] == 'l')
		{
			cout<<"Invalid Input"<<endl;
			break;
		}
		t--;
		long long mark = 0;
		long long user  = 0;
		for(long long i=0;i<(long long)ques.length();i++)
		{
			if(ques[i] == ' ')
			{
				if(user == 1)
					break;
				cout<<"'s question is:";
				mark = i;
				user ++;
			}
			cout<<ques[i];
		}
		cout<<endl;
		std::vector<long long> v;
		string ma = "";
		long long index =0,arr[100];
		for(long long i=mark+1;i<(long long)ques.length();i++)
		{
			// cout<<ques[i];
			if(ques[i] == ','){
				long long x = (long long)strtol(ma.c_str(),NULL,10);
				arr[index] = x;
				// cout<<x<<endl;
				index++;
				ma = "";
			}
			else
			ma += ques[i];
		}
		// cout<<ma<<endl;
		long long x = (long long)strtol(ma.c_str(),NULL,10);
				arr[index] = x;
				// cout<<x<<endl;
				index++;
		long long rightAns;
		if(index == 1)
			rightAns = arr[0];
		else
			rightAns  =  lcm_arr(arr,index);
		// cout<<rightAns<<endl;
		long long kuchbi = 0;
		long long req;
		for(long long i=0;i<(long long)ans.length();i++){
			if(ans[i] == ' ')
				kuchbi += 1;
			if(kuchbi == 2)
			{
				req = i+1;
				break;
			}
		}
		for(long long i=2;ans[i]!=' ';i++){
					// cout<<ans[i];
					maaa += ans[i];	
				}
		// cout<<ans[req]<<endl;
		if(ans[req] >= '0' and ans[req] <= '9'){
			string maa = "";
			for(long long i=req;i<(long long)ans.length();i++)
				maa+= ans[i];
			long long InputAns =  (long long)strtol(maa.c_str(),NULL,10);
			if(InputAns-rightAns == 0){

				cout<<"Correct Answer"<<endl;
				
				cout<<maaa;
				cout<<": 10points"<<endl;
				points[maaa] += 10;
			}
			else{
				cout<<"Wrong Answer"<<endl;
				cout<<maaa<<": 0points"<<endl;
				
			}
		}
		else{

			cout<<"Question is PASSed"<<endl;
			cout<<"Answer is: "<<rightAns<<endl;
			cout<<maaa<<": 0points"<<endl;
		}
		// t = t - 2;
}
	if(t == 0){		
		cout<<"Total points:"<<endl;
		cout<<first<<": "<<points[first]<<"points"<<endl;
		cout<<second<<": "<<points[second]<<"points"<<endl;
		if(points["Sally"] > points["Darrell"])
			cout<<"Game Result: Sally is winner"<<endl;
		else if(points["Sally"] < points["Darrell"])
			cout<<"Game Result: Darrell is winner"<<endl;
		else
			cout<<"Game Result: Draw"<<endl;
	}
}