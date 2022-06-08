#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

ll b_search(ll N, ll S[], ll target)
{
    ll ok = -1;
    ll ng = N;

    while (ok + 1 < ng)
    {
        ll mid = (ok + ng) / 2;
        if (S[mid] >= target)
        {
            ng = mid;
        }
        else
        {
            ok = mid;
        }
    }

    return ok + 1;
}

ll b_search2(ll N, ll S[], ll target)
{
    ll ng = -1;
    ll ok = N;

    while (ng + 1 < ok)
    {
        ll mid = (ok + ng) / 2;
        if (S[mid] <= target)
        {
            ng = mid;
        }
        else
        {
            ok = mid;
        }
    }

    return N - ok;
}

int main()
{
    ll N;
    cin >> N;

    ll A[N], B[N], C[N];
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];
    sort(A, A + N);
    sort(B, B + N);
    sort(C, C + N);

    // Bを固定して考える
    ll ans = 0;
    rep(i, N)
    {
        ll b = B[i];
        // 許容されるAの種類 * 許容されるCの種類
        ans += b_search(N, A, b) * b_search2(N, C, b);
    }

    cout << ans << endl;

    return 0;
}