#include <iostream>      // cout, endl, cin
#include <string>        // string, to_string, stoi
#include <vector>        // vector
#include <algorithm>     // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility>       // pair, make_pair
#include <tuple>         // tuple, make_tuple
#include <cstdint>       // int64_t, int*_t
#include <cstdio>        // printf
#include <map>           // map
#include <queue>         // queue, priority_queue
#include <set>           // set
#include <stack>         // stack
#include <deque>         // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset>        // bitset
#include <cctype>        // isupper, islower, isdigit, toupper, tolower
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
        int N, M;
        cin >> N;
        map<string, int> sma, tma;

        vector<string> s(N + 1);
        rep(i, N) cin >> s[i];
        cin >> M;
        vector<string> t(M + 1);
        rep(i, M) cin >> t[i];
        int ans = 0;

        rep(i, N)
        {
                int cnt = 0;
                rep(j, N) if (s[i] == s[j]) cnt++;
                rep(j, M) if (s[i] == t[j]) cnt--;

                ans = max(ans, cnt);
        }

        cout << ans << endl;

        return 0;
}
