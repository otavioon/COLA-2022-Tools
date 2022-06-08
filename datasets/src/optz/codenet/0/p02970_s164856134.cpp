#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#if defined(_MSC_VER) || defined(ONLINE_JUDGE)
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;
using LL = long long;		using VB = vector<bool>;
using VI = vector<int>;		using VL = vector<LL>;
using VS = vector<string>;	using VD = vector<double>;
using VVI = vector<VI>;		using VVL = vector<VL>;
using PII = pair<int, int>;	using PLL = pair<LL, LL>;
using VP = vector<PII>;		using VPL = vector<PLL>;
const int inf = (int)1e9;
const LL inf_ll = (LL)1e18, MOD = 1000000007;
const double PI = acos(-1.0), EPS = 1e-12;

template<class T>void Sort(T& a) { sort(all(a)); }
template<class T>void RSort(T& a) { sort(rall(a)); }
template<class T>void Reverse(T& a) { reverse(all(a)); }
template<class T>void Unique(T& a) { a.erase(unique(all(a)), a.end()); }
template<class T>T Sorted(T a) { Sort(a); return a; }
template<class T>T RSorted(T a) { RSort(a); return a; }
template<class T>T Reversed(T a) { Reverse(a); return a; }
template<class T>T Uniqued(T a) { Unique(a); return a; }
template<class T>auto Max(const T& a) { return *max_element(all(a)); }
template<class T>auto Min(const T& a) { return *min_element(all(a)); }
template<class T>int MaxPos(const T& a) { return max_element(all(a)) - a.begin(); }
template<class T>int MinPos(const T& a) { return min_element(all(a)) - a.begin(); }
template<class T, class U>int Count(const T& a, const  U& v) { return count(all(a), v); }
template<class T, class U>int Find(const T& a, const U& v) { auto pos = find(all(a), v); return pos == a.end() ? -1 : pos - a.begin(); }
template<class T, class U>U Sum(const T& a, const U& v) { return accumulate(all(a), v); }
template<class T, class U>int Lower(const T& a, const U& v) { return lower_bound(all(a), v) - a.begin(); }
template<class T, class U>int Upper(const T& a, const U& v) { return upper_bound(all(a), v) - a.begin(); }
template<class T, class P>void RemoveIf(T& a, P f) { a.erase(remove_if(all(a), f), a.end()); }
template<class T>T Age(T n, T m) { return (n + m - 1) / m; }
template<class T>T Gcd(T n, T m) { return m ? Gcd(m, n % m) : n; }
template<class T>T Lcm(T n, T m) { return n / Gcd(n, m) * m; }
template<class T>T Pow(T a, T n) { T r = 1; while (n > 0) { if (n & 1)r *= a; a *= a; n /= 2; }return r; }
template<class T>T Powmod(T a, T n, T m = MOD) { T r = 1; while (n > 0) { if (n & 1)r = r * a % m, n--; else a = a * a % m, n /= 2; }return r; }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T>bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
string operator*(string s, int n) { string ret; rep(i, n)ret += s; return ret; }

// --- input --- //
template<class T>T InputF() { T ret; cin >> ret; return ret; }
template<> char InputF() {
	char ret = '\0', c = getchar_unlocked();
	while (c != '\0' && c != '\n' && c != '\t' && c != ' ') { ret = c; c = getchar_unlocked(); }
	return ret;
}
template<> string InputF() {
	string ret; char c = getchar_unlocked();
	while (c != '\0' && c != '\n' && c != '\t' && c != ' ') { ret.push_back(c); c = getchar_unlocked(); }
	return ret;
}
template<> int InputF() {
	int ret = 0; bool neg = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while (isdigit(c)) { ret = ret * 10 + (c - '0'); c = getchar_unlocked(); }
	return neg ? -ret : ret;
}
template<> LL InputF() {
	LL ret = 0; bool neg = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while (isdigit(c)) { ret = ret * 10LL + (LL(c) - LL('0')); c = getchar_unlocked(); }
	return neg ? -ret : ret;
}
template<> double InputF() {
	double ret = 0, dp = 1; bool neg = false, adp = false; char c = getchar_unlocked();
	if (c == '-') { neg = true; c = getchar_unlocked(); }
	while (isdigit(c) || c == '.') {
		if (c == '.')adp = true;
		else if (adp)ret += (c - '0') * (dp *= 0.1);
		else ret = ret * 10.0 + (c - '0');
		c = getchar_unlocked();
	}
	return neg ? -ret : ret;
}
string GetLine() {
	string ret; char c = getchar_unlocked();
	while (c != '\0' && c != '\n') { ret.push_back(c); c = getchar_unlocked(); }
	return ret;
}
struct Input {
	struct InputV {
		int n, m;
		InputV(int N) :n(N), m(-1) {}
		InputV(pair<int, int> N) { tie(n, m) = N; }
		template<class T>operator vector<T>() {
			vector<T> ret(n); rep(i, n)ret[i] = InputF<T>(); return ret;
		}
		template<class T>operator vector<vector<T>>() {
			assert(m != -1); vector<vector<T>> ret(n, vector<T>(m));
			rep(i, n)rep(j, m)ret[i][j] = InputF<T>();
			return ret;
		}
	};
	template<class T>operator T() { return InputF<T>(); }
	InputV operator[](int t) { return InputV(t); }
	InputV operator[](pair<int, int> t) { return InputV(t); }
}in;

// --- output --- //
struct BoolStr {
	const char* t, * f; BoolStr(const char* _t, const char* _f) :t(_t), f(_f) {}
}Yes("Yes", "No"), yes("yes", "no"), YES("YES", "NO"), Int("1", "0");
struct DivStr {
	const char* d, * l; DivStr(const char* _d, const char* _l) :d(_d), l(_l) {}
}spc(" ", "\n"), no_spc("", "\n"), end_line("\n", "\n"), comma(",", "\n"), no_endl(" ", "");
class Print {
	BoolStr B{ Yes }; DivStr D{ spc };	void p(double v) { printf("%.20f", v); }
	void p(int v) { printf("%d", v); }	void p(LL v) { printf("%lld", v); }
	void p(char v) { putchar(v); }		void p(bool v) { printf(v ? B.t : B.f); }
	template<class T>void p(const T& v) { cout << v; }
	template<class T, class U>void p(const pair<T, U>& v) { p(v.first); printf(D.d); p(v.second); }
	template<class T>void p(const vector<T>& v) { rep(i, sz(v)) { if (i)printf(D.d); p(v[i]); } }
	template<class T>void p(const vector<vector<T>>& v) { rep(i, sz(v)) { if (i)printf(D.l); p(v[i]); } }
	void p(const BoolStr& v) { B = v; } void p(const DivStr& v) { D = v; }
	template<class T>bool isPrint(const T& v) { return !is_same<BoolStr, T>::value && !is_same<DivStr, T>::value; }
public:
	void operator()() { printf(D.l); }
	template<class H>void operator()(H&& h) {
		p(h); if (isPrint(h))printf(D.l); B = Yes; D = spc;
	}
	template<class H, class...T>void operator()(H&& h, T&& ...t) {
		p(h); if (isPrint(h))printf(D.d); operator()(forward<T>(t)...);
	}
}out;

// --- dump --- //
#if __has_include("dump.hpp")
#include "dump.hpp"
#else
#define dump(...) (void(0))
#endif


int main() {
	int n = in, d = in;
	out(Age(n, d * 2 + 1));
}