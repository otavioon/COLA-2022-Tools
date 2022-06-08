#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int maxA = *max_element(all(a));
  
  int ng = 0;
  int ok = maxA;
  
  while(abs(ok-ng) > 1){
    int mid = (ok + ng)/2;
    int tmp = 0;
    if (mid == 0) break;
    rep(i,n){
      tmp += (a[i]+mid-1)/mid - 1;
    }
    if(tmp <= k) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}
