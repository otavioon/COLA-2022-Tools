#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, s, t, c;
    cin >> n >> k;
    set<int> st;
    for (int i = 0; i < k; i++)
    {
        cin >> t;
        st.insert(t);
    }
    s = n;
    c = 0;
    while (s != 0)
    {
        t = s % 10;
        s = s / 10;
        if (st.find(t) != st.end())
        {
            c++;
            s = n + c;
            continue;
        }
    }
    cout << n + c << endl;
}