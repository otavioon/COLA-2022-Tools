#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {

    int c[3][3];
    int sum = 0;
    REP(i, 3) REP(j, 3) {
        cin >> c[i][j];
        sum += c[i][j];
    }
    if (sum % 3 == 0 && sum / 3 == c[0][0] + c[1][1] + c[2][2]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}