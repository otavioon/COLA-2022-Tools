#include <bits/stdc++.h>
#define INF 1000000000000000000
long long li(long long n)
{
  int a;
  for(a = 0; n != 0; a++) n /= 10;
  return a;
}
std::vector<long long> enum_div(long long n)
{
  std::vector<long long> ret;
  for(long long i=1 ; i*i<=n ; ++i){
    if(n%i == 0){
      ret.push_back(i);
      if(i!=1 && i*i!=n){
        ret.push_back(n/i);
      }
    }
  }
  return ret;
}

int main(void)
{
  long long n, ans = INF;
  std::cin >> n;
  std::vector<long long> r = enum_div(n);
  std::sort(r.begin(), r.end());
  for(auto i : r){
    if(i * i < n)
      ans = std::min(ans, std::max(li(i), li(n / i)));
    else break;
  }
  std::cout << ans << std::endl;
  return 0;
}