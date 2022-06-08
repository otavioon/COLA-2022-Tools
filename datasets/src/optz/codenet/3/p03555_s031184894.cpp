#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>


using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
const ll MOD = 1e9 + 7;
vi alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };



int main() {
    ll N;
    cin >> N;
    vll A(N);
    vll B(N);
    vll C(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];
    sort(A);
    sort(B);
    sort(C);
    ll ans = 0;
    rep(i, N) {
        ll b = B[i];
        ll counta = 0;
        ll countc = 0;
        auto a = lower_bound(all(A),b);
        auto c = upper_bound(all(C), b);
        counta = a - A.begin();
        countc = C.end() - c;
        ans += counta * countc;
    }
    cout << ans << endl;
}