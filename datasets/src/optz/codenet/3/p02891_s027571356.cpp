#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  string S;
  cin >> S;
  ll K;
  cin >> K;
  int ssize = (int)S.size();
  ll ans = 0;
  ll tmp = 0;

  sort(all(S));
  if(ssize==1){cout << K/2 << endl; return 0;}
  if(ssize%2==1){
    for(int i=1;i<ssize;i++){
      if(S[i]!=S[0]) break;
      if(i+1==ssize){
        ans = (ssize*K) /2;
        cout << ans << endl;
        return 0;
      }
    }
  }
  for(int i=1;i<ssize;i++){
    if(S[i] == S[i-1]){
      S[i] = '0';
      tmp++;
    }
  }
  ans += tmp * K;
  if(S[0] == S[ssize-1]){
    ans += K-1;
  }
  cout << ans << endl;
  return 0;
}
