#include "bits/stdc++.h"
using namespace std;

int ves[27][27][27][27];
int vesited(string s, int type = -1){
    if(type != -1) {
        ves[s[0]-'a'][s[1]-'a'][s[2]-'a'][s[3]-'a'] = type;
        return 1;
    }
    else{
        return ves[s[0]-'a'][s[1]-'a'][s[2]-'a'][s[3]-'a'];
    }
}
int n = 0;
int bfs(string s,string f){
    queue<string> q;
    q.push(s);
    int t = vesited(s,0);
    while(!q.empty()){
        string node = q.front();
        q.pop();
        // cout<<node<<endl;
        for(int i=0;i<4;i++){
            string newNode = node; 
            if(newNode[i] == 'a') newNode[i] = 'z';
            else newNode[i] -= 1;
            if(vesited(newNode) == -1){
            int t = vesited(newNode,1+vesited(node));
            // cout<<newNode<<endl;
            q.push(newNode);
            }
           // n++;
        }
        for(int i=0;i<4;i++){
            string newNode = node; 
            if(newNode[i] == 'z') newNode[i] = 'a';
            else newNode[i] += 1;
            if(vesited(newNode) == -1){
            q.push(newNode);    
            // cout<<newNode<<endl;
            int t = vesited(newNode,1+vesited(node));
            }
        // n++;
        }
        if(vesited(f) != -1)
            return vesited(f);
    }
    // cout<<n<<endl;
}





    // if(vesited(s) != -1) return vesited(s);
    // if(s == f) return 0;
    // int ans = 1;
    // n++;
    // int t = vesited(s,ans);
    // for(int i=0;i<4;i++){   
    //     string newString = s;
    //     if(newString[i] == 'z') newString[i] = 'a';
    //     else    newString[i]+=1;
    //     ans = min(1+bfs(newString,f), ans);
    //     if(newString[i] == 'a') newString[i] = 'z';
    //         else newString[i]-=1;
    //     ans = min(1+bfs(newString,f), ans);
    // }
    // return ans;
//}


class SmartWordToy{
public:
    int minPresses(string start,string finish){
        memset(ves,-1,sizeof(ves));
        return bfs(start,finish);
    }
};

int main(int argc, char const *argv[])
{
    int t; cin>>t;
    while(t--){
        string s,f; cin>>s>>f;
        SmartWordToy A;
        cout<<A.minPresses(s,f)<<endl;
    }
    return 0;
}