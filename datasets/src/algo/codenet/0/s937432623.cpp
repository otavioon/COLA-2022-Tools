#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

string s;
llong k;
llong ans;

int main() {
    cin >> s;
    cin >> k;

    string t = s;
    s += s;

    for (int i = 0; i < s.size(); i++) {
        int cnt = 0;
        while(s[i] == s[i + 1] && i < s.size()) {
            i++;
            cnt++;
        }
        cnt++;
        ans += cnt / 2;
    }
    ans *= k / 2;

    if (k % 2 == 1) {
        int cnt = 0;
        int i = t.size() - 1;
        while (t[i] == t[i - 1] && i > 0) {
            cnt++;
            i--;
        }
        cnt++;

        ans -= cnt / 2;
        t += t;

        for (; i < t.size(); i++) {
            int cnt = 0;
            while (t[i] == t[i + 1] && i < t.size()) {
                i++;
                cnt++;
            }
            cnt++;
            ans += cnt / 2;
        }
    }
    
    /*
    llong n = s.size();
    llong i = n - 1;
    if (s[n - 1] == s[0] && s[n - 1] != s[n - 2]) {
        ans += k - 1;
        i = n - 2;
    }
    else if (s[n - 1] == s[0]) {
        ans += k;
        i = n - 3;
    }

    for (; i > 0; i--) {
        if (s[i] == s[i - 1]) {
            ans += k;
            i--;
        }
    }
    cout << ans << endl;
    */

    cout << ans << endl;

    return 0;
}
