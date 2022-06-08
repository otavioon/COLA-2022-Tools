
#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits>
#include <map>
#include <numeric>

#define ll long long
using namespace std;
static ll imin = std::numeric_limits<ll>::min();
static ll imax = std::numeric_limits<ll>::max();
#define rep(i, n) for(int i = 0; i<n; ++i)
#define rep1(i, n) for(int i = 1; i<n; ++i)
#define rev_rep(i, n) for(int i = n - 1; i >= 0; --i)
#define dump(x) cout << #x << ":" << x << "\n";
#define all(v) v.begin(), v.end()

template<class T1, class T2>
std::ostream& operator << (std::ostream& os, std::pair<T1, T2>& pair){
  os << '(' << pair.first << ',' << pair.second << ')';
  return os;
}
template<class T>
std::ostream& operator << (std::ostream& os, std::vector<T>& vec){
  std::size_t n = vec.size();
  if(n == 0){
    return os;
  }
  os << " ";
  for(int i = 0; i<n - 1; ++i){
    os << vec[i] << " ";
  }
  os << vec[n - 1];
  os << std::endl;
  return os;
}


#ifndef BOOST_TEST_MAIN
int main(int const argc, char const** argv){
  vector<vector<ll>> c(3);
  rep(i, 3){
    rep(j, 3){
      ll p;
      cin >> p;
      c[i].push_back(p);
    }
  }
  // dump(c);
  ll a1, a2;
  a1 = c[0][1] - c[0][0];
  a2 = c[0][2] - c[0][0];
  rep(i, 3){
    if(!(a1 ==  c[i][1] - c[i][0] && a2 == c[i][2] - c[i][0])){
      cout << "No";
      return 0;
    }
  }

  a1 = c[1][0] - c[0][0];
  a2 = c[2][0] - c[0][0];
  rep(i, 3){
    if(!(a1 ==  c[1][i] - c[0][i] && a2 == c[2][i] - c[0][i])){
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
#endif
