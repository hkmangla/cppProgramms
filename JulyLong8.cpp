#include<bits/stdc++.h>
using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
#define ll long long int
#define doit() int t; cin>>t;while(t--)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
template<class type>
type gcd(type a, type b) {return (b==0)?a:gcd(b,a%b);}
bool checkSegment(double x,double y,double x1, double y1, double x2, double y2){
  return ( min(x1,x2) <= x && max(x1,x2) >= x && min(y1,y2) <= y && max(y1,y2) >= y) ? true:false;
}
double areaPolygon(double p[][2], int N){
double area = 0;
// double N = lengthof(p);
//We will triangulate the polygon
//doubleo triangles with podoubles p[0],p[i],p[i+1]
double cross;
for(int i = 1; i+1<N; i++){
    double x1 = p[i][0] - p[0][0];
    double y1 = p[i][1] - p[0][1];
    double x2 = p[i+1][0] - p[0][0];
    double y2 = p[i+1][1] - p[0][1];
    cross = x1*y2 - x2*y1;
    // cout<<cross/2<<endl;
    area += cross;
}
return abs(area/2.0);
}
int main()
{
	doit()
	{
	int n;
	cin>>n;
	vector < pair<double,double> > points;
	for(int i=0;i<n;i++){
		double x,y;
		cin>>x>>y;
		points.push_back(make_pair(x,y));
	}
	double cross;
	vector < pair<double,double> > pPoint;
		// vector < pair<double,double> > nPoint;
	for(int i = 0; i<n; i++){
	    int last = (i - 1 + n) % n;
        int next = (i + 1) % n;
        double x1 = points[i].first - points[last].first;
        double y1 = points[i].second - points[last].second;
        double x2 = points[next].first - points[i].first;
        double y2 = points[next].second - points[i].second;
        double theta1 = atan2(y1, x1)*180/3.1415926358979323;
        double theta2 = atan2(y2, x2)*180/3.1415926358979323;
        cross = theta1 - theta2 + 540;
        while(cross>360)cross-=360;
        // cout<<i<<" "<<i+1<<" "<<cross<<endl;
	    if(cross < 180){
	    	pPoint.push_back(points[last]);
	    	pPoint.push_back(points[i]);
	    	pPoint.push_back(points[next]);    	
	    }
	    // else{
	    // 	pPoint.push_back(points[last]);
	    // 	pPoint.push_back(points[i]);
	    // 	pPoint.push_back(points[next]);    	
	    // }
	}
	vector < pair<double,double> > reducePoints;
	// if(nPoint.size() < pPoint.size()){
	// 	pPoint.clear();
	// 	for(int i=0;i<nPoint.size();i++)
	// 		pPoint.push_back(nPoint[i]);
	// }
		if(pPoint.size() == 0){
			int sis = points.size();
			double arr[sis+1][2];
			int ik=0;
			tr(points,it){
			// printf("%lf %lf\n",it->first,it->second);
			arr[ik][0] = it->first;
			arr[ik][1] = it->second;
			ik++;
			}
			double ans = areaPolygon(arr,sis);
			double total = 4 * 10000000;
			total*=10000000;
			printf("%lf\n",ans/total );
			continue;
			printf("Yes\n");
		}
		double a = (pPoint[1].second - pPoint[0].second),b=(pPoint[0].first - pPoint[1].first);
		double c = (a*pPoint[0].first + b*pPoint[0].second);
		int flag = 0;
		reducePoints.push_back(pPoint[1]);
		for(int i=0;i<n;i++){
			int it = i + 1;
			if(it == n)
				it = 0;
			if(points[i].first == pPoint[1].first && points[i].second == pPoint[1].second)
				continue;
			if(points[it].first == pPoint[1].first && points[it].second == pPoint[1].second)
				continue;
			double A = (points[it].second - points[0+i].second),B=(points[i+0].first - points[it].first);
			double C = (A*points[i].first + B*points[0+i].second);
			if(flag)
				reducePoints.push_back(points[i]);
			double x,y,det = a*B - A*b;
			// cout<<"i = "<<i<<endl;
		    if(det == 0){
		   			continue;
		    }else{
		        x = (B*c - b*C)/det;
		        y = (a*C - A*c)/det;
		        if(checkSegment(x,y,points[i].first,points[i].second,points[it].first,points[it].second)){
		        	reducePoints.push_back(make_pair(x,y));
		        	if(flag)
		        		break;
		        	if(!flag)
		        	{
		        		flag = 1;
		        		a = (pPoint[2].second - pPoint[1].second);
		        		b=  (pPoint[1].first - pPoint[2].first);
						c = (a*pPoint[1].first + b*pPoint[1].second);
		        	}

		        }
		    }
		}

		for(int i=4;i<pPoint.size();i=i+3){
			a = (pPoint[i].second - pPoint[i-1].second),b=(pPoint[i-1].first - pPoint[i].first);
			c = (a*pPoint[i-1].first + b*pPoint[i-1].second);
			for(int j=0;j<reducePoints.size();j++){
				int it = j + 1;
				if(it == n)
					it = 0;
				if(reducePoints[j].first == pPoint[i].first && reducePoints[j].second == pPoint[i].second)
					continue;
				if(reducePoints[it].first == pPoint[i].first && reducePoints[it].second == pPoint[i].second)
					continue;
				double A = (reducePoints[it].second - reducePoints[j].second),B=(reducePoints[j].first - reducePoints[it].first);
				double C = (A*reducePoints[j].first + B*reducePoints[j].second);
				double x,y,det = a*B - A*b;
				// cout<<"i = "<<i<<endl;
		    	if(det == 0){
		   			continue;
		   		 }else{
		        x = (B*c - b*C)/det;
		        y = (a*C - A*c)/det;
		        if(checkSegment(x,y,points[i].first,points[i].second,points[it].first,points[it].second)){
		        	reducePoints.push_back(make_pair(x,y));
		     }
			}

		}

		int sis = reducePoints.size();
		double arr[sis+1][2];
		int ik=0;
		tr(reducePoints,it){
			// printf("%lf %lf\n",it->first,it->second);
			arr[ik][0] = it->first;
			arr[ik][1] = it->second;
			ik++;
		}
		double ans = areaPolygon(arr,sis);
		double total = 4 * 10000000;
		total*=10000000;
		printf("%lf\n",ans/total );
	}
	return 0;
}