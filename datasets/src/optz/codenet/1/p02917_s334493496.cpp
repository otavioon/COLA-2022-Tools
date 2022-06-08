#include<bits/stdc++.h>
using namespace std;
#define found(m,x) ((m).find(x)!=(m).end())
#define uset unordered_set
#define umap unordered_map
#define db(x) cerr << #x << " == " << x << ";\n";
#define a(x) x.begin(),x.end()
#define input(v,n) for(int i=0;i<n;i++)cin>>v[i]
typedef vector<int> vi;
typedef pair<int,int> pi;

const int nax = 1e5+7;
const int mod = 1e9+7; //1e9+2667
const int inf = numeric_limits<int> :: max();
// ===================== MANASH =================== //

int n,m;

void test() {

    cin >> n;
    vector<int> B;
    B.push_back(inf);
    for ( int i = 0; i < n-1; i++ ) {
         int t;
         cin >> t;
         B.push_back(t);
    }
    B.push_back(inf);

    int s = 0;
    for( int i = 1; i <= n; i++) {
        s += min(B[i-1],B[i]);
    }

    cout << s;

}

signed main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    cout<<"Time Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec.\n";
    #endif

    int T = 1;
    //cin >> T;
    while(T--) {
        test();
        cout << "\n";
    }
    return 0;

}