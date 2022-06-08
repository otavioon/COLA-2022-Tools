#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

using ll = long long;

const int INF = 1001001001;
int n, a, b;
vector<int> h(100005);

// 二分探索用判定関数
bool C(int num)
{
    vector<int> temp(h.begin(), h.begin() + n);

    ll res = 0;
    ll subtraction = b * num;
    for (int i = 0; i < n; ++i)
    {
        if (h[i] > subtraction)
        {
            res += ceil((double)(h[i] - subtraction) / (a - b));
        }
    }
    cout << res << endl;

    return res <= num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
    }

    int lb = 0, ub = 1e13;
    while (ub - lb > 1)
    {
        int mid = (lb + ub) / 2;
        if (C(mid))
            ub = mid;
        else
            lb = mid;
    }

    cout << ub << endl;
}