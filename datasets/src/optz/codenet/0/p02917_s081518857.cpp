#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <map>
#include <queue>
#include <list>
#define rep(i,n) for(int i=0;i<(n);i++)
#define crep(i) for(char i='a';i<='z';i++)
#define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
#define psortfirst(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.first<b.first;});
#define All(x) (x).begin(),(x).end()
int ctoi(const char c){
  if('0' <= c && c <= '9') return (c-'0');
  return -1;
}
using namespace std;
using pii  = pair<int,int>;
long long gcd(long long a, long long b){return (b == 0 ? a : gcd(b, a%b));}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
typedef long long ll;
#define MOD 1000000007
#define EPS 10e-8

int main() {
  ll N,A[107],B=0;
  cin >> N;
  rep(i,N-1){
    cin >> A[i];
  }
  rep(i,N){
    if(i==0){
      B+=A[0];
    }
    else if(i==N-1){
      B+=A[N-2];
    }
    else{
      B+=min(A[i-1],A[i]);
    }
  }
  cout <<  B  << endl;
}