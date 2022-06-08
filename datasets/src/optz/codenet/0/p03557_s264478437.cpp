#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main(){
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) cin >> c[i];

  int res = 0;
  rep(i, n){
    auto key = b[i];
    auto iter1 = upper_bound(a.begin(), a.end(), key);
    auto iter2 = lower_bound(c.begin(), c.end(), key);
    auto num1 = distance(a.begin(), iter1);
    auto num2 = c.size() - distance(c.begin(), iter2);
    res += num1*num2;
  }
  cout << res << endl;
}
