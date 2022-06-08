#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long ul;
typedef pair<ul, ul> P;
map<int, int> dp;
#define REP(i, n) for (int i = 0; i < n; i++)

ul N, M,  T;
std::string S;
ul gcd(ul m, ul n) {
  if ((0 == m) || (0 == n)) return 0;
  while (m != n) {
    if (m > n)
      m = m - n;
    else
      n = n - m;
  }
  return m;
}  // gcd

ul lcm(ul m, ul n) {
  if ((0 == m) || (0 == n)) return 0;
  return ((m / gcd(m, n)) * n);  // lcm = m * n / gcd(m,n)
}  // lcm

bool Check(ul num) {
  if(!(num & (num-1))) {
    return true;
  } else {
    return false;
  }
}
void Count_pow(vector<ul>& vecs, ul* count){
  ul ii = 0;
  ul ev_size =  vecs.size();
  // REP(ii,vecs.size()) cout << vecs[ii] <<" ";
  // cout <<endl;
  for(auto& tmp: vecs){
    auto itmp = ii+1;
    while(itmp < ev_size) {
      // cout <<tmp <<" "<<vecs[itmp]<<endl;
      if( Check(tmp + vecs[itmp])){
        *count +=1;
        vecs[itmp]+=1;
      }
      ++itmp;
    }
    ++ii;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  vector<ul> Even;
  Even.reserve(N);
  vector<ul> Odd;
  Odd.reserve(N);
  ul tmp = 0;
  ul count =0;

  REP(ii,N) {
    cin >> tmp;
    if(tmp%2 ==0){
      Even.emplace_back(tmp);
    }else {
      Odd.emplace_back(tmp);
    }
  }
  Count_pow(Even, &count);
  Count_pow(Odd, &count);
  cout <<count <<endl;
}