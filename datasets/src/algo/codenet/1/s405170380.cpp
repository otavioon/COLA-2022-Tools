#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P_ii;
typedef pair<string, int> P_si;

int main() {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int c;
            cin >> c;
            sum += c;
        }
    }
    bool flag = false;
    for (int i = 0; i <=300; ++i) {
        if (i == sum / 3 && sum % 3 == 0) {
            flag = true;
            break;
        }
    }

    if (flag) printf("%s\n", "Yes");
    else printf("%s\n", "No");
    return 0;
}
