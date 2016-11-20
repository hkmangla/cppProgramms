#include <iostream>
#include <fstream>
#include <math.h>
#include "stdio.h"
#include <string>
#include <vector>

using namespace std;
int absd(int n){
    if(n <0)
        return -n;
    else
        return n;
}
int main(int argc, char const *argv[])
{
    // freopen("template.in", "r", stdin);
    // freopen("template.out", "w", stdout);
    freopen("aplusb.in", "r", stdin);
    freopen("aplusb.out", "w", stdout);
    int w,h;
    cin>>w>>h;
    cin.ignore();
    string keyboard[h+1];
    vector< pair<int,int> > keyRect(256);
    for(int i=0;i<h;i++){
        getline(cin,keyboard[i]);
        for(int j=0;j<keyboard[i].length();j++){
            keyRect[int(keyboard[i][j])] = (make_pair(i,j));
        }
    }
    string lang[3];
    int minTime = 100000000;
    string minLang;
    getline(cin,minLang);
    int langTime = 0;
    for(int k=0;k<3;k++){
    cin>>lang[k];
    cin.ignore(); 
    bool flag = 0;
    for(int it = 0;it<k;it++){
        if(lang[it] == lang[k])
            flag = 1;
    }
    langTime = 0;    
    string s;
    getline(cin,s);
    char lastchar = s[0];
    while( s != ""){
        langTime += max(absd(keyRect[int(s[0])].first-keyRect[int(lastchar)].first),absd(keyRect[int(s[0])].second-keyRect[int(lastchar)].second));
        // cout<<lastchar<<"-->"<<s[0]<<" "<<langTime<<endl; 
        for(int i=1;i<s.length();i++){
            int l = max(absd(keyRect[int(s[i])].first-keyRect[int(s[i-1])].first),absd(keyRect[int(s[i])].second-keyRect[int(s[i-1])].second));
            langTime += l;
            lastchar = s[i];
            // cout<<s[i-1]<<"-->"<<s[i]<<" "<<langTime<<endl; 
        }
        getline(cin,s);
    }
    if(flag) continue;
    if(langTime < minTime){
        minTime = langTime;
        minLang = lang[k];
    }
    }
    cout<<minLang<<endl;
    cout<<minTime;
    return 0;
}