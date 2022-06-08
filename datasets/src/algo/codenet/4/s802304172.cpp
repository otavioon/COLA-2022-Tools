#include <bits/stdc++.h>

#define forn(l, r) for(int i = l; i < (r); ++i)
#define forj(l, r) for(int j = l; j < (r); ++j)
#define TAM 1000100
#define SYNC ios::sync_with_stdio(0);
#define $ << ' ' <<
#define F first
#define S second
#define endl '\n'


using namespace std;

using ll = long long int;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;
using graph = vector<vi>;
const int INF = 0x3f3f3f3f;
const int MAXN = 112345;
const ll mod = 1000000007;

int nums[11];

int main()
{
    int n, k;
    set<int> setint;
    string s;
    cin >> s >> k;
    while (k--) {
        int i;
        cin >> i;
        setint.insert(i);
    }
    n = stoi(s, nullptr);
    for (int i = 0; i < (int) s.size(); ++i) {
        if (setint.find(s[i]-'0') != setint.end()) {
            n++;
            i = -1;
            s = to_string(n);
        }
    }
    cout << n << endl;
    return 0;
}
