#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)
#define cinv(n,v) rep(i,n) cin >> v[i]
using namespace std;
const int INF = 1e9;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
int x_pos[4] = {1,0,-1,0}, y_pos[4] = {0,1,0,-1};
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

char upper(char c){
	return c-0x20;
}

char lower(char c){
	return c+0x20;
}

void unique_vector(vector<int>& v){
	sort(all(v));
	v.erase(unique(all(v)), v.end());
}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

//ユークリッドの互除法
//最大公約数
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

//最小公倍数
ll lcm(ll x, ll y){
	ll g = gcd(x,y);
	return x/g*y;
}

ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}

int main() {
	int n;
	int ans = 0;
	cin >> n;
	vector<int> b(n);
	rep(i,n-1){
		cin >> b[i];
	}
	ans += b[0];
	rep(i, n-1)
	{
		if (i == n - 2)
		{
			ans += b[i];
			continue;
		}
		ans += min(b[i], b[i + 1]);
	}
	cout << ans << endl;
}
