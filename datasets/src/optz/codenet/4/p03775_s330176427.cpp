#include <iostream>
#include <cmath>

using namespace std;

int main(){
  unsigned long long int l;
  cin >> l;
  unsigned long long int a = sqrt(l);
  int tmp = 1000;
  for(long long int i = 1; i <= a; i++){
    if(a % i != 0) continue;
    unsigned long long int b = a / i;
    int p = log10(i), q = log10(b);
    p++, q++;
    if(max(p, q) < tmp) tmp = max(p,q);
  }
  cout << tmp;
}
