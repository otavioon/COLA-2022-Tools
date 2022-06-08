#include<bits/stdc++.h>

#define fi first
#define se second
#define FO(x, n) for (int x = 0; x < n; ++x)
#define FOR(x, a, b) for (int x = a; x < b; ++x)
#define RFO(x, n) for (int x = n - 1; x >= 0; --x)
#define RFOR(x, a, b) for (int x = b - 1; x >= a; --x)
#define FOR_ITER(x, a) for(auto x = a.begin(); x != a.end(); ++x)

#define pb push_back
#define pf push_front
#define mp make_pair
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define VL vector<long long>
#define F first
#define S second

using namespace std;


typedef complex<double> P;
typedef unsigned char byte;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<ll, ll> pll;
inline bool feq(const double& a, const double& b) { return fabs(a - b) < 1e-10; }
inline int gcd(int a, int b) {
    if (b == 0) return a;
    return a < b? gcd(b, a) : gcd(b, a % b);
}
ll mo=1000000007;
const ll INF = 1e18;

int main(){
    string n;
    int k;
    cin >> n >> k;
    set<int> cs;

    FO(i, 10) {
        cs.insert(i);
    }

    FO(i, k) {
        int t;
        cin >> t;
        cs.erase(t);
    }

    vector<int> cv(All(cs));
    sort(All(cv));

    int minNum = cv.front();
    int maxNum = cv.back();
    if (minNum == 0) {
        minNum = cv.at(1);
    }

    int bitNum = SZ(n);

    string maxBitNum = "";
    FO(i, bitNum) {
        maxBitNum.pb('0' + maxNum);
    }

    int rs = minNum;
    FO(i, bitNum + 1) {
        rs = rs * 10 + cv.front();
    }

    if (maxBitNum >= n) {
        FOR(i, stoi(n), rs) {
            string tmp = to_string(i);
            bool flag = true;
            FO (j, bitNum) {
                if (cs.count(tmp.at(j)) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << i << endl;
                break;
            }
        }
    } else {
        cout << rs << endl;
    }

    return 0;
}
