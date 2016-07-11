#include<bits/stdc++.h>
using namespace std;
    int dot(int A[], int B[], int C[]){
        int AB[2];
        int BC[2];
        AB[0] = B[0]-A[0];
        AB[1] = B[1]-A[1];
        BC[0] = C[0]-B[0];
        BC[1] = C[1]-B[1];
        int dot = AB[0] * BC[0] + AB[1] * BC[1];
        return dot;
    }
    //Compute the cross product AB x AC
    int cross(int A[], int B[], int C[]){
        int AB[2];
        int AC[2];
        AB[0] = B[0]-A[0];
        AB[1] = B[1]-A[1];
        AC[0] = C[0]-A[0];
        AC[1] = C[1]-A[1];
        int cross = AB[0] * AC[1] - AB[1] * AC[0];
        return cross;
    }
    //Compute the distance from A to B
    double distance(int A[], int B[]){
        int d1 = A[0] - B[0];
        int d2 = A[1] - B[1];
        return sqrt(d1*d1+d2*d2);
    }
    //Compute the distance from AB to C
    //if isSegment is true, AB is a segment, not a line.
    double linePointDist(int A[], int B[], int C[], bool isSegment){
        double dist = cross(A,B,C) / distance(A,B);
        if(isSegment){
            int dot1 = dot(A,B,C);
            if(dot1 > 0)return distance(B,C);
            int dot2 = dot(B,A,C);
            if(dot2 > 0)return distance(A,C);
        }
        return abs(dist);
    }
int main(){
    int t;cin>>t;while(t--){
        int a[2] = {0,0};
        int b[2] = {0,4};
        int c[2] = {2,2};
        cout<<linePointDist(a,b,c,true)<<endl;
    }
}