#include"bits/stdc++.h"
#include <string>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const double PI = acos(-1.0);
const int MOD = (int)pow(10, 9) + 7;

#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()

ll modinv(ll a, ll m) {
	ll b = m, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

inline void finish() {
	cout << -1 << endl;
	exit(0);
}

template <typename T>
inline void debug(vector<T> v) {
	cout << "[";
	for (size_t i = 0; i < v.size() - 1; ++i) {
		cout << v[i] << ", ";
	}
	cout << v[v.size() - 1] << "]" << endl;
}

class Pos {
public:
	double x, y;
	Pos(double x, double y) {
		this->x = x;
		this->y = y;
	}
	Pos() {
		x = 0.0;
		y = 0.0;
	}
};

class Mod {
public:
	static inline ll Add(ll a, ll b) {
		return (a + b) % MOD;
	}

	static inline ll Sub(ll a, ll b) {
		ll ans = (a - b) % MOD;
		return (ans < 0) ? (ans + MOD) : ans;
	}

	static inline ll Mul(ll a, ll b) {
		return (a * b) % MOD;
	}
	
	static inline ll Div(ll a, ll b) {
		return (a % MOD) * modinv(b, MOD) % MOD;
	}
};
/*
class BitFlag {
private:
	const void Check(size_t n) const {
		if (n >= bits.size() || n < 0) {
			throw std::exception(("BitFlag OutOfRange size=" + to_string(bits.size()) + ", n = " + to_string(n) + ". You can use 0 <= n <= " + to_string(bits.size() - 1)).c_str());
		}
	}
	inline void BitPlus(size_t n) {
		Check(n);
		if (isTrue(n)) {
			Change(n);
			BitPlus(n + 1);
		}
		else {
			Change(n);
		}
	}
	inline void BitMinus(size_t n) {
		Check(n);
		if (isFalse(n)) {
			Change(n);
			BitMinus(n + 1);
		}
		else {
			Change(n);
		}
	}

public:
	vector<bool> bits;

public:
	BitFlag(int n, bool firstFlag = false) {
		bits.resize(n, firstFlag);
	}
	BitFlag(vector<bool> bits) {
		this->bits = bits;
	}

	inline void Change(size_t n) {
		Check(n);
		bits[n] = !bits[n];
	}
	
	inline void SetTrue(size_t n) {
		Check(n);
		bits[n] = true;
	}
	inline void SetFalse(size_t n) {
		Check(n);
		bits[n] = false;
	}

	inline void SetFlag(size_t n, bool flag) {
		Check(n);
		bits[n] = flag;
	}

	inline bool isTrue(size_t n) {
		Check(n);
		return bits[n];
	}
	inline bool isFalse(size_t n) {
		Check(n);
		return !bits[n];
	}

	inline size_t Size() const{
		return bits.size();
	}
	inline size_t Length() const {
		return bits.size();
	}

	void debug() {
		for (size_t i = bits.size() - 1;; --i) {
			cout << bits[i];
			if (i == 0) {
				cout << endl;
				return;
			}
		}
	}

	const bool& operator [](size_t n) const {
		Check(n);
		return bits[n];
	}
	
	BitFlag& operator ++() {
		BitPlus(0);
		return *this;
	}
	BitFlag& operator --() {
		BitMinus(0);
		return *this;
	}
	BitFlag& operator ++(int) {
		BitFlag bf = *this;
		--(*this);
		return bf;
	}

	BitFlag& operator --(int) {
		BitFlag bf = *this;
		++(*this);
		return bf;
	}
};
*/
inline double distance(Pos p1, Pos p2) {
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

inline int Kaijo(int n) {
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		ans *= i;
	}
	return ans;
}

template <typename T>
inline int GetKeta(T num) {
	return to_string(num).length();
}

void Main();
inline void DebugMain() {
	while (true) {
		Main();
		cout << endl;
	}
}

int main() {
	bool debug = false;
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);

	if (debug) {
		cout << "\x1b[41m" << "Debug Mode このまま提出すると死" << endl;
	}
	try {
		(debug) ? DebugMain() : Main();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}

template <typename T>
inline bool isExistVector(vector<T>& v, T& str) {
	if (v.size() == 0) {
		return false;
	}
	for (string& s : v) {
		if (s == str) {
			return true;
		}
	}
	return false;
}

inline ll MinKobaisu(ll a, ll b) {
	ll x = a * b;
	if (a < b) {
		ll tmp = a;
		a = b;
		b = tmp;
	}

	ll r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return x / b;
}

inline int ctoi(char c) {
	return (int)c - 48;
}

inline void Main(){
	int k, x;
	cin >> k >> x;

	Yes(k * 500 >= x);
}