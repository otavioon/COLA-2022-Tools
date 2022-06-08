#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

int N;
int A[222222];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    multiset<int>s;
    rep(i,N)s.insert(A[i]);
    int ans=0;
    while(s.size()>1){
        int x=*s.rbegin();
        s.erase(--s.end());
        int y=(1ll<<__lg(x)+1)-x;
        if(s.find(y)!=s.end()){
            s.erase(s.find(y));
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}