#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
#define all(v) v.begin(), v.end()
const int inf = 1000000000; //10^9
using ll = long long;
using P = pair<int, int>;
//加算代入演算子は+=！！！！！
int n, k, num, ans;
vector<bool> flag(10, false);
bool check(int n)
{
    while (n > 0)
    {
        if (flag.at(n % 10) == true)
        {
            return false;
        }
        else
        {
            n /= 10;
        }
    }
    return true;
}
int main()
{
    cin >> n >> k;
    rep(i, k)
    {
        cin >> num;
        flag.at(num) = true;
    }
    for (int i = n; i < 100000; i++) {
        if (check(i) == true)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}