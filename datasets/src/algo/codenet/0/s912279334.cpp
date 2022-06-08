#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  string s;
  cin >> s;
  ll k;
  cin >> k;
  ll ans=0;
  for(int i=1;i<s.size();i++){
    if(s.at(i)==s.at(i-1)){
      ans++;
      s.insert(i,1,'A');
    }
  }
  if(s.at(0)==s.at(s.size()-1))
    ans++;
  cout << ans*k-1 << endl;
}
