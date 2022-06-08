#include <iostream>
#include <algorithm>
#include <cstdio>
#include <regex>
#include <cmath>
#include <vector>
#include <queue>
#include <functional>
#include <numeric>
#include <iomanip>
#include <stack>
#include <string>
#include <map>
#include <set>
using namespace std;

template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T>
using VVV = V<VV<T>>;
template <class T, class U>
using P = pair<T, U>;
template <class S, class T, class U>
using TUP = tuple<S, T, U>;

using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ld = long double;
using str = string;
using vll = V<ll>;
using vll2 = VV<ll>;
using vll3 = VVV<ll>;
using pll = P<ll, ll>;
using tll = TUP<ll, ll, ll>;
using vpll = V<pll>;
using tpll = V<tll>;
using vs = V<str>;
using vvs = V<vs>;
using vd = V<dbl>;
using vvd = V<vd>;
using qll = queue<ll>;
using qpll = queue<pll>;
using mapll = map<ll, ll>;
using setll = set<ll>;

#define int ll
#define fst first
#define snd second
#define PQ priority_queue
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define popb pop_back()
#define sz size()
#define bn begin()
#define ed end()
#define FOR(i, a, b) for (ll i = (a); i <= (ll)(b); i++)
#define rFOR(i, a, b) for (ll i = (b); i >= (ll)(a); i--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define REP1(i, n) FOR(i, 1, (n))
#define VFOR(i, v) for (auto &(i) : v)
#define IOTA(a, n) \
	vll(a)((n));   \
	iota((a).bn, (a).ed, (0));
