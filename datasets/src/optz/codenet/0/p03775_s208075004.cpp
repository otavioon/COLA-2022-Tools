#include <bits/stdc++.h>
using namespace std;

#define PI 4*atan(1)
#define INF 1e8

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

unsigned long long F(unsigned long long a, unsigned long long b){
  return max(log10(a) + 1, log10(b) + 1);
}

int main(){
  unsigned long long n;
  cin >> n;
  unsigned long long a = 1, b = n, _min = INF;
  for(int i = 2; i <= sqrt(n); i++){
    _min = min(_min, F(a, b));
    if(b % i == 0){
      a *= i;
      b /= i;
      i--;
      if(a > b)break;
    }
  }  
  cout << _min << endl;
}
