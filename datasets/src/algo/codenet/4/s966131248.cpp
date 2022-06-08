#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cassert>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<string, int> si;
typedef vector<string> vs;
const int INF = 1 << 29;
#define mp make_pair
#define fi first
#define se second
int n, k, digit;
set<int> d;

bool isFound(int num) {
    while (num != 0) {
        int last = num % 10;
        if (d.find(last) != d.end()) return false;
        num /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> digit;
        d.insert(digit);
    }
    int i;
    for (i = n; !isFound(i); i++);
    cout << i << endl;
    return 0;
}