#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P_ii;
typedef pair<string, int> P_si;

int main() {
    int grid[5][5];
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> grid[i][j];
            sum += grid[i][j];
        }
    }
    bool flag = false;
    for (int i = 0; i <=600; ++i) {
        if (i == sum / 3 && sum % 3 == 0) {
            flag = true;
            break;
        }
    }

    if (flag) printf("%s", "Yes");
    else printf("%s", "No");
    return 0;
}
