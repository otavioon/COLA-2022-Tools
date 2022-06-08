#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define INF 100000000
#define MAX 100001
//#define int ll
#define ll long long
#define ld long double
#define vi vector<int>
#define pa pair<ll, ll>
#define pb push_back
#define mp make_pair
 
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest&...rest) { cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC(type, c, n) vector<type> c(n);for(auto& i:c)cin>>i;
#define MAT(type, c, m, n) vector<vector<type>> c(m, vector<type>(n));for(auto& r:c)for(auto& i:r)cin>>i;
 
#define BR cout << "\n";
#define SP cout << " ";
#define ENDL cout<<endl;
#define OUT(d) cout<<(d);
#define OUTL(d) cout<<(d)<< "\n";
#define YES OUTL("YES")
#define Yes OUTL("Yes")
#define NO OUTL("NO")
#define No OUTL("No")
#define RET return 0;
 
#define REP(i, n) for(int i=0;i<(n);i++)
#define RREP(i, n) for(int i=n-1;i>=0;--i)
#define FOR(i, m, n) for(int i = m;i < n; i++)
#define RFOR(i, a, b) for(int i=(a)-1;i>=(b);--i)
#define AREP(a, n) for(auto (a):(n))
#define ALL(a) (a).begin(),(a).end()
#define IN(n, a, b) ((a)<=(n)&&(n)<(b))

signed main(){ INIT;
    MAT(int, c, 3, 3);
    REP(i, 101) REP(j, 101) REP(k, 101){
        if(c[0][0] - i == c[1][0] - j && c[0][0] - i == c[2][0] - k &&
           c[0][1] - i == c[1][1] - j && c[0][1] - i == c[2][1] - k &&
           c[0][2] - i == c[1][2] - j && c[0][2] - i == c[2][2] - k){
                Yes; RET;
            }
    }
    No;
RET;}
