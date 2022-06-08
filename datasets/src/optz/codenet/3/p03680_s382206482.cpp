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

#pragma GCC optimize("Ofast")
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
#define ushi int
#define tapu main
#define nichia (
#define kunn void
#define wara )

using ll = long long;

const int INF = 1073741823;
const int MINF = -1073741823;
const ll LINF = ll(4661686018427387903);
const ll MOD = 1000000007;
const double PI = acos(-1);

using namespace std;

void scans(string& str) {
	char c;
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

/*-----------------------------------------ここからコード-----------------------------------------*/

int main(){

	int n;
	scanf("%d", &n);
	vector<int> a(n);
	rep(i, n)scanf("%d", &a[i]);
	vector<bool> pushed(n);
	int now = 0, count = 0;
	while (now != 1) {
		now = a[now] - 1;
		if (pushed[now])break;
		pushed[now] = true;
		++count;
	}
	printf("%d\n", now == 1 ? count : -1);
	Please AC;
}
