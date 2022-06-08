#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n;
  map<string, int> blue, red;
  vector<string> s;
  for (int i = 0; i < n; i++){
    string x;
    cin >> x;
    blue[x]++;
    s.push_back(x);
  }

  cin >> m;
  for (int i = 0; i < m; i++){
    string x;
    cin >> x;
    red[x]++;
  }

  int ans = -1e9;
  for (int i = 0 ; i < s.size(); i++){
    ans = max(ans, blue[s[i]] - red[s[i]]);
  }
  if (ans < 0) ans = 0;
  cout << ans << endl;
  return 0;
}