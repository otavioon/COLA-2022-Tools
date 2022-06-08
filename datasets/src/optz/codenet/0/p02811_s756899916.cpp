using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops")
#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<string>
#include<cmath>
#include<map>
#include<iomanip>
#include<numeric>
#include<queue>
#include<deque>
#include<cfloat>
#include<functional>
#include<tuple>
#include<math.h>
#include<bitset>
#include<stack>
#include<set>
#include<random>
#include<stdlib.h>
#define rip(i,n) for(ll i=0;i<n;i++)
#define Rip(i,n) for(ll i=1;i<n;i++)
#define all(V) V.begin(),V.end()
#define ll long long
#define ld long double
#define MOD 998244353
#define mod MOD
#define sec setprecision
constexpr double eps = 1e-9;
constexpr double PI = 3.141592653589793238462643383279;
ll gcd(ll a, ll b) {
	if (a % b == 0)	return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void cominit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (ll i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
vector<ll> soinnsuubunnkai(ll n) {
	vector<ll>a;
	while (n % 2 == 0) {
		a.push_back(2);
		n /= 2;
	}
	ll f = 3;
	while (f * f <= n) {
		if (n % f == 0) {
			a.push_back(f);
			n /= f;
		}
		else f += 2;
	}
	if (n != 1)
		a.push_back(n);
	return(a);
}
// 二項係数計算
long long com(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
ll pow(ll a, ll b) {
	a = a % mod;
	if (b == 0)return(1);
	else if (b % 2 == 0)return(pow((a * a) % mod, b / 2));
	else return(a * (pow(a, b - 1)));
}
void solve() {
	int k, x;
	cin >> k >> x;
	if (k * 500 >= x)cout << "Yes" << endl;
	else cout << "No" << endl;
}
int main() {
	solve();
}