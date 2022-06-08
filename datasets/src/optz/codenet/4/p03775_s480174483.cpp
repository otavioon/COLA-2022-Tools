#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    ll N;
    cin>>N;
    set<ll>primelist;
    ll K=N;
    for(ll i=1;i<=sqrt(N);i++){
        if(K%i==0){
            primelist.insert(i);
        }
    }
    ll A=*rbegin(primelist);
    string S=to_string(A);
    string T=to_string(N/A);
    cout<<max(S.size(),T.size())<<endl;
}