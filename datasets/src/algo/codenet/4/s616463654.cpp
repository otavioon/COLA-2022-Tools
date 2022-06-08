#include <bits/stdc++.h>
using namespace std;

#define DUMP(x) cerr << #x << "=" << x << endl
#define DUMP2(x, y) cerr<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")"<< endl
#define BINARY(x) static_cast<bitset<16> >(x)

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)

#define in_range(x, y, w, h) (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()

typedef long long ll;
const int INF = 1e9;
typedef pair<int, int> PII;
int dx[4]={0, -1, 1, 0}, dy[4]={-1, 0, 0, 1};
set<int> S;

bool check(int N)
{
    stringstream ss;
    string NS; 
    ss << N; ss >> NS;

    for (auto i : NS) {
        if (S.count(i-'0')) return false;
    }

    return true;
}


int main()
{
    int N, K;
    cin >> N >> K;
    rep(i, K) {
        int D; cin >> D;
        S.insert(D);
    }

    int ans = N;
    while (true) {
        if (check(ans)) {
            cout << ans << endl;
            return 0;
        }
        ans++;
    }
}

