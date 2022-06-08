#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int main() {
    int n, m;
    cin >> n;
    set<string> st;
    string s[110];
    string t[110];
    imfor(i, n) {
        cin >> s[i];
        st.insert(s[i]);
    }
    cin >> m;
    imfor(i, m) {
        cin >> t[i];
        st.insert(t[i]);
    }
    int ans = 0;
    for (string x : st) {
        int tmp = 0;
        imfor(i, n) {
            if (s[i] == x) {
                tmp++;
            }
        }
        imfor(i, m) {
            if (t[i] == x) {
                tmp--;
            }
        }
        if (tmp > ans) {
            ans = tmp;
        }
    }
    cout << ans << endl;
}