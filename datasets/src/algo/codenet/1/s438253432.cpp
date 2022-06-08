#include <bits/stdc++.h>
using namespace std;
int main() {
        int ar[4][4];
        for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                        cin >> ar[i][j];
        for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                        if (ar[i][j] != ar[i][i] + ar[j][j] - ar[j][i]) {
                                cout << "No";
                                return 0;
                        }
        cout << "Yes";
        return 0;
}
