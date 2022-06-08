#include                            <iostream>
#include                            <list>
#include                            <stdio.h>
#include                            <math.h>
#include                            <string.h>
#include                            <time.h>
#include                            <stdlib.h>
#include                            <string>
#include                            <bitset>
#include                            <vector>
#include                            <set>
#include                            <map>
#include                            <queue>
#include                            <algorithm>
#include                            <sstream>
#include                            <stack>
#include                            <iomanip>
#include                            <numeric>
#include                            <unordered_map>



using namespace                     std;
#define MOD                         1000000007
#define int                         int64_t
#define baba_shiv                   ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mpii                        map<int,int>
#define pb                          push_back
#define mkp                         make_pair
#define all(x)                      x.begin(),x.end()
#define allr(x)                     x.rbegin(),x.rend()
#define ub(v,x)                     upper_bound(all(v),x)
#define lb(v,x)                     lower_bound(all(v),x)
#define gcd(a,b)                    __gcd(a,b)
#define lcm(a,b)                    (((a*b))/__gcd(a,b))
#define vi                          vector<int>
#define pii                         pair<int,int>
#define vpii                        vector<pii>
#define vs                          vector<string>
#define ff                          first
#define ss                          second
#define foru(v,s,e)                 for(int v=s;v<e;v++)
#define ford(v,s,e)                 for(int v=s;v>e;v--)

//int MOD;

inline void normal(int &a) { a %= MOD; (a < 0) && (a += MOD); }
inline int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a * b) % MOD; }
inline int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a + b) % MOD; }
inline int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline int modPow(int b, int p) { int r = 1; while (p) { if (p & 1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline int modInverse(int a) { return modPow(a, MOD - 2); }
inline int modDiv(int a, int b) { return modMul(a, modInverse(b)); }


/***********************************************************************************************************************/
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if ( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if ( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if ( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr<< #x << " = " << x << '\n';


/***********************************************************************************************************************/

int good(vi &arr, int x)
{
    int n = arr.size();
    int mov = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = arr[i];
        if (cur <= x)continue;
        mov += cur / x;
    }
    return mov;
}

signed main()
{
    baba_shiv;
    int T = 1;
    // cin >> T;
    foru(trr, 1, T + 1)
    {
        int n, k; cin >> n >> k;
        vi arr(n); foru(i, 0, n)cin >> arr[i];
        int ans = -1;
        int hi = 1e10, lo = 0;
        while (hi >= lo)
        {
            int mid = (hi + lo) / 2;
            if (good(arr, mid) <= k)
            {
                ans = mid;
                hi = mid - (int)1;
            }
            else
                lo = mid + (int)1;
        }
        cout << ans;



    }

}

