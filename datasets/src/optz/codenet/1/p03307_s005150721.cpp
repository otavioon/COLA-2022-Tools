#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;
const ll MOD = 1000000007;

//GCD

ll gcd(int a, int b){
  if(a%b == 0) return b;
  return gcd(b, a%b);
}

int main(){
  int n;
  cin >> n;
  cout << 2*n/gcd(2, n) <<endl;
}