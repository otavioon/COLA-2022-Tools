#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int32_t sum;

    for (uint32_t idx = 0; idx < 3; ++idx) {
        uint32_t v1, v2, v3;
        std::cin >> v1 >> v2 >> v3;
        sum += v1 + v2 + v3;
    }

    if (sum % 3 == 0) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;

    return 0;
}