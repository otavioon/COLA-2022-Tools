#include <bits/stdc++.h>
using namespace std;

int solve(long long N, std::vector<long long> a)
{
    long long cnt = 1;
    long long n;
    for (int i = 1; i <= N; i++)
    {
        cnt++;
        if (i == 1)
            n = a[i];
        else
            n = a[n];

        if (a[n] == 2)
        {
            cout << cnt << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
}

// Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main()
{
    long long N;
    scanf("%lld", &N);
    std::vector<long long> a(N + 1);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
