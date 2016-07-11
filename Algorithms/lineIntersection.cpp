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
pair<double,double> lineIntersection(double A1,double B1,double C1,double A2,double B2,double C2){
	double x,y,det = A1*B2 - A2*B1;
    if(det == 0){
        return make_pair<double,double>(-1000000000,-1000000000);
    }else{
        x = (B2*C1 - B1*C2)/det;
        y = (A1*C2 - A2*C1)/det;
    }
    return make_pair<double,double>(x,y);
}

bool checkSegment(double x,double y,double x1, double y1, double x2, double y2){
  return ( min(x1,x2) <= x && max(x1,x2) >= x && min(y1,y2) <= y && max(y1,y2) >= y) ? true:false;
}
int main(){
	int t;		
	scanf("%d",&t);
	while(t--){
      double a,b,c,A,B,C,x1,x2,y1,y2;
      scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
      a = y2-y1;
      b = x1-x2;
      c = a*x1+b*y1;
      scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
      A = y2-y1;
      B = x1-x2;
      C = A*x1+B*y1;
      double x,y;
      unpair(x,y) = lineIntersection(a,b,c,A,B,C);
      bool check = checkSegment(x,y,x1,y1,x2,y2);
      cout<<check<<endl;
      printf("%lf %lf\n",x,y);
	}
}