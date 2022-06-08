# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define RALL(x) (x).rbegin(), (x).rend()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define debug(x) std::cerr<<#x<<": "<<(x)<<endl;
using namespace std;
using lint = long long;
template<class T> using grid = vector<vector<T>>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
static const lint MOD = (lint)1e9+7;

lint Sum(vector<lint> nums)
{
    lint sum = 0;
    rep (i, SZ(nums))
    {
        sum += nums[i];
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;
    vector<lint> B(N-1);
    rep (i, N-1)
    {
        cin >> B[i];
    }

    vector<lint> A(N);
    A[0] = B[0];
    for (int i = N - 1; i >= 0; --i)
    {
        A[i-1] = min(B[i-1], B[i]);
    }
    A[N-1] = B[N-2];

    rep (i, N)
    {
        cerr << A[i] << " ";
    }
    cerr << endl;

    lint sum = Sum(A);
    cout << sum << endl;

    return 0;
}
