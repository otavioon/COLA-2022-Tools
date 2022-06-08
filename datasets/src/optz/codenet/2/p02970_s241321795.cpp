#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
#include<functional>
#include<cstdlib>
#include<queue>
#include<deque>
const double PI = acos(-1);
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
using ll =long long;
const int mod = 1000000007;

//map<string>a
class mint {
	long long x;
public:
	mint(long long x = 0) : x((x% mod + mod) % mod) {}
	mint operator-() const {
		return mint(-x);
	}
	mint& operator+=(const mint & a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint & operator-=(const mint & a) {
		if ((x += mod - a.x) >= mod) x -= mod;
		return *this;
	}
	mint & operator*=(const  mint & a) {
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint & a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint & a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint & a) const {
		mint res(*this);
		return res *= a;
	}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}
	// for prime mod
	mint inv() const {
		return pow(mod - 2);
	}
	mint& operator/=(const mint & a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint & a) const {
		mint res(*this);
		return res /= a;
	}

	friend ostream& operator<<(ostream & os, const mint & m) {
		os << m.x;
		return os;
	}
};
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}
//組み合わせ
void recursive_comb(vector<int> indexes, int s, int rest, std::function<void(vector<int>)> f) {
	if (rest == 0) {
		f(indexes);
	}
	else {
		if (s < 0) return;
		recursive_comb(indexes, s - 1, rest, f);
		indexes[rest - 1] = s;
		recursive_comb(indexes, s - 1, rest - 1, f);
	}
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(vector<int>)> f) {
	vector<int>indexes(k);
	recursive_comb(indexes, n - 1, k, f);
}

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
};
//fixed << setprecision(2)


int main() {
	int N, D;
	cin >> N >> D;
	int ans = 1;
	N -= D * 2+1;
	while (N > 0) {
		N -= D * 2 + 1;
		ans++;
	}
	cout << ans;
}
	

