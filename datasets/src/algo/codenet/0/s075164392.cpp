#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef int ftype;
typedef complex<ftype> point;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second 
#define debug(x)  do{cerr<<#x<<": "<<x<<"\n";}while(0)
#define debugv(x) do{cerr<<#x<<": ";for(auto&e: (x))cerr<<e<<" ";cerr<<"\n";}while(0)
#define fori(i, n) for (int i = 0; i < (int)(n); ++i)
#define forn(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n); i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define RETURN(x) do{cout << x << '\n'; return 0;}while(0)
#define FIRSTWIN do{cout << "Monocarp\n"; return 0;}while(0)
#define SECONDWIN do{cout << "Bicarp\n"; return 0;}while(0)

const int MAXN = 1e2+3;
const int MOD = 1e9+7;
const LL INF = 1e18+1;

char S[101];
LL K;
int C[3];
int E[2];

int main() {
#ifdef OJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> K;
    int N = strlen(S);

    if(N == 1) {
        cout << K/2 << endl;
        return 0;
    } else {
        int i;
        int c = 0;
        int k = 0;
        int f = 0;
        for(i = 1; i < N; i++) {
            if(S[i] == S[i-1]) {
                c++;
                f = i;
                break;
            }
        }
        
        if(!f) {
            cout << 0 << endl;
            return 0;
        } 

        i += 2;
        if(i >= N) {
            i -= N;
            k++;
        }

        while(i != f) {
            if(i && S[i] == S[i-1] || (i == 0 && S[0] == S[N-1])) {
                c++;
                i += 2;
            } else i++;

            if(i >= N) {
                i -= N;
                k++;

                if(k == K) {
                    cout << c << endl;
                    return 0;
                }
            }
        }

        LL ans = K/k*c;
        LL r = K%k;
        for(int i = 1; r;) {
            if(S[i] == S[i-1]) {
                ans++;
                i += 2;
            } else i++;

            if(i >= N) {
                r--;
                i -= N;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
