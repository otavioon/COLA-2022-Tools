#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, count, ans;
    cin >> n;
    vector<string> s(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s.at(i);
    }
    cin >> m;
    vector<string> t(m);
    for (int i = 0; i < m; i++)
    {
        cin >> t.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (s.at(i) == s.at(j))
            {
                count++;
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (s.at(i) == t.at(j))
            {
                count--;
            }
        }
        a.at(i) = count;
    }
    ans = max(a.at(0), 0);
    for (int i = 1; i < n; i++)
    {
        ans = max(a.at(i), ans);
    }
    cout << ans << endl;
}