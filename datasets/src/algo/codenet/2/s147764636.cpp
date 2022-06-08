#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <list>

#define N 100000

using namespace std;
typedef long long ll;

int main() {
  ll i, j;
  ll temp;
  int n;
  int n_check = 0;

  scanf("%d", &n);
  // array<ll, N> ar;
  vector<ll> v(n);
  // list<ll> ar;
  for (i = 0; i < n; i++) {
    scanf(" %lld", &v[i]);
    // scanf(" %lld", &temp);
    // ar.push_back(temp);
    n_check++;
  }
  // printf("%d", n_check);

  // for (i = 0; i < n; i++) {
  //   printf("%lld\n", ar[i]);
  // }
  // printf("end\n");

  // sort(v.begin(), v.end());
  // ar.sort();
  // list<ll> ar(v.begin(), v.end());
  vector<ll> ar = v;

  int count = 0;
  ll last, max_v;
  vector<ll>::iterator max_i;
  while (ar.size()) {
    max_i = max_element(ar.begin(), ar.end());
    max_v = *max_i;
    last = max_v;
    // last = ar.back();
    // cout << "last: " << last << endl;
    // ar.pop_back();
    ar.erase(max_i);
    for (auto x = ar.begin(); x != ar.end(); ++x) {
      temp = *x + last;
      if (!(temp & (temp - 1))) {
        count++;
        ar.erase(x);
        break;
      }
    }
  }

  printf("%d", count);

  
  return 0;
}