#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main(){
    int N,K; cin >> N >> K;
    set<int> st;
    rep(i,K){
        int d; cin >> d;
        st.insert(d);
    }

    for(int i=N;i<100000;i++){
        string s = to_string(i);
        bool ng = false;
        rep(j,s.size()){
            for(auto it : st){
                if(s[j]==it+'0'){
                    ng = true;
                    break;
                }
            }
            if(ng) break;
        }
        if(!ng){
            cout << s << endl;
            return 0;
        }
    }
}