#include <bits/stdc++.h>

using namespace std;

const int SGM = 30;

int f[SGM];

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    string s;
    int k;
    cin >> s >> k;
//    ///dp[i][0/1] = primele i, modificam i sau nu
    if (s.size() == 1)
        return cout << k / 2, 0;
    for (int i = 0; i < s.size(); ++i)
        f[s[i] - 'a'] = 1;
    int numdist(0);
    for (int i = 0; i < SGM; ++i)
        if (f[i])
            ++numdist;
    if (numdist == 1)
        return cout << (s.size() * k) / 2, 0;
//    int adaugate(0);
//    int cur(0);
//    while (s[cur] == s.back())
//        s.push_back(s[cur++]), ++adaugate;
//    dp[0][0] = 0;
//    dp[0][1] = 1;
//    for (int i = 1; i < s.size(); ++i) {
//        if (s[i] == s[i - 1]) {
//            dp[i][0] = dp[i - 1][1];
//            dp[i][1] = 1 + min(dp[i - 1][0], dp[i - 1][1]);
//        }
//        else {
//            dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]);
//            dp[i][1] = 1 + dp[i][0];
//        }
//    }
    ///o sa fie pur si simplu pt fiecare secventa de cifre egale ans += l / 2;
    int front_back(0), first(0), last(s.size() - 1);
    char the_one(s[0]);
    bool prob(1);
    if (s[first] != s[last])
        prob = 0;
    else {
        while (s[first] == the_one)
            ++first, ++front_back;
        while (s[last] == the_one)
            --last, ++front_back;
    }
    ///acum calculam shmecheria pe [first, last]
    int imp(0);
    int capat(first);
    for (int i = first; i <= last; ++i) {
        if (i != first && s[i] != s[i - 1]) {
            imp += (i - 1 - capat + 1) / 2;
            capat = i;
        }
    }
    imp += (last - capat + 1) / 2;
    if (prob)
        cout << 1LL * imp * k + first / 2 + (s.size() - last - 1) / 2 + 1LL * front_back / 2 * (k - 1);
    else
        cout << 1LL * imp * k;
    return 0;
}
