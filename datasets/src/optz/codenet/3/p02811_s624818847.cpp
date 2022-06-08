#include"bits/stdc++.h"

using namespace std; 

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long LL;
typedef priority_queue<int> PQ_DESC;
typedef priority_queue<int, vector<int>, greater<int>> PQ_ASC;
typedef priority_queue<PII> PQ_DESC_PII;
typedef priority_queue<PII, vector<PII>, greater<PII>> PQ_ASC_PII;

#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define MP make_pair
#define SORT_ASC(c) sort(ALL(c))
#define SORT_DESC(c) sort(ALL(c), greater<typeof(*((c).begin()))>())
#define SIZE(a) int((a).size())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(b-1);i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define REP(i,n) FOR(i,0,n)
#define PER(i,n) ROF(i,0,n)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int LARGE_INT = 1e9+100;
const int INF = 2e9+100;
const LL INF_LL = (LL)INF * 300 * 300;
const int MOD = 1e9+7;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

LL modpow(LL a, LL n) {
    LL res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

LL modinv(LL a) {
    LL b = MOD, u = 1, v = 0;
    while (b) {
        LL t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

LL moddev(LL a, LL b){
	return a * modinv(b) % MOD;
}

void Main()
{
    int k,x;
    cin >> k >> x;
    if(500*k >= x){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

	return;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
    return 0;
}