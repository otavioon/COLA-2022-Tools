#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

int main() {
    string s; cin >> s;
    ll k; cin >> k;
    set<char> st;

    REP(i, s.size()) {
        st.insert(s[i]);
    }

    ll tmp_c = 0;
    bool prev_change = false;
    REP(i, s.size()) {
        if (i == 0) {
            continue;
        } else {
            if (s[i] == s[i-1]) {
                if (prev_change) {
                    prev_change = false;
                } else {
                    tmp_c++;
                    prev_change = true;
                }
            } else {
                if (prev_change) {
                    prev_change = false;
                } else {
                }
            }
        }
    }
    if (st.size() == 1) {
        cout << s.size() * k / 2 << endl;
    } else if (s[0] != s[s.size()-1]) {
        cout << tmp_c * k << endl;
    } else {
        ll a = 0;
        ll b = 0;
        REP(i, s.size()) {
            if (s[i] == s[0]) {
                a++;
            } else {
                break;
            }
        }
        REP(i, s.size()) {
            if (s[s.size()-i-1] == s[0]) {
                b++;
            } else {
                break;
            }
        }
        cout << tmp_c * k - (a/2 + b/2 - (a+b)/2) * (k-1) << endl;
    }
    return 0;
}