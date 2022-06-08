#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
const double EPS = 1e-10;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define LCIN(n) LL(n);cin >> (n)
#define SCIN(n) string(n);cin >> (n)
#define YES(n) cout<<((n)? "YES" : "NO")<<endl
#define Yes(n) cout<<((n)? "Yes" : "No")<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) <<endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define ALL(obj) (obj).begin(),(obj).end()

#define P pair<int,int>
#define I vector<int>
#define pb(v) push_back(v)
#define V vector
#define rt return
#define rmsame(a) sort(ALL(a)),a.erase(unique(ALL(a)), a.end())
#define ENDL cout<<endl
#define MAXE(a,b) a=max(a,b)
#define MINE(a,b) a=min(a,b)

typedef string::const_iterator State;
class PalseError {};
class Edge{
public:
    int from,to,value;
    Edge(LL a,LL b,LL c){
        from = a;
        to = b;
        value = c;
    }
    Edge(LL a,LL b){
        from = a;
        to = b;
    }
};

int main(){
    CIN(N);
    I vec;
    V<LL> two;
    LL s = 1;
    for(int a = 0;a < 40;a++){
        two.push_back(s);
        s *= 2;
    }
    multiset<LL> se;
    REP(a,N){
        CIN(b);
        vec.push_back(b);
        se.insert(b);
    }
    LL ans = 0;
    while(!se.empty()){
        LL s = *max_element(ALL(se));
        se.erase(s);
        LL w = *upper_bound(ALL(two),s);
        if(se.find(w-s) != se.end()){
            se.erase(w-s);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
