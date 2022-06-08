#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,o,cnt1,maxcnt1=0,cnt2,maxcnt2=0,answer=0;
  cin >> N;
  vector<string> s(N);
  vector<string> word;
  vector<string> delword = { "" };
  
  for (int i = 0; i < N; i++) {
    cin >> s.at(i);
  }
  
  int M;
  cin >> M;
  vector<string> t(M);
  
  for (int j = 0; j < M; j++) {
    cin >> t.at(j);
  }

  for (int o =0; o < N; o++) {
    //　重複チェック
    for (int k = 0; k < N; k++) {
      cnt1 = 0;
      for (int l = 0; l < N; l++) {
        if (s.at(k) == s.at(l)) {
          cnt1++;
        }
        if (maxcnt1 <= cnt1 && s.at(l) != delword.at(0)) {
          maxcnt1 = cnt1;
          word = {s.at(l)};
        }
      }
    }
    //　重複チェック
    maxcnt2 = 0;
    for (int m = 0; m < M; m++) {
      if (word.at(0) == t.at(m) && t.at(m) != delword.at(0)) {
        maxcnt2++;
      }
    }
    // 最終チェック
    if (maxcnt1 < maxcnt2) {
      delword = word;
      maxcnt1 = 0;
    } else {
      answer = maxcnt1 - maxcnt2;
      break;
    }
  }
  cout << answer << endl;
}