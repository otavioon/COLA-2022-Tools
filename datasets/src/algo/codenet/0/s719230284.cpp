#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.inp","r",stdin);
    long long k, i, j;
    int t;
    string s;
    t = 0;
    cin >> s >> k;
    i = 0;
    while (i < s.length()-1)
    {
        j = i+1;
        while (s[j] == s[j+1])
        {
            t++;
            j++;
        }
        if (j-1 != i) t++;
        i = j;
    }
    if (s[0] == s[s.length()-1]) t += k;
    t /= 2; t = max(1, t);
    cout << t*k;
    return 0;
}

