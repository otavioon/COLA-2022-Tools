#include <bits/stdc++.h>
using namespace std;

bool all_ch_same(string s) {
  char t = s[0];
  for ( int i = 1; i < s.length(); i++ ) {
    if ( t != s[i] ) { return false; }
  }
  return true;
}

int main() {
  string s1;
  string s2;
  long long k;
  cin >> s1;
  cin >> k;
  s2 = s1 + s1;
  long long l1 = 0;
  long long l2 = 0;

  string t;
  t  = s1;
  for ( int i = 0; i < t.length()-1; i++ ) {
    if ( t[i] == t[i+1] ) { l1++; t[i+1] = '0';  }
  }
  t = s2;
  for ( int i = 0; i < t.length()-1; i++ ) {
    if ( t[i] == t[i+1] ) { l2++; t[i+1] = '0';  }
  }

  long long ans;
  if ( s1.length()%2 == 1 && all_ch_same(s1) ) {
    ans = ( k%2 == 0 ) ? l2*k/2 : l2*(k/2) + l1;
  } else {
    ans = l1*k;
  }

  cout <<  ans << endl;
  return 0;
}
