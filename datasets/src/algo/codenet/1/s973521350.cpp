#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
#define INF 1200000000


int main(){
    
    int c[4][4];
    rep(i,0,3){
        rep(j,0,3){
            cin>>c[i][j];
        }
    }
    if(c[0][0]+c[1][1]+c[2][2] == c[0][1]+c[1][2]+c[2][0] && c[1][0]+c[2][1]+c[0][2]== c[0][1]+c[1][2]+c[2][0]){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}


