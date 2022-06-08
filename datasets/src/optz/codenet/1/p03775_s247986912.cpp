#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll n, ans, divisor = 1, half, prev = 1;
  vector<ll> div_v;
  cin >> n;
  half = n / 2 + 1;
  for (int i = 2; i < half; i+=2){
    if (n % i == 0){
      divisor = i;
      if (prev * i == n || i * i == n){
        break;
      }else{
        prev = i;
      }
    }
  }
  ans = max(n / divisor, divisor);
  cout << (to_string(ans)).size() << endl;
  return 0;
}
