
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getint(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}

static void ABC042C();

#if 1
int main()
{
	ABC042C();
	fflush(stdout);
	return 0;
}
#endif

static void ABC042C()
{
	int N, K;
	getint(N, K);

	std::set<int> dn;
	for (int i = 0; i < K; i++) {
		int tmp;
		getint(tmp);
		dn.insert(tmp);
	}

	std::set<int> use;
	for (int i = 0; i < 10; i++) {
		if (dn.find(i) == dn.end()) {
			use.insert(i);
		}
	}
	int nowPrice = N;
	int digitCount = use.size();

	while (1) {
		int now = nowPrice;
		while (now) {
			int lsb = now % 10;
			if (use.find(lsb) == use.end()) {
				break;
			}
			now /= 10;
		}

		if (!now) break;
		nowPrice++;
	}

	printf("%d\n", nowPrice);
}
