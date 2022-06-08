#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N); 
  for (int i = 0; i < N; i++)
    cin >> s.at(i);
  
  int M;
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++)
    cin >> t.at(i);
  
  int s_count;
  int t_count;
  int max = 0;
  
  for (int i = 0; i < N; i++) {
    s_count = 0;
    t_count = 0;
    
  	for (int j = 0; j < N; j++) {
      if (s.at(i) == s.at(j))
        s_count++;
    }
    
    for (int j = 0; j < M; j++) {
      if (s.at(i) == t.at(j))
        t_count++;
    }
    
    if (s_count - t_count > max)
      max = s_count - t_count;
  } 
  
  cout << max << endl;
}
