#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include<vector>
#include<iomanip>
#include<map>
#include <queue>
#include<cmath>
#include<cstdio>
#include<iomanip>
 
using namespace std;
 
using ll = long long int; 
 
void prime(vector<int> &num, int n){
    for(int i=0;i<=n;i++){
        num[i] = 1;
    }
    num[0] = 0;
    num[1] = 0;
    num[2] = 1;
 
    for(int i=2;i<=sqrt(n);i++){
        if(num[i] == 1){
            for(int j=2;j<=n/i;j++){
                num[i*j] = 0;
            }
        }
    }
}
 
 
ll gcd(ll a, ll b) {
  ll tmp;
  if ( b > a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  while (a % b !=0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}
 
ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}
 
ll keta(ll a){
  ll ans = 1;
  while(1){
    if(a/10 > 0){
      ans++;
      a = a/10;
    }
    if(a<10) break;
  }
  return ans;
}
 
const int MAX = 50;
const int MOD = 1000000007;
 
long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
 
 
int main(void){
 
    ll k,x;
    cin>>k>>x;

    if(500*k >= x)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
 
    return 0;
}