#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
        string s;
        int k;
        cin >> s >> k;

        if (s.size() == 1)
                return cout << k / 2, 0;

        int first = -1, last, ans = 0;
        for (int i = 0; i < s.size(); i++) {
                int cur = 1;
                while (i + 1 < s.size() && s[i + 1] == s[i])
                        ++i, ++cur;
                if (!~first)
                        first = cur;
                last = cur;
                ans += cur / 2;
        }
        if (s.front() == s.back()) {
                ans += (first & 1) && (last & 1);
        }

        cout << ans * k;

        return 0;
}
