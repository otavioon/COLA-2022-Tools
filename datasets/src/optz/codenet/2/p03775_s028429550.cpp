#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

uint64_t N;

pair<uint64_t, uint64_t> dv(uint64_t n, uint64_t d) {

  uint64_t e = 0;

  while (n % d == 0) {
    ++e;
    n /= d;
  }

  return make_pair(n, e);
}

map<uint64_t, uint64_t> factorize(uint64_t n) {

  map<uint64_t, uint64_t> ret;

  {
    auto e = dv(n, 2);
    if (e.second) {
      ret[2] = e.second;
      n = e.first;
    }
  }

  for (uint64_t d = 3; d * d < n; d += 2) {
    auto e = dv(n, d);
    if (e.second) {
      ret[d] = e.second;
      n = e.first;
    }
  }
  if (1 < n)
    ret[n] = 1;

  return ret;
}

vector<uint64_t> divsors(const map<uint64_t, uint64_t> &factorize) {

  vector<uint64_t> ret = {1};

  for (const auto &p : factorize) {
    const auto i_size = ret.size();

    for (uint64_t i = 0; i < i_size; ++i) {
      auto n = ret[i];

      for (uint64_t j = 0; j < p.second; ++j) {
        n *= p.first;
        ret.push_back(n);
      }
    }
  }

  return ret;
}

uint64_t scale(uint64_t n) {
  uint64_t ret = 1;

  while (n /= 10)
    ++ret;

  return ret;
}

int main() {

  cin >> N;
  auto m = factorize(N);
  auto v = divsors(m);
  sort(v.begin(), v.end());

  auto larger = v[v.size() / 2];

  cout << scale(larger) << endl;

  return 0;
}
