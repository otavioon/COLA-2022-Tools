#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int c[9];
  int sum = 0;
  rep(i,9) {
    cin >>c[i];
    sum += c[i];
  }
  int jud = 3*(c[0]+c[4]+c[8]);
  if(sum==jud) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0; 
}
