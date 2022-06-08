#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <stack>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <climits>
#include <list>
#include <time.h>
#include <unordered_map>
#include <bitset>
#include <exception>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INPUT "/Users/bekhzodsoliev/Desktop/C++/cp/cp/file.in"
#define OUTPUT "/Users/bekhzodsoliev/Desktop/C++/cp/cp/file.out"
#define lc v << 1
#define rc (v << 1) + 1
#define inf 1e+9
#define linf ll(1e+18)
#define dinf 1e+14

typedef long long ll;
#define pb push_back
#define mp make_pair

vector<string> a, b;
set<string> c;
void solve()
{
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        c.insert(a[i]);
    }
    
    int m;
    cin >> m;
    b.resize(m);
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
        c.insert(b[i]);
    }
    
    int ans = 0;
    while(c.size() > 0)
    {
        string cur = *c.begin();
        c.erase(c.begin());
        int temp = 0;
        for(int i = 0; i < n; i++)
        {
            temp += (cur == a[i]);
        }
        
        for(int i = 0; i < m; i++)
        {
            temp -= (cur == b[i]);
        }
        ans = max(ans, temp);
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    //freopen(INPUT, "r", stdin);freopen(OUTPUT, "w", stdout);
    int t = 1;
    //cin >> t;
    
    while(t--)
    {
        solve();
    }
    
    return 0;
}

