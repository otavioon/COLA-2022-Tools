#include <bits/stdc++.h>
using namespace std;

vector<long long> divisor(long long N) {
  vector<long long> res;
  for (long i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      res.push_back(i);
      if (i != N / i) {
        res.push_back(N / i);
      }
    }
  }
  return res;
}

long long F(long long A, long long B) {
  long long result = 0;
  long long countA = to_string(A).size();
  long long countB = to_string(B).size();
  return max(countA, countB);
}

int main() {

  long long N;
  cin >> N;

  vector<long long> d = divisor(N);

  long long answer = 1LL<<60;

  for (int i = 0; i < d.size() - 1; i++) {
    long long f = F(d[i], d[i+1]);
    answer = min(answer, f);
  }

  if (answer == 1LL<<60) {
    answer = 1;
  }
  
  cout << answer << endl;

  return 0;

}