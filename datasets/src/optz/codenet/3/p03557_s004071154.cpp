#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// マクロ
// forループ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(ll)(b);i--)
// xにはvectorなどのコンテナ
#define ALL(x) (x)begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
// 出力
#define PRINT(x) cout<<(x)<<endl
#define PRINTA(x,n) REP(i,n)PRINT(x[i])
// 定数
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
// 略記
#define PB push_back
#define MP make_pair

const int MAX_N = 100000;

int N, A[MAX_N], B[MAX_N], C[MAX_N];

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) cin >> C[i];

    sort(A, A + N);
    sort(C, C + N);

    ll ans = 0;
    REP(i, N) {
        ll a = lower_bound(A, A + N, B[i]) - A;
        ll c = N - (lower_bound(C, C + N, B[i] + 1) - C);
        ans += a * c;
    }
    PRINT(ans);
    return 0;
}