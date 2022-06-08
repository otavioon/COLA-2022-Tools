#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int counter = 1;
int howMany(ll r){
  if(r / 10 == 0){
    return counter;
  }
  counter ++;
  return howMany(r / 10);
}

int main()
{
  ll n = 0;
  cin >> n;
  ll div,r = 0;

  for(int i = 1; i <= pow(n,0.5); i++){
    if(n % i == 0){
      div = i;
    } 
  }

 r = n / div;

 //howMany(r);

  cout << howMany(r) << endl;
  return 0;
}