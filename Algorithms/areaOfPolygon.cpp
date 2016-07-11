#include<bits/stdc++.h>
using namespace std;

template <typename T1, typename T2>
struct t_unpair
  {
  T1& a1;
  T2& a2;
  explicit t_unpair( T1& a1, T2& a2 ): a1(a1), a2(a2) { }
  t_unpair<T1,T2>& operator = (const pair<T1,T2>& p)
    {
    a1 = p.first;
    a2 = p.second;
    return *this;
    }
  };

// Our functor helper (creates it)
template <typename T1, typename T2>
t_unpair<T1,T2> unpair( T1& a1, T2& a2 )
  {
  return t_unpair<T1,T2>( a1, a2 );
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
pair<double,double> lineIntersection(double A1,double B1,double C1,double A2,double B2,double C2){
	double det = A1*B2 - A2*B1
    if(det == 0){
        //Lines are parallel
        return 
    }else{
        double x = (B2*C1 - B1*C2)/det
        double y = (A1*C2 - A2*C1)/det
    }
    return make_pair<double,double>(x,y);
}
int main(){
	int t;		
	scanf("%d",&t);
	while(t--){
		int n;//cin>>n;
		scanf("%d",&n);
		double a[n+1][2];
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0];
			cin>>a[i][1];
		}
		double area = areaPolygon(a,n);
		printf("%lf\n",area);
	}
}