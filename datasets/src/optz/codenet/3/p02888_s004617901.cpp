#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include<unordered_set> 
#include<cmath>
using namespace std;
long long p  = 998244353;
//long long p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<int,pin>
#define V vector
#define Endl endl
#define veb vector<bool>
#define rev(s) reverse(s.begin(),s.end())
#define lower(h,val) lower_bound(h.begin(),h.end(),val)
#define upper(h,val) upper_bound(h.begin(),h.end(),val)
#define mint modint<998244353>
#define end_s(a) cout <<a<<endl;return 0
template <std::uint_fast64_t Modulus> class modint {
	using u64 = std::uint_fast64_t;

public:
	u64 a;

	constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
	constexpr u64 &value() noexcept { return a; }
	constexpr const u64 &value() const noexcept { return a; }
	constexpr modint operator+(const modint rhs) const noexcept {
		return modint(*this) += rhs;
	}
	constexpr modint operator-(const modint rhs) const noexcept {
		return modint(*this) -= rhs;
	}
	constexpr modint operator*(const modint rhs) const noexcept {
		return modint(*this) *= rhs;
	}
	constexpr modint operator/(const modint rhs) const noexcept {
		return modint(*this) /= rhs;
	}
	constexpr modint &operator+=(const modint rhs) noexcept {
		a += rhs.a;
		if (a >= Modulus) {
			a -= Modulus;
		}
		return *this;
	}
	constexpr modint &operator-=(const modint rhs) noexcept {
		if (a < rhs.a) {
			a += Modulus;
		}
		a -= rhs.a;
		return *this;
	}
	constexpr modint &operator*=(const modint rhs) noexcept {
		a = a * rhs.a % Modulus;
		return *this;
	}
	constexpr modint &operator/=(modint rhs) noexcept {
		u64 exp = Modulus - 2;
		while (exp) {
			if (exp % 2) {
				*this *= rhs;
			}
			rhs *= rhs;
			exp /= 2;
		}
		return *this;
	}
};
vel pa;
int root(int x) {
	if (pa[x] == -1) { return x; }
	int ans = root(pa[x]); pa[x] = ans;
	return ans;
}
void marge(int x, int y) {
	x = root(x);
	y = root(y);
	if (x != y) {pa[x] = y;}
}
signed main() {
	int n; cin >> n;
	vel l(n);
	rep(i, n) { cin >> l[i]; }
	sor(l);
	int ans = 0;
	rep(i, n) {
		rep(j, i) {
			if (l[j] * 2 > l[i]) {
				int st = upper_bound(l.begin(), l.end(), l[i] - l[j])-l.begin();
				ans += j - st;
			}
		}
	}
	cout << ans << endl;
	return 0;
}