#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    string s;
    map<string, int> a, b;

    cin >> n;
    while (n--) {
        cin >> s;
        a[s]++;
    }
    cin >> m;
    while (m--) {
        cin >> s;
        b[s]++;
    }

    int ans = 0;
    for (auto t : a) {
        ans = max(ans, a[t.first] - b[t.first]);
    }
    cout << ans << endl;
    
    return 0;
}
