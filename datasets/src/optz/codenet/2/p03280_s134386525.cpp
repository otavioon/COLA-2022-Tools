#include <cstdio>
#include <vector>

using namespace std;

const int N_MAX = 500;
const int M_MAX = 200000;
const int Q_MAX = 100000;

int N, M, Q;
int L[M_MAX + 1], R[M_MAX + 1];
int p[Q_MAX + 1], q[Q_MAX + 1];

vector<vector<int> > memo(N_MAX + 2);

void solve() {
  for (int i = 0; i < M; i++) {
    int l = L[i];
    for (int j = 0; j < l; j++) {
      memo[j].push_back(i);
    }
  }

  for (int i = 0; i < Q; i++) {
    int start_at = p[i];
    int end_at = q[i];

    vector<int> start_list = memo[start_at - 1];
    int list_size = start_list.size();
    int cnt = 0;
    for (int j = 0; j < list_size; j++) {
      int l_idx = start_list[j];
      if (R[l_idx] <= end_at) cnt++;
    }
    printf("%d\n", cnt);
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &Q);
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &L[i], &R[i]);
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d %d", &p[i], &q[i]);
  }
  solve();
}
