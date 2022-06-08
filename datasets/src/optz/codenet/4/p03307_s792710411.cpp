#include <cstdio>
#include <array>
#include <algorithm>
#include <numeric>

int main()
{
    std::array<int, 200005> d;
    std::array<int, 200005> dm;
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &d[i]);
        dm[i] = d[i] - (i + 1);
    }

    int ave = std::accumulate(dm.begin(), dm.begin() + n, 0) / n;

    int min = 1 << 30;
    int bans;
    int temp_sum = 0, sum = 1 << 30;

    for (int b = ave - 1000000; b < ave + 100000; ++b)
    {
        temp_sum = sum;
        sum = 0;

        for (int i = 0; i < n; ++i)
        {
            sum += std::abs(d[i] - (b + i + 1));
        }
        if (min > sum)
        {
            min = sum;
            bans = b;
        }
    }
    printf("%d\n", min);
    return 0;
}
