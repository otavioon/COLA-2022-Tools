#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll mod = 1e9 +7;


int main() {
    

    string s;
    ll k;
    cin >> s >> k;
    
    string ss = s + s;
    
    ll st = 0;
    bool f = 0;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] != s[i - 1])
        {
            st = i;
            break;
        }
        if (i == s.size() - 1)
        {
            f = 1;
            break;
        }
    }
    if (f)
    {
        cout << (s.size() * k) / 2ll << endl;
        return 0;
    }
    
    ll c1 = 0, c2 = 0, c3 = 0;
    
    for (int i = 1; i < st; ++i)
    {
        if (ss[i] == ss[i - 1])
        {
            c1++;
            i++;
        }

    }
    for (int i = st + 1; i < st + s.size(); ++i)
    {
        if (ss[i] == ss[i - 1])
        {
            c2++;
            i++;
        }

    }
    
    for (int i = st + 1; i < s.size(); ++i)
    {
        if (ss[i] == ss[i - 1])
        {
            c3++;
            i++;
        }

    }
    
    
    ll ret = c1 + (k - 1ll) * c2 + c3;
    cout << ret << endl;
    
    return 0;
}