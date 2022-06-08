#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;++i)
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//max=({});
//条件式が真ならwhileの中身を回し続ける
//printf("%d\n", ans);

//pairの入力
//vector<pair<ll, ll>>work(n);
//rep(i, n) {
//	ll a, b;
//	cin >> a >> b;
//	work[i] = make_pair(a, b);
//}

int g[15][15];
const int INF = 1001001001;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

//最大公約数
ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
	if (x == 0 || y == 0)return 0;
	return (x / gcd(x, y) * y);
}

//素因数分解
vector<pair<ll, int>>factorize(ll n) {
	vector<pair<ll, int>>res;
	for (ll i = 2;i * i <= n;++i) {
		if (n % i)continue;
		res.emplace_back(i, 0);
		while (n % i == 0) {
			n /= i;
			res.back().second++;
		}
	}
	if (n != 1)res.emplace_back(n, 1);
	return res;
}

int dp[1010][1010];
int bingo[3][3];
bool flag[3][3];
int I[100][20];
char s[100][100];

int main() {
	rep(i, 3) {
		rep(j, 3) {
			cin >> bingo[i][j];
		}
	}
	bool flag = true;
	for (int i = 0;i < 3;++i) {
		for (int j = i;j < 3;++j) {
			if (bingo[i][1] - bingo[j][1] != bingo[i][2] - bingo[j][2])flag = false;
			else if (bingo[i][2] - bingo[j][2] != bingo[i][3] - bingo[j][3])flag = false;
		}
	}
	for (int i = 0;i < 3;++i) {
		for (int j = i;j < 3;++j) {
			if (bingo[1][i] - bingo[1][j] != bingo[2][i] - bingo[2][j])flag = false;
			else if (bingo[2][i] - bingo[2][j] != bingo[3][i] - bingo[3][j])flag = false;
		}
	}
	if (flag)puts("Yes");
	else puts("No");
	return 0;
}
