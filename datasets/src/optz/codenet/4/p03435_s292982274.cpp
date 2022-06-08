#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
 
int main(void){
    int c[3][3];
    rep(i,3)rep(j,3){
        cin>>c[i][j];
    }
    rep(i,3){
        set<int> st;
        rep(j,3) st.insert(c[i][j]-c[(i+1)%3][j]);
        if(st.size() > 1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}