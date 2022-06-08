#include <cassert>
#include <cstdio>
#include <cstdlib>

int
main()
{
    int c[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            assert(scanf("%d", &c[i][j]) == 1);
    int diff[3];
    for (int j = 0; j < 3; j++)
        diff[j] = c[0][j] - c[0][0];
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (c[i][j] - c[i][0] != diff[j]) {
                printf("No\n");
                exit(0);
            }
        }
    }
    printf("Yes\n");
    exit(0);
}
