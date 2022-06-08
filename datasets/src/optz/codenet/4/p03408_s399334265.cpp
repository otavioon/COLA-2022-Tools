#include <bits/stdc++.h>
using namespace std;
#define REP(i, t) for (int i = 0; i < t; i++)

int main()
{
    int N, M;
    string s[110], t[110];
    set<string> kinds;
    cin >> N;
    REP(i, N) cin >> s[i], kinds.insert(s[i]);
    cin >> M;
    REP(i, M) cin >> t[i], kinds.insert(t[i]);

    int now_max = 0;
    for (string c : kinds)
    {
        int now_get = count(&s[0], &s[N], c) - count(&t[0], &t[M], c);
        now_max = max(now_max, now_get);
    }

    cout << now_max << endl;

    return 0;
}
