#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <forward_list>
#include <random>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm( a, b ) (a)/__gcd((a),(b))*(b)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair< int, int > P;
typedef pair< LL, LL > LP;
typedef pair< int, P > iP;
typedef pair< P, P > PP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 500005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector< int > Div( int n ) {
    vector< int > ret;
    for( int i = 1; i * i <= n; ++i ) {
        if( n % i == 0 ) {
            ret.pb( i );

            if( i * i != n ) ret.pb( n / i );
        }
    }
    sort( all( ret ) );
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    LL k;
    cin >> k;
    LL cnt = 0;
    if( s[0] == s[s.size() - 1] && k > 1 ) {
        char tmp = s[0];
        int pos = 0;
        while( pos < s.size() && s[pos] == tmp ) {
            ++pos;

        }

        int r = s.size() - 1;
        while( r >= 0 && s[r] == tmp ) {
            --r;

        }
        if( pos == s.size() ) {
            if( s.size() % 2 != 0 ) {
                cnt = s.size() / 2 * k;
                cout << cnt + k / 2 << endl;
                return 0;

            }
            cout << s.size() / 2 * k << endl;
            return 0;

        }


        cnt = (pos + (s.size() - r - 1)) / 2 * (k - 1);
        LL tm = 0;
        for( int i = pos; i <= r; ++i ) {
            if( s[i] == s[i - 1] ) {
                ++tm;
                s[i] = '*';

            }
        }

        cnt += tm * k;
        cnt += pos / 2 + (s.size() - r - 1) / 2;
        cout << cnt << endl;
        return 0;

    }

    for( int i = 1; i < s.size(); ++i ) {
        if( s[i] == s[i - 1] ) {
            ++cnt;
            s[i] = '*';

        }
    }
    cout << cnt * k << endl;


    return 0;
}

