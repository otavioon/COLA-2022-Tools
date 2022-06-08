#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, K, x;
    cin >> N >> K;
    set<long long> s;
    for (auto i = 0; i < 10; i++)
        s.insert(i);
    for (auto i = 0; i < K; i++)
    {
        cin >> x;
        s.erase(x);
    }

    while (true)
    {
        x = N;
        long long digit = 1;
        while (x > 0)
        {

            if (s.find(x % 10) == s.end())
            {
                N = (x + 1) * digit;
                break;
            }
            digit *= 10;
            x /= 10;
        }
        if (x == 0)
            break;
    }

    cout << N << endl;

    return 0;
}
