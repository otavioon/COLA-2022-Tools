#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int i, j, c[4][4] = {};

    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            scanf("%d", &c[i][j]);
            j++;
        }
        i++;
    }

    i = 0;
    while (i < 3)
    {
        j = 0;
        while (j < 3)
        {
            if (c[i][j] - c[i][(j + 1) % 3] != c[(i + 1) % 3][j] - c[(i + 1) % 3][(j + 1) % 3])
            {
                printf("No\n");
                return (0);
            }
            j++;
        }
        i++;
    }

    printf("Yes\n");

    return 0;
}