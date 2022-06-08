#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

#define rep(i,N) for(int i=0;i<(int)N;++i)

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}
int main()
{
    vector<vector<char> > C((2), vector<char>(3));

    cin >> C[0][0] >> C[0][1] >> C[0][2];
    cin >> C[1][0] >> C[1][1] >> C[1][2];

    if (C[0][0] == C[1][2] && C[0][1] == C[1][1] && C[0][2] == C[1][0]) { cout << "YES" << endl; }
    else { cout << "NO" << endl; }

}