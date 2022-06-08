#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>

// using namespace std;

#define Rep(i,a,b) for(int i = a; i < b; i++)
#define rep(i,b) Rep(i,0,b)
#define allof(a) (a).begin(), (a).end()

typedef long long ll;
const int inf = 1e9 + 7;
const ll infll = 1ll << 60ll;
const ll mod = 1e9 + 7;
// 0~3までは右左下上 4~7までは斜め
constexpr int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
constexpr int dy[] = { 0, -1, 0, 1, 1, -1, -1, 1 };

namespace {  // 名前なし名前空間
	// gcd, lcm は C++17 でstdに標準入りしたので言語のバージョンに注意
	// 最大公約数
	ll gcd(ll a, ll b) {
		if (b == 0) return a;
		return gcd(b, a % b);
	}

	// 最小公倍数
	ll lcm(ll a, ll b) {
		return a / gcd(a, b) * b;
	}

	ll getRemainNum(const std::vector<ll>&h, int n, ll a, ll b, ll num) {
		ll res = 0;
		ll eachDamage = a - b;
		ll accumDamage = b * num;
		rep(i, n) {
			if (h[i] > accumDamage) {
				res += (h[i] - accumDamage - 1) / eachDamage + 1;
			}
		}
		return res;
	}
}

int main() {

	int n;
	ll a, b;
	std::cin >> n >> a >> b;
	std::vector<ll> h(n);
	rep(i, n) std::cin >> h[i];
	std::sort(allof(h), std::greater<ll>());
	// 1回攻撃するたびに敵全員のHPをBだけ減らす
	// さらに，敵一帯に対してa - bダメージ与える

	// あと追加のa-bダメージが何回必要か
	ll right = (h[0] - 1) / b + 2;
	ll left = -1;
	// 左の境界線を探す
	while (right - left > 1) {
		ll mid = (right + left) / 2;
		ll remain = getRemainNum(h, n, a, b, mid);
		if (remain > mid) {
			// 右を探す
			left = mid;
		}
		else right = mid;
	}
	// mid = low, right = low + 1 = mid + 1 となっている
	ll ans = right;

	std::cout << ans << std::endl;

	return 0;
}