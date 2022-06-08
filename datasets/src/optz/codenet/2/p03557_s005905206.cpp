#include <iostream>
#include <algorithm>

#define int long long
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)

using namespace std;

int N;
int A[100001];
int B[100001];
int C[100001];

int bb[100001];

signed main()
{
    cin >> N;
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) cin >> C[i];

    sort(A, A+N);
    sort(B, B+N);
    sort(C, C+N);

    for (int i = N-1; i >= 0; --i)
    {
        int b = B[i];
        int* cpos = upper_bound(C, C+N, b);
        bb[i] = (C + N - cpos);
        if (i != N-1) bb[i] += bb[i+1];
    }

    int ans = 0;
    REP(i, N)
    {
        int a = A[i];
        int* bpos = upper_bound(B, B+N, a);
        ans += bb[bpos - B];
    }

    cout << ans << endl;

    return 0;
}