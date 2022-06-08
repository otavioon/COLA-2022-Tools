#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <algorithm>
#include <cstring>

using namespace std;


set<int> banned;

int next(int x) {
    for (int i = x + 1; i <= 9; ++i)
        if (!banned.count(i))
            return i;
}

int main() {
    int n, k, saven;
    cin >> n >> k;
    saven = n;
    for (int i = 0; i < k; ++i) {
        int tmp;
        cin >> tmp;
        banned.insert(tmp);
    }
    banned.insert(10);

    vector<int> nx;
    int make_bigger = -1;
    while (n) {
        int d = n % 10;
        nx.push_back(d);
        n /= 10;

        if (make_bigger == nx.size() - 1)
            d++;
        if (!banned.count(d)) {
            continue;
        }

        bool ok = false;
        for (int i = d + 1; i <= 9; ++d)
            if (!banned.count(i)) {
                ok = true;
                break;
            }
        if (!ok)
            make_bigger = nx.size();
        else
            make_bigger = nx.size() - 1;
    }
    if (make_bigger == -1) {
        cout << saven;
        return 0;
    }

    int smallest = -1;
    for (int i = 0; i <= 9; ++i)
        if (!banned.count(i)) {
            smallest = i;
            break;
        }
    if (make_bigger == nx.size()) {
        cout << next(0);
        for (int i = 0; i < nx.size(); ++i)
            cout << smallest;
        return 0;
    }
    int i;
    for (i = nx.size() - 1; i >= 0; --i) {
        if (i != make_bigger)
            cout << nx[i];
        else {
            cout << next(nx[i]);
            i--;
            break;
        }
    }
    for (;i >=0; --i)
        cout << smallest;

    return 0;
}
