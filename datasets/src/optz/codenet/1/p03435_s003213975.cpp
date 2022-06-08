#include <bits/stdc++.h>
using namespace std;

int store[5][5];

int main()
{
    int a1, a2, a3;
    int b;
    for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) cin >> store[i][j];

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i == 1) {
                a1 = store[1][1];
                a2 = store[1][2];
                a3 = store[1][3];
            }
            else {
                if (j == 1) b = a1 - store[i][j]; /// cout << "1. " << b << endl;
                else if (j == 2) {if (a2 - store[i][j] != b) {printf("No\n"); return 0;}} ///cout << "2. " << a2 - store[i][j] << endl;
                else if (j == 3) {if (a3 - store[i][j] != b) {printf("No\n"); return 0;}} ///cout << "3. " << a3 - store[i][j] << endl;
            }
        }
    }

    printf("Yes\n");
}
