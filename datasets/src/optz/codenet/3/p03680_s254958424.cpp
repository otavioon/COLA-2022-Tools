#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  unordered_set<int> visit;
  int now = 1;
  int answer = 0;
  while (true) {
    if (visit.count(now)) {
      cout << -1 << endl;
      return 0;
    }
    visit.emplace(now);
    now = A[now];
    ++answer;
    if (now == 2) break;
  }
  cout << answer << endl;
  return 0;
}
