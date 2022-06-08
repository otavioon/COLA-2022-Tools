#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int CMax = 3;

int n, A[CMax][CMax], ats;

int main() {
    n = CMax;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < n-1; i++) {
        if (
            A[i][0] - A[i+1][0] != A[i][1] - A[i+1][1] ||
            A[i][1] - A[i+1][1] != A[i][2] - A[i+1][2] ||
            A[0][i] - A[0][i+1] != A[1][i] - A[1][i+1] ||
            A[1][i] - A[1][i+1] != A[2][i] - A[2][i+1]
        ) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
}
