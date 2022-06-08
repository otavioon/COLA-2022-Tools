#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll MOD = 1e9 + 7;
const long long INF = 1LL << 60;

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> d;
    rep(i, k)
    {
        int input;
        cin >> input;
        d.insert(input);
    }

    int answer = n;
    while (true)
    {
        int digit_num = to_string(answer).size();
        bool is_ok = true;
        for (int i = 0; i < digit_num; i++)
        {
            int ith_num = ctoi(to_string(answer).at(i));
            if (d.count(ith_num) == 1)
            {
                is_ok = false;
                break;
            }
        }
        if (is_ok)
        {
            break;
        }
        else
        {
            answer++;
        }
    }

    cout << answer << endl;
}