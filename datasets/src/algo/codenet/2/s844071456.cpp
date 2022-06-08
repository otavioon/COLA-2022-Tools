/*  -*- coding: utf-8 -*-
 *
 * b.cc: B - Powers of two
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 200000;

/* typedef */

/* global variables */

int as[MAX_N];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d", as + i);
  sort(as, as + n);

  int cnt = 0;
  for (int i = 0, j = n - 1; i < j; i++) {
    int b = 0;
    while (i < j) {
      b = 1 << 30;
      while ((b >> 1) >= as[j]) b >>= 1;
      if (as[i] <= b - as[j]) break;
      j--;
    }
    if (i >= j) break;

    if (as[i] + as[j] == b) cnt++;
  }

  printf("%d\n", cnt);
  return 0;
}
