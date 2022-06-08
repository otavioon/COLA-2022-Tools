#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,n) for(int i=1;i<=(int)(n);i++)
#define rep3(i,n) for(int i=0;i<=(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
#define repll(i,n) for(ll i=0;i<(ll)(n);i++)
#define repll2(i,n) for(ll i=1;i<=(ll)(n);i++)
#define REPLL(i,m,n) for(ll i=m;i<(ll)(n);i++)
#define INF 1000000000 //
#define LINF (ll)4000000000000000000 //
#define MOD (ll)1000000007
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define PI 3.1415926535898
#define NP(v) next_permutation(v.begin(),v.end())

//------------------------------------------------------

int main() {
    int n, k;
    cin >> n >> k;
    set<char> NG;

    rep(i, k) {
        char d;
        cin >> d;
        NG.insert(d);
    }

    int i = n;
    while (1) {
        string s = to_string(i);
        bool can = true;
        for (auto c : s) {
            if (NG.count(c)) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << i << endl;
            return 0;
        }
        i++;
    }

    return 0;
}