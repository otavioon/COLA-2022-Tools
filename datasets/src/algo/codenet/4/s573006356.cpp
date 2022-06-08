#include<stdio.h>
#include<cmath>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>
#include<queue>
#include<set>
#include<utility>
#include<climits>
#include<iomanip>
#include<limits>
#include<thread>
#include<map>
#include<stack>
#include<numeric>
#include<cstring>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<tuple>
#include <cstdio>
using namespace std;

#define pb          push_back
#define mp          make_pair
#define ll          long long int
#define hmap        unordered_map
#define pii         pair<int,int>
#define pdd         pair<double, double>
#define M           1000000007
#define MOD         998244353
#define fast        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test        ll t; cin>>t; while(t--)
#define inp(a,n)    int a[n]; for(int i=0;i<n;i++)  cin>>a[i];
#define inpl(a,n)   ll a[n];  for(ll i=0;i<n;i++)   cin>>a[i];
#define out(a,n)    for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define outl(a,n)   for(ll i=0;i<n;i++)  cout<<a[i]<<" "; cout<<endl;
#define outv(v)     for(int i=0;i<v.size();i++) cout<<v[i]<<" ";  cout<<endl;
#define all(s)      (s).begin(),(s).end()

#define rep(i,n) for(int i=0; i<n; i++)
#define rep1(i,n) for(int i=1; i<n+1; i++)
#define repr(i,n) for(int i=n-1; i>=0; i--)
#define repr1(i,n) for(int i=n; i>0; i--)
#define FOR(i,j,n) for(int i=j; i < n; i++)
#define souatari(i,j,n) rep1(i,n-1)rep(j,i)
#define souatari1(i,j,n) for(int i=2; i<n+1; i++)rep1(j,i-1)
#define mp make_pair
#define F first
#define S second
#define elif else if
#define inpv(a,n)   vector<int>a(n);  for(ll i=0;i<n;i++)   cin>>a[i];



ll  efficient_expo(ll a , ll  b , ll mod) {
	ll res = 1 ;
	// a = a % mod;
	// b = b % mod ;
	while (b > 0) {
		if (b & 1) res = (res * a) % mod ;
		a = (a * a) % mod ;
		b = b >> 1 ;
	}
	return res ;
}

// int modd(int a, int b, int c)
// {
// 	if (b == 0) return 1;

// 	if (b % 2 == 0)
// 	{
// 		int x = modd(a, b / 2, c);
// 		return (x * x) % c;
// 	}
// 	else return (a % c * modd(a, b - 1, c)) % c;
// }

// ll recursive_mod(ll a , ll b , ll mod) {
// 	if (b == 0) return 1 ;
// 	if (b & 1) return (a % mod * recursive_mod(a, b - 1, mod)) % mod;
// 	ll x = (recursive_mod(a, b / 2, mod)) ;
// 	return ((x ) * (x )) % mod ;
// }

// ll leading_digit(ll a , ll b , ll k) {
// 	long long double  pro = b * log10(a) ;
// 	long long double deci = pro - floor(pro) ;
// 	int po = pow(10, k - 1);
// 	return (ll)(((long long double)pow(10, deci)) * po) ;
// }

bool check(int num, set<int>ff) {
	while (num) {
		int a = num % 10 ;
		if (ff.count(a)) return false;
		num = num / 10 ;
	}
	return true ;
}



int main() {

	fast ;
	int n; int k;
	cin >> n >> k ;
	set<int> ff;
	for (int i = 0 ; i < k; i++) {
		int aa;
		cin >> aa ;
		ff.insert(aa) ;
	}
	for (int i = n ; i < 1000000; i++) {
		if (check(i, ff)) {
			cout << i ;
			return 0 ;
		}
	}
	return 0 ;


}

