#include<bits/stdc++.h>
using namespace std;
int main() {
  set<int> s;
  for(int i = 0; i < 10; ++i) {
    s.insert(i);
  }
  string N;
  int K, x;
  cin >> N >> K;
  for(int i = 0; i <= K; ++i) {
    cin >> x;
    s.erase(x);
  }
  for(int i = 0; N[i]; ++i) {                                                            
    //cout << N[i]-'0' << endl;
    cout << *s.lower_bound(N[i]-'0');
  }
  puts("");
}
