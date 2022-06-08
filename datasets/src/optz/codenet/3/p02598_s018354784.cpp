#include"bits/stdc++.h"

using namespace std; 

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef pair<LL, LL> PLL;
typedef vector<PLL> VPLL;
typedef priority_queue<LL> PQ_DESC;
typedef priority_queue<LL, VL, greater<LL>> PQ_ASC;
typedef priority_queue<PII> PQ_DESC_PII;
typedef priority_queue<PII, vector<PII>, greater<PII>> PQ_ASC_PII;
typedef priority_queue<VL> PQ_DESC_VL;
typedef priority_queue<VL, vector<VL>, greater<VL>> PQ_ASC_VL;
typedef priority_queue<PLL> PQ_DESC_PLL;
typedef priority_queue<PLL, vector<PLL>, greater<PLL>> PQ_ASC_PLL;

#define ALL(c) (c).begin(),(c).end()
#define PB push_back
#define MP make_pair
#define SORT_ASC(c) sort(ALL(c))
//#define SORT_DESC(c) sort(ALL(c), greater<typeof(*((c).begin()))>())
#define SORT_DESC(c) sort((c).rbegin(),(c).rend())
#define REV(c) reverse((c).begin(), (c).end())
#define SIZE(a) int((a).size())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(b-1);i>=(a);--i)
#define REP(i,n) FOR(i,0,n)
#define PER(i,n) ROF(i,0,n)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int LARGE_INT = 1e9+100;
const int INF = 2e9+100;
const LL INF_LL = (LL)INF*(LL)INF;
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

LL n,k;
VL a;

bool isOK(LL mid){
    LL cut = 0;
    REP(i,n){
        cut += (a[i]+mid-1)/mid -1;
    }
    if(cut<=k){
        return true;
    }
    else{
        return false;
    }
}

void Main()
{
    cin>>n>>k;

    a.resize(n);
    REP(i,n){
        cin>>a[i];
    }

    LL ng = 0;
    LL ok = INF ;

    while (abs(ok - ng) > 1) {
        LL mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    cout<<ok<<endl;

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