#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
ll B[100005];
ll C[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, N)
    {
        cin >> B[i];
    }
    REP(i, N)
    {
        cin >> C[i];
    }
    sort(A, A + N);
    sort(B, B + N);
    sort(C, C + N);

    ll sum = 0;
    REP(i, N)
    {
        ll a = 0;
        {
            int ok = -1, ng = N;
            while (abs(ok - ng) > 1)
            {
                int mid = (ok + ng) / 2;
                if (A[mid] < B[i])
                    ok = mid;
                else
                    ng = mid;
            }
            a = ok + 1;
        }
        ll c = 0;
        {
            int ok = N, ng = -1;
            while (abs(ok - ng) > 1)
            {
                int mid = (ok + ng) / 2;
                if (B[i] < C[mid])
                {
                    ok = mid;
                }
                else
                {
                    ng = mid;
                }
            }
            c = N - ok;
        }
        sum += a * c;
    }
    cout << sum << endl;
    return 0;
}