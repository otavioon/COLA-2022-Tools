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
typedef vector<bool> vbool;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<llint> vllint;
typedef vector<vllint> vvllint;
typedef vector<pair<int, int>> vpint;
typedef vector<pair<llint, llint>> vpllint;
#define rep(i,n) for(int i=0;i<n;i++)
#define drep(i,n) for(int i=n-1;0<=i;i--)
#define yes(ans) if(ans)cout<<"yes"<<endl;else cout<<"no"<<endl;
#define Yes(ans) if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define POSSIBLE(ans) if(ans)cout<<"POSSIBLE"<<endl;else cout<<"IMPOSSIBLE"<<endl;
#define Pi 3.1415926535897932384626
#define coutans rep(i, ans.size())cout << ans[i] << endl;
#define mod (llint)1000000007
#define int_max 2147483647
#define ll_max (llint)9223372036854775807

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

bool check(llint a, llint b) {
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

bool IsPrime(llint num) {
	if (num < 2) return false;
	else if (num == 2) return true;
	else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

	double sqrtNum = sqrt(num);
	for (llint i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			// 素数ではない
			return false;
		}
	}

	// 素数である
	return true;
}

//aのb乗を求める(1000000007で割った余りやで)
llint modpow(llint a, llint b) {
	if (b == 0)return 1;
	if (b == 1)return a;
	llint tmp = modpow(a, b / 2);
	tmp %= mod;
	tmp = tmp * tmp % mod;
	if (b % 2)return tmp * a % mod;
	else return tmp;
}

//aCbを1000000007で割った余りを求める
llint convination(llint a, llint b) {
	llint ans = 1;
	for (llint i = 0; i < b; i++) {
		ans *= a - i;
		ans %= mod;
	}
	for (llint i = 1; i <= b; i++) {
		ans *= modinv(i, mod);
		ans %= mod;
	}
	return ans;
}


int main() {
	int a[3][3];
	rep(i, 3)rep(j, 3)cin >> a[i][j];
	Yes(a[0][0] - a[0][1] == a[1][0] - a[1][1] &&
		a[1][0] - a[1][1] == a[2][0] - a[2][1] &&
		a[0][2] - a[0][1] == a[1][2] - a[1][1] &&
		a[1][2] - a[1][1] == a[2][2] - a[2][1] &&
		a[2][0] - a[1][0] == a[2][1] - a[1][1] &&
		a[2][1] - a[1][1] == a[2][2] - a[1][2] &&
		a[0][0] - a[1][0] == a[0][1] - a[1][1] &&
		a[0][1] - a[1][1] == a[0][2] - a[1][2]);
	return 0;
}