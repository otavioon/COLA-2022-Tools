#include <bits/stdc++.h>
using namespace std;
int main () {
    int c[9];
    for (int i = 0; i < 9; i++) {
        cin >> c[i];
    }
    set<vector<int>> s;
    for (int i = 0; i < 3; i++) {
        vector<int> v;
        for (int j = 3+i; j < 9; j += 3) {
            v.push_back(c[j]-c[j-3]);
        }
        s.insert(v);
    }
    if (s.size() == 1) {
        puts("Yes");
    }
    else {
        puts("No");
    }
}