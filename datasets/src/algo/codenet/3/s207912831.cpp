#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const long double EPS = 1e-9;
const ll mod = 1e9 + 7;
const ll INF = 1e9;

#define rep(i, n) for(ll i = 0; i < n ; i++ )
#define For(i, a, b) for(ll i = (a); i < (b) ; i++ )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll MAX_N = 100000;

int main(void){
    ll N;
    ll A[MAX_N], B[MAX_N], C[MAX_N];
    ll l[MAX_N + 1], u[MAX_N + 1];
    ll answer = 0;

    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    sort(A, A + N);
    sort(B, B + N);
    sort(C, C + N);

    l[0] = 0;
    u[N] = 0;
    rep(i, N){
        l[i + 1] = l[i];
        u[N - i - 1] = u[N - i];
        For(j, l[i], N) if (A[j] < B[i]) l[i + 1] ++; else break;
        For(j, u[N - i], N) if (B[N - i - 1] < C[N - j - 1]) u[N - i - 1] ++; else break;
    }

    rep(i, N) answer += l[i + 1] * u[i];

    cout << answer << endl;

    return 0;
}
