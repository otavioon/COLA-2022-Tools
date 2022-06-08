#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
using namespace std;
#define ll long long

int main () {
  ll n;
  cin >> n;
  vector<ll> divisor;
  for (ll i = 1; i <= (ll) sqrt(n); i++) {
    if (n % i == 0) {
      divisor.push_back(n/i);  
    }    
  }    
  ll ans = divisor[divisor.size() - 1];
  ll sub = 1;
  for (ll i = 1; i <= 10; i++) {
    sub = sub * 10;
    if (sub > ans) {
      cout <<  i << endl;
      break; 
    }    
  }
}