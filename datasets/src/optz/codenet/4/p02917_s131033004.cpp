#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<string.h>
#include<complex>
#include<math.h>
#include<queue>
#include<time.h>
using namespace std;
typedef long long int llint;
typedef pair<int, int> pint;
typedef pair < llint, llint> pllint;
typedef vector<int> vint;
typedef vector<llint> vllint;
typedef vector<pint> vpint;
typedef vector<pair<llint, llint>> vpllint;
typedef vector<vector<int>> vvint;
typedef vector<vector<llint>> vvllint;
typedef vector<vector<pint>> vvpint;
typedef vector<bool> vbool;
#define rep(i,n) for(int i=0;i<n;i++)
#define drep(i,n) for(int i=n-1;0<=i;i--)
#define yes(ans) if(ans)cout<<"yes"<<endl;else cout<<"no"<<endl;
#define Yes(ans) if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define POSSIBLE(ans) if(ans)cout<<"POSSIBLE"<<endl;else cout<<"IMPOSSIBLE"<<endl;
#define Pi 3.1415926535897932384626

class UnionFind {
public:
	//親の番号を格納する。親だった場合は-(その集合のサイズ)
	vector<int> Parent;

	//作るときはParentの値を全て-1にする
	//こうすると全てバラバラになる
	UnionFind(int N) {
		Parent = vector<int>(N, -1);
	}

	//Aがどのグループに属しているか調べる
	int root(int A) {
		if (Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}

	//自分のいるグループの頂点数を調べる
	int size(int A) {
		return -Parent[root(A)];//親をとってきたい
	}

	//AとBをくっ付ける
	bool connect(int A, int B) {
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) {
			//すでにくっついてるからくっ付けない
			return false;
		}

		//大きい方(A)に小さいほう(B)をくっ付けたい
		//大小が逆だったらひっくり返しちゃう。
		if (size(A) < size(B)) swap(A, B);

		//Aのサイズを更新する
		Parent[A] += Parent[B];
		//Bの親をAに変更する
		Parent[B] = A;

		return true;
	}
};

//aとbの最大公約数を求めるよ
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
long long extGCD(long long a, long long b, long long& x, long long& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

bool check(int a, int b) {
	return a > b;
}

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

//aCbを1000000007で割った余りを求める
llint convination(llint a, llint b) {
	llint ans = 1;
	for (llint i = 0; i < b; i++) {
		ans *= a - i;
		ans %= 1000000007;
	}
	for (llint i = 1; i <= b; i++) {
		ans *= modinv(i, 1000000007);
		ans %= 1000000007;
	}
	return ans;
}

//aのb乗を1000000007で割った余りを求める
llint power(llint a, llint b) {
	if (b == 1)return a;
	if (b == 0)return 1;
	llint tmp = power(a, b / 2);
	tmp *= tmp;
	tmp %= 1000000007;
	if (b % 2 == 1) {
		tmp *= a;
		tmp %= 1000000007;
	}
	return tmp;
}

int main() {
	int n;
	cin >> n;
	vint a(n - 1);
	llint ans = 0;
	rep(i, n - 1) {
		cin >> a[i];
	}
	rep(i, n - 1) {
		if (i == 0)ans += (llint)a[i];
		else ans += (llint)min(a[i], a[i - 1]);
	}
	ans += (llint)a[n - 2];
	cout << ans << endl;
	return 0;
}
