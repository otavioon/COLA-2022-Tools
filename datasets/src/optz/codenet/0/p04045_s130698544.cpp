#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  vector<int> hates;
  int n, k;
  int i;
  int hate;
  int s, a, b, c, d;
  s = a = b = c = d = 0;
  
  cin >> n >> k;
  
  for (i = 0; i < k; i++) {
    cin >> hate;
    hates.push_back(hate);
  }
  
  d = n % 10; 
  while(find(hates.begin(), hates.end(), d) != hates.end()) {
    d++;
    if (d > 9) {
      n += 10;
      d = 0;
    }
  }
  
  if (n >= 10) {
    c = (n % 100) / 10;
    while(find(hates.begin(), hates.end(), c) != hates.end()) {
      c++;
      if (c > 9) {
        n += 100;
        c = 0;
      }
    }
  }
  
  if (n >= 100) {
    b = (n % 1000) / 100;
    while(find(hates.begin(), hates.end(), b) != hates.end()) {
      b++;

      if (b > 9) {
        n += 1000;
        b = 0;
      }
    }
  }
  
  if (n >= 1000) {
    a = (n % 10000) / 1000;
    while(find(hates.begin(), hates.end(), a) != hates.end()) {
      a++;    
      if (a > 9) {
        n += 10000;
        a = 0;
      }
    }
  }
   
  if (n >= 10000) {
    s = n / 10000;
    while(find(hates.begin(), hates.end(), s) != hates.end()) {
      s++;
    }
  }
  
  if (s > 0) {
    cout << s << a << b << c << d << endl;
  } else if (a > 0) {
    cout << a << b << c << d << endl;
  } else if (b > 0) {
    cout << b << c << d << endl;
  } else if (c > 0) {
    cout << c << d << endl;
  } else {
    cout << d << endl;
  }
   
  return 0;
  
}