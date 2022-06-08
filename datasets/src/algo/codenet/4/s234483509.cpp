//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,k; cin>>n>>k;
    int ans=n;
    set<int> se;
    rep(i,k){
        int d; cin>>d;
        se.insert(d);
    }
    while(1){
        string s=to_string(ans);
        int cnt=0;
        for(auto ch:s)if(se.count(ch-'0')) cnt++;
        if(cnt==0) break;
        ans++;
    }
    cout<<ans<<endl;
}