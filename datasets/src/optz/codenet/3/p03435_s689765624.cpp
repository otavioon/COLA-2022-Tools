#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const long long MOD = 1000000007;
long long modpow(long long a, long long n, long long m)
{
    long long ans = 1;
    while (n)
    {
        if (n & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return ans;
}
long long combi(long long n, long long a)
{
    long long ans = 1, ans1 = 1;
    for (long long i = n - a + 1; i <= n; i++)
    {
        ans *= i % MOD;
        ans %= MOD;
    }

    for (long long i = 2; i <= a; i++)
        ans1 = (ans1 * i) % MOD;
    ans1 = modpow(ans1, MOD - 2, MOD);
    return ((ans % MOD) * ans1) % MOD;
}

void dfs(string s, char mx, ll N)
{
    if (s.length() == N)
    {
        cout << s.c_str() << endl;
    }
    else
    {
        for (char c = 'a'; c <= mx; c++)
        {
            dfs(s + c, ((c == mx) ? (char)(mx + 1) : mx), N);
        }
    }
}

int bfs(int i, int j, int h, int w, char tmp[][21])
{
    int ans[21][21] = {0};
    char c[21][21] = {0};
    queue<pair<int, int>> s;

    for (int i = 0; i<=h; i++){
        for(int j=0; j<=w; j++){
            c[i][j] = tmp[i][j];
        }
    }

        s.push(make_pair(i, j));

    while (s.size() > 0)
    {

        pair<int, int> tmp = s.front();
        s.pop();
        c[tmp.first][tmp.second] = '#';
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (tmp.first + i < 1 || tmp.first + i > h)
                {
                    continue;
                }
                if (tmp.second + j < 1 || tmp.second + j > w)
                {
                    continue;
                }
                if (i != 0 && j != 0)
                {
                    continue;
                }
                if (i == 0 && j == 0)
                {
                    continue;
                }
                if (c[tmp.first + i][tmp.second + j] == '#')
                {
                    continue;
                }
                c[tmp.first + i][tmp.second + j] = '#';
                if (ans[tmp.first + i][tmp.second + j] == 0)
                {
                    ans[tmp.first + i][tmp.second + j] = ans[tmp.first][tmp.second] + 1;
                }
                else
                {
                    ans[tmp.first + i][tmp.second + j] = min(ans[tmp.first + i][tmp.second + j], ans[tmp.first][tmp.second] + 1);
                }
                s.push(make_pair(tmp.first + i, tmp.second + j));
            }
        }
    }

    int a = 0;

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            a = max(a, ans[i][j]);
        }
    }

    return a;
}


int main()
{
    int c[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> c[i][j];
        }
    }

    int b1, b2, b3;
    for(int a1=0; a1<=100; a1++){
        b1 = c[0][0]-a1;
        b2 = c[0][1]-a1;
        b3 = c[0][2]-a1;
        if(c[1][0]-b1 != c[1][1]-b2 ||
           c[1][2]-b3 != c[1][0]-b1 ){
               continue;
           }
        if(c[2][0]-b1 != c[2][1]-b2 ||
           c[2][2]-b3 != c[2][0]-b1 ){
               continue;
           }

        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}

/*

a1+b1=c11
a1+b2=c12
a1+b3=c13
a2+b1=c21
a2+b2=c22
a2+b3=c23
a3+b1=c31
a3+b2=c32
a3+b3=c33

*/