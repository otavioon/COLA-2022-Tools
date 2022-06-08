#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const ll INF = 1e9 + 7;
const ll inf = 1LL << 50;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
///////////////////////////////////////

//整数Tに対しenough(T)をT回以内の爆発ですべての魔物を消すことは可能か？という問いの答え
//とする。求めたい答えはenough(T)=YesであるようなTの最小値です。enoughは単調性を持つため
//この最小値を二分探索で求めることができる
//定められたTの値に対してenough(T)を判定するには爆発を起こすことを以下のようにとらえなおす
//すべての魔物の体力をBずつ減らし魔物を一体選んでその体力をさらにA-B減らす
//するとT回の爆発を起こすことはすべての魔物の体力をB*T減らしその上でT回にわたって
//一体の魔物の体力をA-B減らすことと同等すべての魔物を消すには体力がB*Tより高い魔物
//iにそれぞれに対して追加ダメージを[(hi-B*T)/(A-B)]回与える必要がありこの回数の合計が
//T以下であればenough(T)=Yes,合計がTを超える場合はenough(T)=Noと判定できます

int N, A, B;
int h[100100];
bool ok(int k) {
	int cnt = 0;
	int sa = A - B;
	for (int i = 0; i < N; ++i) {
		if (h[i] > B*k) {
			cnt += (h[i] - B * k + (A - B) - 1)/ (A - B);
		}
	}
	return (cnt <= k);
}
int main() {
	cin >> N >> A >> B;
	REP(i, N)cin >> h[i];
	int l = 0;
	int r = 1e10;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (ok(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r << endl;
	return 0;
}