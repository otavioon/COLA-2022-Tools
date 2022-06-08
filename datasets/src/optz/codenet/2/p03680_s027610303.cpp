#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n, x;
  cin >> n;
  vector<int> b;
  rep(i, n) {
    cin >> x;
    x--;
    b.push_back(x);
  }
  int now, c;
  while(true){
    if(now == 1) {
      cout << c << endl;
      break;
    }
    if(c >= n){
      cout << -1 << endl;
      break;
    }
    now = b[now];
    c++;
  }
}
