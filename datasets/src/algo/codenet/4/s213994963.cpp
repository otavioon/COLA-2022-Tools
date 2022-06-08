#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <map>
#include <utility>
#include <numeric>
#include <chrono>
#include <ctime>
#include <bitset>

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define P pair<int, int>
#define debug(x) cerr << #x << ": " << x << ", "
#define debugln(x) cerr << #x << ": " << x << '\n'

using namespace std;
using ll = long long;
const ll mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k; cin >> n >> k;
  vector<bool> notuse(10);
  rep(i, k) {
    int d; cin >> d;
    notuse.at(d) = true;
  }

  for(int i = n;; i++) {
    bool flag = true;
    int tmp = i;
    while (tmp > 0) {
      int rem = tmp%10;
      if (notuse.at(rem)) {
        flag = false;
        break;
      }
      tmp /= 10;
    }
    if (flag) {
      cout << i << endl;
      return 0;
    }
  }

}