#define fixed_echo(x) echo(fixed, setprecision(20), x)
#define SORT_ASC(a) sort((a).bn, (a).ed)
#define SORT_DESC(a) sort((a).rbegin(), (a).rend())
#define UNIQUE(a) (a).erase(unique((a).bn, (a).ed), (a).ed)
#define PREVP(a) prev_permutation((a).bn, (a).ed)
#define NEXTP(a) next_permutation((a).bn, (a).ed)
#define BINS(a, target) binary_search((a).bn, (a).ed, target)
#define LB(a, target) lower_bound((a).bn, (a).ed, target)
#define FIND(a, target) find((a).bn, (a).ed, target)
#define UB(a, target) upper_bound((a).bn, (a).ed, target)
#define ARG(a, itr) distance((a).begin(), itr)
#define CNT(a, target) count((a).bn, (a).ed, target)
#define SUM(a) accumulate((a).bn, (a).ed, 0)
#define DEBUG(...)     \
	dal(#__VA_ARGS__); \
	dal(__VA_ARGS__)
#define Dig2(a, b) ((a) >> (b)&1)
#define Dig10(a, b) (ll)(((a) / ((ll)(pow(10.0, (dbl)(b))))) % 10)
#define DigN2(a) ((llabs(a) == 0) ? 1 : ((ll)log2((dbl)llabs(a)) + 1))
#define DigN10(a) ((llabs(a) == 0) ? 1 : ((ll)log10((dbl)llabs(a)) + 1))
#define Pow2(a) ((ll)(1) << (a))
#define Pow10(a) ((ll)(pow(10.0, double(a))))
#define LSB(a) ((a) & -(a))
#define llin(n) \
	ll n;       \
	cin >> n;
#define strin(n) \
	str n;       \
	cin >> n;
#define vin(v) \
	VFOR(i, v) { cin >> (i); };
#define vllin(v, N) \
	vll(v)((N));    \
	vin(v);
#define vpllin(vp, N) \
	vpll vp;   \
	REP(i, N){ll a,b; cin >> a >> b; vp.pb(mp(a, b));}
#define vll2in(vv, col, row) \
	vll2(vv); \
	(vv).resize((col)); \
	for(ll i=0; i<col; i++) {vv[i].resize(row);} \
	REP(y, col) {REP(x, row){cin >> (vv)[y][x];}}
#define vl4in(v1, v2, N) \
	vll(v1)(N), (v2)(N); \
	REP(i, N) { cin >> (v1)[i] >> (v2)[i]; };
#define vl6in(v1, v2, v3, N)      \
	vll(v1)(N), (v2)(N), (v3)(N); \
	REP(i, N) { cin >> (v1)[i] >> (v2)[i] >> (v3)[i]; };
#define vsin(v, N) \
	vs(v)((N));    \
	vin(v);
#define sort_asc_pair_by_second(vp) \
	std::sort(vp.begin(), vp.end(), [](auto &left, auto &right) {\
    	return left.second < right.second;\
	});
#define sort_desc_pair_by_second(vp) \
	std::sort(vp.begin(), vp.end(), [](auto &left, auto &right) {\
    	return left.second > right.second;\
	});
#define min(...) Min(__VA_ARGS__)
#define max(...) Max(__VA_ARGS__)
#define emin(a, ...) ((a) = Min((a), __VA_ARGS__))
#define emax(a, ...) ((a) = Max((a), __VA_ARGS__))
#define egcd(a, ...) ((a) = gcd((a), __VA_ARGS__))
#define elcm(a, ...) ((a) = lcm((a), __VA_ARGS__))
#define tf(cond, t, f) if(cond){echo(t);}else{echo(f);}
#define yn(cond) tf(cond, "yes", "no")
#define Yn(cond) tf(cond, "Yes", "No")
#define YN(cond) tf(cond, "YES", "NO")


static const ll MOD = (ll)1e9 + 7;
static const ll INF = (1LL << 62) - 1; // 4.611E+18
static const dbl PI = acos(-1.0);

void Input(){};
template <class T, class... Args>
void Input(T &t, Args &... args)
{
	cin >> t;
	Input(args...);
}

void vInit(ll size) {}
template <class T, class... Args>
void vInit(ll size, V<T> &v, Args &... args)
{
	v.resize(size);
	vInit(size, args...);
}

void vInputNum(ll num) {}
template <class T, class... Args>
void vInputNum(ll num, V<T> &v, Args &... args)
{
	cin >> v[num];
	vInputNum(num, args...);
}

void vInput(ll size) {}
template <class... Args>
void vInput(ll size, Args &... args)
{
	vInit(size);
	REP(i, size)
	{
		vInputNum(i, args...);
	}
}

template <class S, class T>
ostream &operator<<(ostream &o, const P<S, T> &p)
{
	return o << "(" << p.first << ", " << p.second << ")";
}

template <class T>
ostream &operator<<(ostream &o, const V<T> &v)
{
	if (v.empty())
	{
		return o << "[]";
	}
	else
	{
		auto itr = v.bn;
		o << "[" << *itr;
		itr++;
		while (itr != v.ed)
		{
			o << ", " << *itr;
			itr++;
		}
		o << "]";
		return o;
	}
}

template <class T>
ostream &operator<<(ostream &o, queue<T> q)
{
	if (q.empty())
	{
		return o << "| |";
	}
	else
	{
		while (!q.empty())
		{
			o << "| " << q.front() << " ";
			q.pop();
		}
		o << "|";
		return o;
	}
}

template <class S, class T>
ostream &operator<<(ostream &o, const map<S, T> &m)
{
	if (m.empty())
	{
		return o << "[]";
	}
	else
	{
		auto itr = m.bn;
		o << "{" << itr->first << ": " << itr->second;
		itr++;
		while (itr != m.ed)
		{
			o << "} {" << itr->first << ": " << itr->second;
			itr++;
		}
		o << "}";
		return o;
	}
}

template <class T>
ostream &operator<<(ostream &o, const set<T> &s)
{
	if (s.empty())
	{
		return o << "<>";
	}
	else
	{
		auto itr = s.bn;
		o << "<" << *itr;
		itr++;
		while (itr != s.ed)
		{
			o << ", " << *itr;
			itr++;
		}
		o << ">";
		return o;
	}
}

void say() {}
template <class T>
void say(T t) { cout << t; }
template <class Head, class... Body>
void say(Head h, Body... b)
{
	cout << h;
	say(b...);
}
void puts() {}
template <class T>
void puts(T t) { cout << t; }
template <class Head, class... Body>
void puts(Head h, Body... b)
{
	cout << h << " ";
	puts(b...);
}
void echo() { cout << "\n"; }
template <class... Args>
void echo(Args... args)
{
	say(args...);
	cout << "\n";
}
void print() { cout << "\n"; }
template <class... Args>
void print(Args... args)
{
	puts(args...);
	cout << "\n";
}

void dbgsay() {}
template <class T>
void dbgsay(T t) { cout << t; }
template <class Head, class... Body>
void dbgsay(Head h, Body... b)
{
	cerr << h << " ";
	dbgsay(b...);
}
void dbgecho() { cout << "\n"; }
template <class... Args>
void dbgecho(Args... args)
{
	dbgsay(args...);
	cerr << "\n";
}

void echovv() {}
template <class T>
void echovv(VV<T> v)
{
	if (v.empty())
	{
		echo();
	}
	else
	{
		VFOR(i, v)
		echo(v);
	}
}
template <class T, class... Args>
void echovv(VV<T> v, Args... args)
{
	echovv(v);
	echovv(args...);
}
template <class Head> Head Min(Head head) { return head; }
template <class Head, class... Body>
Head Min(Head h, Body... b)
{
	auto t = Min(b...);
	return (h < t) ? h : t;
}
template <class Head> Head Max(Head head) { return head; }
template <class Head, class... Body>
Head Max(Head h, Body... b)
{
	auto t = Max(b...);
	return (h > t) ? h : t;
}

ll gcd(ll a, ll b)
{
	if (a < b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	return b ? gcd(b, a % b) : a;
}
template <class... Body>
ll gcd(ll h, Body... b)
{
	return gcd(h, gcd(b...));
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <class... Body>
ll lcm(ll h, Body... b)
{
	return lcm(h, lcm(b...));
}

ll Bset(ll a, ll b, ll c)
{
	if (c)
		a |= b;
	else
		a &= ~b;
	return a;
}

ll sumOfRange(ll N) {
	return N * (N - 1) / 2;
}

struct UF
{
public:
	ll tsize;
	ll mode;
	ll connect = 0;
	vll nodeSize;
	vll par;
	vll rank;
	UF(){};
	UF(const UF &uf) {}
	UF(ll _size, ll _mode = 0)
	{
		tsize = _size;
		mode = _mode;
		par.assign(tsize, -1);
		if (!mode)
			rank.resize(tsize, 0);
		nodeSize.resize(tsize, 1);
	}
	ll root(ll x)
	{
		return par[x] < 0 ? x : par[x] = root(par[x]);
	}
	bool isRoot(ll x)
	{
		return root(x) == x;
	}
	void unite(ll x, ll y)
	{
		x = root(x);
		y = root(y);
		if (x == y)
			return;
		if (mode)
		{
			par[x] += par[y];
			par[y] += x;
		}
		else
		{
			connect -= sumOfRange(nodeSize[x]) + sumOfRange(nodeSize[y]);
			connect += sumOfRange(nodeSize[x] + nodeSize[y]);
			if (rank[x] < rank[y])
			{
				nodeSize[y] += nodeSize[x];
				par[y] += par[x];
				par[x] = y;
			}
			else
			{
				nodeSize[x] += nodeSize[y];
				par[x] += par[y];
				par[y] = x;
				if (rank[x] == rank[y])
					rank[x]++;
			}
		}
	}
	bool same(ll x, ll y)
	{
		return root(x) == root(y);
	}
	ll size(ll x)
	{
		return -par[root(x)];
	}
};


class Vertex
{
  public:
	ll idx;
	ll param = -1;
	ll dist = INF;
	vector<pair<Vertex *, ll> /**/> e;
	ll size() { return e.size(); }
	bool operator==(const Vertex *o) { return dist == o->dist; }
	bool operator!=(const Vertex *o) { return dist != o->dist; }
	bool operator>(const Vertex *o) { return dist > o->dist; }
	bool operator<(const Vertex *o) { return dist < o->dist; }
	bool operator>=(const Vertex *o) { return dist >= o->dist; }
	bool operator<=(const Vertex *o) { return dist <= o->dist; }
};

class Graph
{
  public:
	vector<Vertex *> V;
	vll order;
	typedef tuple<Vertex *, Vertex *, ll> Edge;
	vector<Edge> E;
	Graph(ll siz)
	{
		REP(i, siz)
		{
			auto v = new Vertex();
			v->idx = i;
			V.pb(v);
		}
	}
	static bool comp(const Edge &e1, const Edge &e2)
	{
		return get<2>(e1) < get<2>(e2);
	}
	Vertex *getVertex(ll idx) { return V[idx]; }
	void unite(ll from, ll to, ll w = 1, bool digraph = true)
	{
		E.push_back(make_tuple(V[from], V[to], w));
		V[from]->e.pb(make_pair(V[to], w));
		if (!digraph)
		{
			E.push_back(make_tuple(V[to], V[from], w));
			V[to]->e.pb(make_pair(V[from], w));
		}
	}
	void dijkstra(ll start)
	{
		PQ<Vertex *, vector<Vertex *>, greater<Vertex *> /**/> pq;
		Vertex *s = getVertex(start);
		s->dist = 0;
		pq.push(s);
		while (!pq.empty())
		{
			Vertex *v = pq.top();
			pq.pop();
			for (auto &u : v->e)
			{
				if (u.first->dist > v->dist + u.second)
				{
					u.first->dist = v->dist + u.second;
					pq.push(u.first);
				}
			}
		}
	}
	bool sort(){
		for(auto &v : V){
			if(v->param==-1 && !sort_visit(v->idx)){
				return false;
			}
		}
		reverse(order.bn, order.ed);
		return true;
	}
	bool sort_visit(int v){
		Vertex *_v = getVertex(v);
		_v->param = 1;
		if(!_v->e.empty()){
			for(auto &u: _v->e){
				if(u.first->param == 2) continue;
				if(u.first->param == 1) return false;
				if(!sort_visit(u.first->idx)) return false;
			}
		}
		order.push_back(v);
		_v->param = 2;
		return true;
	}
};

ll isPrime(ll n)
{
	if (n <= 1)
		return 0;
	FOR(i, 2, (ll)sqrt(n))
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

ll DigS10(ll n)
{
	ll m = 0;
	REP(i, DigN10(n)) { m += (ll)((llabs(n) % Pow10(i + 1))) / Pow10(i); }
	return m;
}

ll PowMod(ll a, ll b)
{
	ll ans = 1, x = a % MOD;
	REP(i, DigN2(b))
	{
		if (Dig2(b, i) == 1)
		{
			ans = (ans * x) % MOD;
		}
		if (i != (DigN2(b) - 1))
		{
			x = (x * x) % MOD;
		}
	}
	return ans;
}

vll FactMod(1, 1);
vll FactModInv(1, 1);
ll Mod(ll n)
{
	n %= MOD;
	n = (n + MOD) % MOD;
	return n;
}
ll InvM(ll n)
{
	n = Mod(n);
	n = PowMod(n, MOD - 2);
	return n;
}
void CFactMod(ll n)
{
	if (FactMod.size() <= n)
	{
		FOR(i, FactMod.size(), n)
		{
			FactMod.pb((FactMod[i - 1] * (i % MOD)) % MOD);
		}
	}
}
void CFactModInv(ll n)
{
	CFactMod(n);
	if (FactModInv.size() < (n + 1))
	{
		FactModInv.resize(n + 1, -1);
	}
	if (FactModInv[n] == -1)
	{
		FactModInv[n] = PowMod(FactMod[n], MOD - 2);
	}
	for (int i = n - 1; i >= 1; i--)
	{
		if (FactModInv[i] != -1)
			break;
		FactModInv[i] = ((FactModInv[i + 1] * ((i + 1) % MOD)) % MOD);
	}
}

ll CombMod(ll n, ll k)
{
	if (n < 0 || k < 0 || n < k)
		return 0;
	if (n + 1 > FactModInv.size())
		CFactModInv(n);
	return ((((FactModInv[k] * FactModInv[n - k]) % MOD) * FactMod[n]) % MOD);
}

pll factor_sub(ll n, ll m)
{
	ll i = 0;
	while (n % m == 0)
	{
		i++;
		n /= m;
	}
	return mp(i, n);
}

vpll factrization(ll n)
{
	vpll a;
	ll c, m;
	tie(c, m) = factor_sub(n, 2);
	if (c > 0)
		a.pb(mp(2, c));
	for (ll i = 3; m >= i * i; i += 2)
	{
		tie(c, m) = factor_sub(m, i);
		if (c > 0)
			a.pb(mp(i, c));
	}
	if (m > 1)
		a.pb(mp(m, 1));
	return a;
}

vll countSameNeighbour(vll v) {
	ll prev, pres;
	vll ctr;
	ctr.pb(1);
	FOR(i, 1, v.size() - 1) {
		prev = v[i - 1];
		pres = v[i];
		if(pres != prev) {
			ctr.pb(1);
		}else {
			ctr[ctr.size() - 1]++;
		}
	}
	return ctr;
}

ll sumDigit(ll N) {
	ll sum = 0;
	for(ll i = 1; i <= N; i*= 10){
		sum += (N % (i * 10)) / i;
	}
	return sum;
}

ll dot(vll a, vll b) {
	ll ans = 0;
	REP(i, a.size()) {
		ans += a[i] * b[i];
	}
	return ans;
}
ll dot(vpll p) {
	ll ans = 0;
	REP(i, p.size()) {
		ans += p[i].first * p[i].second;
	}
	return ans;
}

ll xorSum(ll n) {
	if(n<=0) return 0;
	switch (n % 4)
	{
		case 0:
			return n;
			break;
		case 1:
			return 1;
			break;
		case 2:
			return n + 1;
			break;
		default:
			return 0;
			break;
	}
}


signed main() {
	llin(N);
	ll ans = INF;
	FOR(i, 1, (ll)sqrt(N)) {
		if(N % i == 0) {
			ll n_digit1 = to_string(i).sz;
			ll n_digit2 = to_string(N / i).sz;
			ans = min(ans, max(n_digit1, n_digit2));
		}
	}
	echo(ans);
}
