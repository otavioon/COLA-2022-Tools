#include <cstdint>
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>


int kaijo(int n)
{
    int c = 1;

    for ( int _i = 1; _i <= n ; _i++ ) {
        c *= _i;
    }

    return c;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> na(n);
    std::vector<int> nb(n);
    for ( int _n = 0; _n < n; _n++ ) {
        na[_n] = _n+1;
        nb[_n] = _n+1;
    }

    int a = 0;
    int b = 0;
    for ( int _n = 0; _n < n; _n++ ) {
        int p;
        std::cin >> p;
        auto it_a = std::find(na.begin(), na.end(), p);
        auto sz_a = std::distance(na.begin(), it_a);
        a += kaijo((n-_n)-1) * sz_a;
        na.erase(it_a);
    }
    for ( int _n = 0; _n < n; _n++ ) {
        int p;
        std::cin >> p;
        auto it_b = std::find(nb.begin(), nb.end(), p);
        auto sz_b = std::distance(nb.begin(), it_b);
        b += kaijo((n-_n)-1) * sz_b;
        nb.erase(it_b);
    }

    std::cout << std::abs(a-b) << std::endl;

    return 0;
}
