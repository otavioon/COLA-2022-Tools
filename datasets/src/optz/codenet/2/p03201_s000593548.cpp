#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, int> wyst;
    vector<int> a;
    int odp = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ++wyst[x];
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = (int) a.size() - 1; i >= 0; --i)
    {
        int d;
        if (__builtin_popcount(a[i]) == 1)
            d = a[i];
        else
        {
            d = 1;
            while (d < a[i])
                d *= 2;
            d = d - a[i];
        }
        if (wyst[a[i]] != 0 && wyst.find(d) != wyst.end() && wyst[d] != 0)
        {
            ++odp;
            --wyst[a[i]];
            --wyst[d];
        }
    }
    cout << odp;
    return 0;
}
