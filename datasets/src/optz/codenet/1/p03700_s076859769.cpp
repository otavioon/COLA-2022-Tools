#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int N, A, B; scanf("%d %d %d", &N, &A, &B);
  vector<int> H(N);
  int hmax = 0;
  for (int i = 0; i < N; ++i) {
    scanf("%d", &H[i]);
    hmax = max(hmax, H[i]);
  }

  priority_queue<int> que(H.begin(), H.end());
  int ans = 0;
  while (not que.empty()) {
    int hp = que.top(); que.pop();
    if (hp <= 0) { break; }
    hp -= A;
    ++ans;
    que.push(hp);
  }
  printf("%d\n", ans);
  return 0;
}
