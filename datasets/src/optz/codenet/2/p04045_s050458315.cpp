#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,K; cin>>N>>K;
    vector<int> D(K);
    rep(k,0,K) cin>>D.at(k);

    set<int> setN{0,1,2,3,4,5,6,7,8,9};
    for(auto d:D) setN.erase(d);

    string S=to_string(N),ans;
    bool over=false;
    rep(i,0,S.size()){
        int sN;
        if(over) sN=0;
        else sN=S.at(i)-'0';

        rep(j,sN,10){
            if(setN.count(j)){
                ans+='0'+j;
                if(j>sN) over=true;
                break;
            }
        }
    }

    cout<<ans<<endl;
}