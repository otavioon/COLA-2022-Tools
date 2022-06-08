#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  long long K;
  scanf("%lld", &K);

  if (S.length() == 1) {
    long long ans = K / 2;
    printf("%lld", ans);
    return 0;
  }
  
  long long replace_num = 0;
  for (int i = 0; i < S.length() - 1; i++) {
    long long duplicate_num = 0;
    if (S.at(i) == S.at(i + 1)) {
      int end = 0;
      for (int j = i + 1; j < S.length(); j++) {
        if (S.at(i) == S.at(j)) {
          duplicate_num++;
          end = j;
          continue;
        } else {
          end = j - 1;
          break;
        }
      }
      replace_num += (duplicate_num + 1) / 2;
      i = end;
    }
  }

  long long ans = replace_num * K;
  if (S.at(0) != S.at(1) || S.at(S.length() - 1) != S.at(S.length() - 2)) {
    if (S.at(0) == S.at(S.length() - 1)) {
      ans += K - 1;
    }
  }

  printf("%lld", ans);
  return 0;
}
