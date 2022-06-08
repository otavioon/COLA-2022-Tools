#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>

const ll INF = pow(10, 9) + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> lmin(2005,n);//iより長さが小さい棒の数
  rep(i,n){
    cin >> a[i];
    rep(j,a[i]+1) lmin[j]--;
  }
  rep(i,14){
    cout << lmin[i] << endl;
  }
  sort(a.begin(),a.end());
  ll sum = 0;
  rep(i,n){
    for(int j = i + 1 ;j < n;j++){
      sum = sum + lmin[a[i]+a[j]]-lmin[a[j]+1];
    }
  }
  cout << sum << endl;
}