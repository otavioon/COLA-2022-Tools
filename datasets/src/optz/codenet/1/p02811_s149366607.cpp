/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
		  　　　　　　　　　　(¸.·´ (¸.·'* ☆
					*/

#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <numeric>
#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <queue>
#include <regex>
#include <functional>
/*多倍長整数/cpp_intで宣言
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
*/

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i <= (n); ++i)
#define rep2(i, n) for(int i = 2; i < (n); ++i)
#define repr(i, n) for(int i = n; i >= 0; --i)
#define reprm(i, n) for(int i = n - 1; i >= 0; --i)
#define printynl(a) printf(a ? "yes\n" : "no\n")
#define printyn(a) printf(a ? "Yes\n" : "No\n")
#define printYN(a) printf(a ? "YES\n" : "NO\n")
#define printin(a) printf(a ? "possible\n" : "inposible\n")
#define printdb(a) printf("%.50lf\n", a)//少数出力
#define printdbd(a) printf("%.16lf\n", a)//少数出力(桁少なめ)
#define prints(s) printf("%s\n", s.c_str())//string出力
#define all(x) (x).begin(), (x).end()
#define allsum(a, b, c) ((a + b) * c / 2)//等差数列の和、初項,末項,項数
#define pb push_back
#define priq priority_queue
#define rpriq priq<int, vector<int>, greater<int>>
#define deg_to_rad(deg) (((deg)/360.0)*2.0*PI)
#define rad_to_deg(rad) (((rad)/2.0/PI)*360.0)
#define Please return
#define AC 0
#define debug(aa, a) fprintf(stderr, aa, a)

using ll =long long;

constexpr int INF = 1073741823;
constexpr int MINF = -1073741823;
constexpr ll LINF = ll(4661686018427387903);
constexpr ll MOD = 1000000007;
const long double PI = acos(-1.0L);

using namespace std;

void scans(string& str) {
	char c;
	str = "";
	scanf("%c", &c);
	if (c == '\n')scanf("%c", &c);//最初の改行対策
	while (c != '\n' && c != -1) {
		str += c;
		scanf("%c", &c);
	}
}

void scanc(char& str) {
	char c;
	scanf("%c", &c);
	if (c == -1)return;
	while (c == '\n') {
		scanf("%c", &c);
	}
	str = c;
}

double acot(double x) {
	return PI / 2 - atan(x);
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll number1, ll number2) {//lcmを求める
	return number1 / gcd(number1, number2) * number2;
}

/*-----------------------------------------ここからコード-----------------------------------------*/



int main() {

	int k, x;
	scanf("%d%d", &k, &x);
	k *= 500;
	printyn(k >= x);

	Please AC;
}
