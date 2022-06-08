#include <bits/stdc++.h>
using namespace std;

#define what_is(x)    cerr<<#x<<" is "<<x<<"\n";
#define rep(i,a,n)    for(int i=a; i<=n; ++i)
#define rep1(i,a,n)   for(int i=a; i>=n; --i)
#define pb            push_back
#define mp            make_pair
#define int           long long
#define fr            first
#define sc            second
#define vc            vector
#define sz(v)         (int)v.size()
#define all(x)        (x).begin(),(x).end()
#define rall(x)       (x).rbegin(),(x).rend()
#define M             1000000007
#define MM            998244353
#define PI            3.14159265358979
#define INF           1000000000000000

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;

int n,m,ans; string str;

int solve(){
    cin>>n>>m;
    m*=2; m++;
    cout<<(n-m+1)/m;
    return 0;
}

signed main() {
    ios::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}