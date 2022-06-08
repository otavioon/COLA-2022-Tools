#include <bits/stdc++.h>
#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>
#include<utility>
#include<functional>
#include<map>
#include<set>
#include<cctype>
#include<fstream>
#include <numeric>
#include <iomanip>
#include <cstring> 
using namespace std;
using ll=long long;

#define FOR(i, a, b) for( int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for( int i=(a);i>=(b);i--)
#define LFOR(i, a, b) for( long long int i=(a);i<=(b);i++)
#define LRFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define LLONG_MAXs 9223372036854775800

#include <iostream>
#include <cmath>
using namespace std;
 

 
bool isPrimeNum( ll x ){ // 素数である場合 true を返す
  if( x <= 1 ){ // 1以下である場合は素数でないことがすぐにわかる
    return false;
  }
  // sqrt( double型 ) は引数の平方根を double型で返すので、int型でキャスト
  int n = (int)sqrt( (double)x );
  for( int i = 2; i <= n; i++ ){
    if( x % i == 0 ){ // 割り切る整数がある場合、即判定終了
      return false;
    }
  }
  return true; // 割り切る整数がない場合、素数である
}

constexpr ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
constexpr ll lcm(ll a,ll b){return a*b/gcd(a,b);}
constexpr ll abs(ll a,ll b){
if(a>=b)return a-b;
if(a<b)return b-a;
}
constexpr ll min(ll a,ll b){
if(a>=b)return b;
if(a<b)return a;
}

constexpr ll max(ll a,ll b){
if(a>=b)return a;
if(a<b)return b;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {

  ll C[3][3];

    cin>>C[0][0]>>C[0][1]>>C[0][2];
    cin>>C[1][0]>>C[1][1]>>C[1][2];
    cin>>C[2][0]>>C[2][1]>>C[2][2];

  int flag=0;
 
  ll a1a2=C[0][1]-C[0][0];
  ll a2a3=C[0][2]-C[0][1];
  ll b1b2=C[1][0]-C[0][0];
  ll b2b3=C[2][0]-C[1][0];

  if(a1a2!=C[1][1]-C[1][0])flag++;
  if(a1a2!=C[2][1]-C[2][0])flag++;
  if(a2a3!=C[1][2]-C[1][1])flag++;
  if(a2a3!=C[2][2]-C[2][1])flag++;

  if(b1b2!=C[1][1]-C[0][1])flag++;
  if(b1b2!=C[1][2]-C[0][2])flag++;
  if(b2b3!=C[2][1]-C[1][1])flag++;
  if(b2b3!=C[2][2]-C[1][2])flag++;
  if(flag==0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
 
