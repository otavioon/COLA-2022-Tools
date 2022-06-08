#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define debug(x) cerr << #x << ": " << x << '\n'

int main()
{
    int N, M;
    map<string, int> s;
    map<string, int> t;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        s[temp] += 1;
    }
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        string temp;
        cin >> temp;
        t[temp] += 1;
    }
    int ans = 0;
    for (map<string, int>::iterator itr = s.begin(); itr != s.end(); ++itr)
    {
        int val = itr->second - t[itr->first];
        ans = max(ans, val);
    }

    cout << ans << endl;
}
