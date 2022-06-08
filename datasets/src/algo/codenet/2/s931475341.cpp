#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  multiset<int> A;
  int atmp;
  while (cin >> atmp) {
    A.insert(atmp);
  }

  int nr_of_pairs = 0;

  while (!(A.empty())) {
    auto itr_max = --A.end();
    auto max = *itr_max;
    int i;
    for (i = 1; i <= max; i *= 2)
      ;
    if (A.find(i - max) != A.end()) {
      A.erase(A.find(i - max));
      ++nr_of_pairs;
    }
    A.erase(itr_max);
  }

  cout << nr_of_pairs << endl;
  return 0;
}