#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <functional>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpll = vector<pll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define Rep(i, n) for (long long i = 0; i< (long long)(n); i++)
#define RRep(i,n) for (long long i = ((long long)(n)-1); i>=0; i--)
#define all(v) (v).begin(),(v).end()

struct Edge{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w){ }
};

using Graph = vector<vector<Edge>>;
using graph = vector<vector<int>>;

template <class T>
inline bool chmin(T &a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
T gcd(T a, T b){
    if( b==0 ) return a;
    return gcd(b, a%b);
}

template <class T>
T lcm(T a, T b){
    return (a*b)/gcd(a,b);
}

const int INF = 1e9+7;

vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,-1,0,1};

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n),b(n),c(n);
    Rep(i,n) cin >> a[i];
    Rep(i,n) cin >> b[i];
    Rep(i,n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    vector<ll> m(n);
    Rep(i,n){
        auto x = lower_bound(all(a),b[i]);
        m[i] = x-a.begin();
    }
    Rep(i,n-1){
        m[i+1]+=m[i];
    }
    ll ans = 0;
    Rep(i,n){
        auto x = lower_bound(all(b),c[i]);
        if(x-b.begin()==0) continue;
        ans += m[x-b.begin()-1];
    }
    cout << ans << endl;
}