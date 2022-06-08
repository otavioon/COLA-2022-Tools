#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

bool chk(int n, vector<bool> &use){
  if(n == 0){
    return !use.at(0);
  }
  while(n != 0){
    if(use.at(n%10) == true) return false;
    n /= 10;
  }
  return true;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<bool> use(10, false);
  rep(i, k){
    int in;
    cin >> in;
    use.at(in) = true;
  }
  while(1){
    if(chk(n, use) == true){
      cout << n << endl;
      return 0;
    }
    n++;
  }
  return 0;
}