#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

//long long
using ll = long long;

//出力系
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
 
// begin() end()
#define all(x) (x).begin(),(x).end()

//for
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//最大公約数 
unsigned gcd(unsigned a, unsigned b) {
  if(a < b) return gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(){
int N, K;
cin >> N >> K;

vector<bool>D(10, false);
REP(i, K){
  int x;
  cin >> x;
  D.at(x) = true;
}

int ans = N;

while(true){
int now = ans;
    while(now > 0){
      if(D.at(now % 10)) break;
      now /= 10;
    }

if(now == 0) break;
ans++;
}
print(ans);
}
