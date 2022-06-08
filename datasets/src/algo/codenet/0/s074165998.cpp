#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <map>

#define FOR0(var, max) for (ul (var) = 0; (var) < (max); ++(var))
#define FORi(var, min, max) for (ul (var) = (min); (var) < (max); ++(var))
#define FORi_INV(var, min, max) for (ul (var) = (max) - 1; (var) + 1 > (min); --(var))
#define FORITER(var, iter) for (auto (iter) = (var).begin(); (iter) != (var).end(); (iter)++)
#define FORITER_INV(var, iter) for (auto (iter) = (var).rbegin(); (iter) != (var).rend(); (iter)++)

#define LTLT(a, b, c) (((a) < (b)) && ((b) < (c)))
#define LELT(a, b, c) (((a) <= (b)) && ((b) < (c)))
#define LTLE(a, b, c) (((a) < (b)) && ((b) <= (c)))
#define LELE(a, b, c) (((a) <= (b)) && ((b) <= (c)))

using namespace std;

using uc = unsigned char;
using ui = unsigned int;
using ul = unsigned long long int;

using sc = signed char;
using si = signed int;
using sl = signed long long int;

template <class T>
T gcd(T a, T b) {
  while (b) {
    T t = a % b;
    a = b;
    b = t;
  }
  return a;
}

const static ui SMAX = 100;
const static ui KMAX = 1000000000;

static ul K;
static string S;

void solve(void) {
  string str = S + S;
  ul c1 = 0, c2 = 0;
  FOR0(i, str.size()) {
    if (str[i] == str[(i + 1) % str.size()]) {
      str[i] = 'A';
      if (i < S.size()) {
        c1++;
      } else {
        c2++;
      }
    }
  }
  string str2 = S + S;
  ui c3 = 0, c4 = 0;
  FORi(i, 1, str2.size()) {
    if (str2[i - 1] == str2[i]) {
      str2[i] = 'A';
      if (i < S.size()) {
        c3++;
      } else {
        c4++;
      }
    }
  }
  ul r1 = (c1 * ((K + 1) / 2) + c2 * (K / 2));
  ul r2 = (c3 * ((K + 1) / 2) + c4 * (K / 2));
  if (r1 == 0 || r2 == 0) {
    if (r1 == r2) {
      cout << 0 << endl;
    } else {
      cout << max(r1, r2) << endl;
    }
  } else {
    cout << min(r1, r2) << endl;
  }
}

int main(void) {
  cin >> S;
  cin >> K;
  solve();
  return 0;
}