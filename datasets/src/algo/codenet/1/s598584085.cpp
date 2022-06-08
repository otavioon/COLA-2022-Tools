#include <cstdio>

/// @brief Verifies Takahashi's information.
///
/// \f[
/// \exists \ (a_1, a_2, a_3, b_1, b_2, b_3) \ s.t. \ 
/// \begin{pmatrix} c_{11} & c_{12} & c_{13} \\ c_{21} & c_{22} & c_{23} \\ c_{31} & c_{32} & c_{33} \end{pmatrix}
/// = 
/// \begin{pmatrix} a_1 + b_1 & a_1 + b_2 & a_1 + b_3 \\ a_2 + b_1 & a_2 + b_2 & a_2 + b_3 \\ a_3 + b_1 & a_3 + b_2 & a_3 + b_3 \end{pmatrix}
/// \f]
int main() {
    bool failed = false;
    int a[4], b[4], c[4][4];

    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            scanf("%d", &c[i][j]);
        }
    }

    a[1] = 0;
    b[1] = c[1][1];
    b[2] = c[1][2];
    b[3] = c[1][3];
    a[2] = c[2][1] - b[1];
    a[3] = c[3][1] - b[1];

    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (c[i][j] != a[i] + b[j]) {
                failed = true;
            }
        }
    }

    puts(failed ? "No" : "Yes");
}
