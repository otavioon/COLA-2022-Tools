#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  vector<string> s(N);
  vector<int> sum(N);
  for(int i = 0; i < N; i++)
    cin >> s.at(i);
  cin >> M;
  vector<string> t(M);
  for(int i = 0; i < M; i++)
    cin >> t.at(i);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(s.at(i) == s.at(j))
        sum.at(i) += 1;
    }
    for(int j = 0; j < M; j++){
      if(s.at(i) == t.at(j))
      sum.at(i) -= 1;
    }
    if((i ==0) && (sum.at(i) < 1))
      sum.at(i) = 1;
    if((i > 0) && (sum.at(i) < sum.at(i - 1)))
      sum.at(i) = sum.at(i - 1);
  }
  cout << sum.at(N - 1) - 1 << endl;
}
