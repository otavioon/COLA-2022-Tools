#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int N, res = 0;
  cin >> N;
  multiset<ll> st;
  for (int i = 0; i < N; i++) {
    int a; cin >> a; st.insert(a);
  }

  while (!st.empty()) {
    int t = *st.rbegin();
    int n = 1;
    while(t > n) {
      n *= 2;
    }
    
    st.erase(st.find(t)); 
    auto e = st.find(n - t);
    if (e != st.end()) {
      res++;
      st.erase(e); 
    }
  }
  
  cout << res << endl;
}
