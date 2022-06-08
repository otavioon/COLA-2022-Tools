#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI=3.14159265358979323846;
using namespace std;
vector<int> dy={1,0,-1,0};
vector<int> dx={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    int n;
    cin>>n;
    vector<int> l(n);
    rep(i,n) cin>>l[i];
    sort(all(l));
    
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int left=max((int)(lower_bound(all(l),l[i]+l[j])-l.begin()),j+1);
            int right=max((int)(upper_bound(all(l),abs(l[i]-l[j]))-l.begin()),j+1);
            ans+=left-right;
            //cout<<right<<" "<<left<<endl;
        }
    }
    cout<<ans<<endl;
}
