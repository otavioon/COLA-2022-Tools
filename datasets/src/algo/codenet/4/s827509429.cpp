#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main()
{
    vector<bool> digit(10);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int now;
        cin >> now;
        digit.at(now) = true;
    }
    for (int i = n;; i++)
    {
        int now = i;
        bool ans = true;
        while (now != 0)
        {
            int next = now % 10;
            if (digit.at(next))
            {
                ans = false;
            }
            now /= 10;
        }
        if (ans)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}