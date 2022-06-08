#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <cmath>
#include <set>

using namespace std;

int main() {
  int n,l;
  cin >> n;
  
  int result = 0;

  set<int> ls;
  for (int i = 0; i < n; i++) {
    cin >> l;
    
    for (const auto& l2 : ls) {
      auto i1 = ls.lower_bound(l+l2); //条件を満たす最大+1
      auto i2 = ls.upper_bound(abs(l-l2)); //条件を満たす最小
      
      int d = distance(i2,i1);
      
      //cout << l << "," << l2 << ",," << *i1 << "," << *i2 << "," << d << endl;
      if (d > 0) {
        if (l<l2+l2) {
          d--; //l,l2,l2の組み合わせが引っ掛かった場合
        }

        result += d;
      }      
    }
    
    ls.emplace(l);
  }
  
  result = result/2; // 同じ組み合わせ2回ずつ計算されているので対応
  
  cout << result << endl;
}