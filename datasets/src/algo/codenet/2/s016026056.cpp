#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    multiset<int> m;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m.insert(a);
    }
    int ans = 0;
    while(m.size() > 0)
    {
        int cand = *m.rbegin();
        m.erase(m.find(cand));
        ll ctwo = 1;
        while(ctwo <= cand)
        {
          ctwo *= 2;
        }
      auto fitr = m.find(ctwo - cand);

        if(fitr != m.end())
        {
            m.erase(fitr);
            ans++;
        }
    }
    cout << ans << endl;
}
