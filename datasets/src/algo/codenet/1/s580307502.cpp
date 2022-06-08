#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int A[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%i", &A[i][j]);

    int a0, a1, a2, b0, b1, b2;
    bool flag = false;
    for (a0 = 0; a0 <= 100; a0++) {
        b0 = A[0][0] - a0;
        b1 = A[0][1] - a0;
        b2 = A[0][2] - a0;
        a1 = A[1][0] - b0;
        a2 = A[2][0] - b0;

        bool check =
            a1 + b1 == A[1][1] &&
            a1 + b2 == A[1][2] &&
            a2 + b1 == A[2][1] &&
            a2 + b2 == A[2][2];

        if (check) {
            flag = true;
            break;
        }
    }

    if (flag)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
