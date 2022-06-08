#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
#define ALL(X) X.begin(), X.end()
using lint = long long;
template <typename T>
void print_container(std::vector<T> vec)
{
    for (auto iter = vec.begin(); iter != vec.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main()
{
    lint n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);

    std::set<lint> hate;

    for (int i = 0; i < k; ++i)
    {
        lint d;
        scanf("%lld", &d);
        hate.insert(d);
    }

    lint pay = n;

    while (1)
    {
        lint cur = pay;
        lint ok = 1;
        while (cur > 0)
        {
            if (hate.find(cur % 10) != hate.end())
            {
                pay++;
                ok = 0;
                break;
            }
            cur /= 10;
        }
        if (ok)
            break;
    }

    std::cout << pay << "\n";

    return 0;
}
