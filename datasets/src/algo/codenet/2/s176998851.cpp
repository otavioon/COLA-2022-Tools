#include <iostream>
#include <cstdint>
#include <set>
#include <cmath>
using namespace std;

int main() {
  int32_t n;
  cin >> n;
  multiset<int32_t> set;
  for (int32_t i = 0; i < n; i++) {
    int32_t tmp;
    cin >> tmp;
    set.insert(tmp);
  }

  int32_t count = 0;
  auto itr = set.rbegin();
  while ( itr != set.rend() ) {
    int32_t ball = *itr;
    set.erase(*itr);
    for (auto itr2 = set.rbegin(); itr2 != set.rend(); itr2++) {
      int32_t sum = ball + *itr2;
      double radicand = log(sum) / log(2);
      if ( floor(radicand) == radicand ) {
        count++;
        set.erase(*itr2);
        break;
      }
    }
  }
  cout << count << endl;
}
