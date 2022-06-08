#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
ll inf = LLONG_MAX;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

void bfs(ll n, vector<vll> &next, vll &cnt, ll start) {
  queue<ll> task;
  task.push(start);
  vll seen(n, 0);
  seen[start] = 1;
  ll depth = 0;
  while (task.size() > 0) {
    ll width = task.size();
    for (ll i = 0; i < width; i++) {
      for (ll j = 0; j < next[task.front()].size(); j++) {
        if (seen[next[task.front()][j]] == 0) {
          cnt[next[task.front()][j]] += cnt[task.front()];
          task.push(next[task.front()][j]);
          seen[next[task.front()][j]] = 1;
        }
      }
      task.pop();
    }
    depth++;
  }
  return;
}

int main() {
  ll n, q;
  cin >> n >> q;
  vll a(n - 1), b(n - 1);
  for (ll i = 0; i < n - 1; i++) cin >> a[i] >> b[i];
  vll p(q), x(q);
  for (ll i = 0; i < q; i++) cin >> p[i] >> x[i];
  vector<vll> next(n, vll(0));
  for (ll i = 0; i < n - 1; i++) {
    next[a[i] - 1].push_back(b[i] - 1);
    next[b[i] - 1].push_back(a[i] - 1);
  }
  vll cnt(n, 0);
  for (ll i = 0; i < q; i++) {
    cnt[p[i] - 1] += x[i];
  }
  bfs(n, next, cnt, 0);
  for (ll i = 0; i < n - 1; i++) cout << cnt[i] << " ";
  cout << cnt[n - 1] << endl;
}