#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <fstream>
#include <cstddef>
#include <cstring>
//#include <chrono> //正確な時間計測のため
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define PB push_back
#define rep(i, a) for(int i = 0; i < a; i++)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define mp make_pair
#define INT int_64
#define MOD 998244353
const ll INF = (1<<30);
const ll NEGA=-INF*10000; 

//階乗
ll Kaijou(ll a) {
if (a < 2) return 1;
return a * Kaijou(a - 1)%MOD;
}

//逆元の計算用(pは素数のときb=p-2で逆元)
ll calc(ll a, ll b, ll p) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		ll d = calc(a, b / 2, p);
		return (d*d) % p;
	}
	else {
		return (a*calc(a, b - 1, p)) % p;
	}
}


//ユークリッドの互除法
ll gcd(ll x, ll y) {
	if (x < y) swap(x, y);
	if (y == 0) return x;
	return gcd(y, x%y);
}

ll CCC(ll all,ll a,ll b,ll c){
  all=Kaijou(all)%MOD;
  a=Kaijou(a);
  b=Kaijou(b);
  c=Kaijou(c);
  ll sita=((a*b)%MOD*c)%MOD;
  return all*calc(sita,MOD-2,MOD)%MOD;
}

 ll ans=INF;

 ll cc[501][501];
 ll D[31][31];
 
 ll pdmin[3];

//再帰なし累乗
ll iPOW(ll x, ll p){
  ll result;
	for(result=1;p!=0;p>>=1)
	{
    if(p&1) result*=x;
	  x*=x;
  }
  return result;
}


int main(){  
 int n;
 cin>>n;
 if(n%2) cout<<2*n<<endl;
 else cout<<n<<endl;

}