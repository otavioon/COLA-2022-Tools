#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define all(c) (c).begin(), (c).end()
#define debug(x) cerr << #x << " = " << x << endl
#define eb emplace_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> pw2(40);
  pw2[0] = 1;
  rep(i,1,40) pw2[i] = 2*pw2[i-1];

  int n;
  cin>>n;
  vector<int> v(n);
  unordered_map<int,int> m;
  rep(i,0,n) {
    cin>>v[i];
    ++m[v[i]];
  }
  int cnt = 0;
  for(int a:v) {
    if(--m[a] < 0) continue;
    for(int i = 32; i>=0; --i) {
      auto &r = m[pw2[i] - a];
      if(r > 0) {
        ++cnt;
        --r;
        break;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
