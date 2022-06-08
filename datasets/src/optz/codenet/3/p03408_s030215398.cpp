#include <bits/stdc++.h>
#define loop(i, n) for (int i = 0; i < int(n); i++)
#define rep(i, begin, end) for (int i = int(begin); i < int(end); i++)
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  loop(i, N) cin >> s.at(i);

  int M;
  cin >> M;
  vector<string> t(M);
  loop(i, M) cin >> t.at(i);

  vector<int> score(N, 0);
  int ans = 0;

  loop(i, N) {
    loop(j, N) {
      if (s.at(i) == s.at(j)) score.at(i) += 1;
    }

    loop(j, M) {
      if (s.at(i) == t.at(j)) score.at(i) -= 1;
    }
  }

  loop(i, N) {
    if (ans < score.at(i)) ans = score.at(i);
  }

  cout << ans << endl;
}
